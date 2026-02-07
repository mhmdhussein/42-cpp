#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <set>
#include <sys/time.h>
#include <exception>
#include <utility>
#include <cctype>

class PmergeMe
{
    private:
        std::vector <int> _seq;
        std::vector <int> _vector;
        std::deque <int> _deque;
        double _vecTime;
        double _deqTime;
        int _vecComp;
        int _deqComp;
        static int _comparisons;

        void validate(std::string arg);

        std::vector<int> getInsertionOrder(int n);

        template <typename Container>
        typename Container::iterator binarySearchContainer(Container &main, int value, typename Container::iterator end);

        template <typename Container>
        void fordJohnson(Container &cont);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);

        void parse(int argc, char **argv);
        void sort();
        void display();
};
#endif