#include "PmergeMe.hpp"

int PmergeMe::_comparisons = 0;

// Declarations

static double getTime();
static int jacobsthal(int n);
static int getFJBound(int k);
template <typename Container>
static void printCont(Container &container);

// Constructors

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other):_vector(other._vector),_deque(other._deque){}
PmergeMe::~PmergeMe(){}
PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

// Parsing

void PmergeMe::validate(std::string arg)
{
    if(arg.empty())
        throw std::runtime_error("Empty argument");

    if(arg[0] == '-')
        throw std::invalid_argument("No Negative numbers");

    for(size_t i = 0; i < arg.length(); i++)
    {
        if(!std::isdigit(arg[i]))
            throw std::invalid_argument("Only numbers allowed");
    }

    long num = std::atol(arg.c_str());
    if (num > INT_MAX)
        throw std::invalid_argument("Number larger than INT_MAX");
}

void PmergeMe::parse(int argc, char **argv)
{
    _seq.clear();
    _vector.clear();
    _deque.clear();

    if (argc < 2)
        throw std::invalid_argument("Usage ./PmergeMe [positive integers...]");

    std::set<int> seen;
    for (int i = 1; i < argc; i++)
    {
        validate(argv[i]);

        int n = std::atoi(argv[i]);

        if(!seen.insert(n).second)
            throw std::invalid_argument("Duplicate numbers are not allowed");
        _seq.push_back(n);
        _vector.push_back(n);
        _deque.push_back(n);
    }
}

// Sorting

template <typename Container>
typename Container::iterator PmergeMe::binarySearchContainer(Container &main, int value, typename Container::iterator end)
{
    typename Container::iterator first = main.begin();
    typename Container::iterator it;
    size_t count = end - first;
    size_t step;

    while (count > 0)
    {
        it = first;
        step = count / 2;
        std::advance(it, step);

        ++_comparisons;
        if (*it < value)
        {
            first = ++it;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

std::vector<int> PmergeMe::getInsertionOrder(int n)
{
    std::vector<int> order;
    if (n <= 0)
        return order;

    std::vector<int> jacobSeq;
    jacobSeq.push_back(1);

    int k = 3;
    while (jacobsthal(k) <= n + 1)
    {
        jacobSeq.push_back(jacobsthal(k));
        k++;
    }
    jacobSeq.push_back(n + 1);

    std::vector<bool> inserted(n, false);

    for (size_t i = 1; i < jacobSeq.size(); i++)
    {
        int high = std::min(jacobSeq[i] - 2, n - 1);
        int low = jacobSeq[i - 1] - 1;

        for (int j = high; j >= 0 && j >= low; j--)
        {
            if (!inserted[j])
            {
                order.push_back(j);
                inserted[j] = true;
            }
        }
    }

    return order;
}

template <typename Container>
void PmergeMe::fordJohnson(Container &cont)
{
    if (cont.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = false;
    int odd = 0;

    for (size_t i = 0; i + 1 < cont.size(); i += 2)
    {
        ++_comparisons;
        if (cont[i] > cont[i + 1])
            pairs.push_back(std::make_pair(cont[i], cont[i + 1]));
        else
            pairs.push_back(std::make_pair(cont[i + 1], cont[i]));
    }

    if (cont.size() % 2 == 1)
    {
        hasOdd = true;
        odd = cont.back();
    }

    if (pairs.size() > 1)
    {
        Container largerElements;
        for (size_t i = 0; i < pairs.size(); i++)
            largerElements.push_back(pairs[i].first);

        fordJohnson(largerElements);

        std::vector<std::pair<int, int> > sortedPairs;
        std::vector<bool> used(pairs.size(), false);

        for (size_t i = 0; i < largerElements.size(); i++)
        {
            for (size_t j = 0; j < pairs.size(); j++)
            {
                if (!used[j] && pairs[j].first == largerElements[i])
                {
                    sortedPairs.push_back(pairs[j]);
                    used[j] = true;
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }

    Container main;
    Container pend;

    main.push_back(pairs[0].second);
    main.push_back(pairs[0].first);

    for (size_t i = 1; i < pairs.size(); i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    if (hasOdd)
        pend.push_back(odd);

    if (!pend.empty())
    {
        std::vector<int> insertOrder = getInsertionOrder(pend.size());

        for (size_t i = 0; i < insertOrder.size(); i++)
        {
            int idx = insertOrder[i];
            if (idx < 0 || idx >= static_cast<int>(pend.size()))
                continue;

            int valueToInsert = pend[idx];
            int k = idx + 2;

            int fjBound = getFJBound(k);
            int boundPos = std::min(fjBound, static_cast<int>(main.size()));

            typename Container::iterator bound = main.begin() + boundPos;

            typename Container::iterator pos = binarySearchContainer(main, valueToInsert, bound);

            main.insert(pos, valueToInsert);
        }
    }

    cont = main;
}

void PmergeMe::sort()
{
    double start, end;

    _comparisons = 0;
    start = getTime();
    fordJohnson(_vector);
    end = getTime();
    _vecTime = end - start;
    _vecComp = _comparisons;

    _comparisons = 0;
    start = getTime();
    fordJohnson(_deque);
    end = getTime();
    _deqTime = end - start;
    _deqComp = _comparisons;
}

// Display

void PmergeMe::display()
{
    std::cout << "Before: ";
    printCont(_seq);

    std::cout << "After: ";
    printCont(_vector);
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _seq.size()
              << " elements with std::vector : " << _vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _seq.size()
              << " elements with std::deque : " << _deqTime << " us" << std::endl;

    // Counter display (Uncomment)
    //std::cout << std::endl;
    //std::cout << "Total comparisons: " << _comparisons << std::endl;
    //std::cout << "Vector comparisons: " << _vecComp << std::endl;
    //std::cout << "Deque comparisons: " << _deqComp << std::endl;
}

// Helpers

static double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return(tv.tv_sec * 1000000 + tv.tv_usec);
}

static int jacobsthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int jNm2 = 0;
    int jNm1 = 1;
    int jN = 0;

    for (int i = 2; i <= n; i++)
    {
        jN = jNm1 + 2 * jNm2;
        jNm2 = jNm1;
        jNm1 = jN;
    }

    return jN;
}

static int getFJBound(int k)
{
    if (k <= 1) return 0;

    int t = 1;
    int prev = 1;
    int curr = 1;

    while (curr < k)
    {
        int next = curr + 2 * prev;
        prev = curr;
        curr = next;
        t++;
    }

    return (1 << t) - 1;
}

template <typename Container>
static void printCont(Container &container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
