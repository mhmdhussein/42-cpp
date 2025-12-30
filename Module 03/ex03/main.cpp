#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d1("Diamond");

    std::cout << "-----" << std::endl;

    d1.attack("enemy target");
    d1.highFivesGuys();
    d1.guardGate();
    d1.whoAmI();

    std::cout << "-----" << std::endl;

    DiamondTrap d2(d1);
    d2.whoAmI();
    d2.attack("second enemy");

    std::cout << "-----" << std::endl;

    DiamondTrap d3;
    d3 = d1;
    d3.whoAmI();

    std::cout << "-----" << std::endl;

    return 0;
}
