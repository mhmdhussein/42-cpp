#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe sort;

    try
    {
        sort.parse(argc, argv);
        sort.sort();
        sort.display();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
