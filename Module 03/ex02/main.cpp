#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap scav("GateKeeper");
    FragTrap frag("HighFiver");

    std::cout << "-----" << std::endl;

    scav.guardGate();
    scav.attack("dummy");
    scav.takeDamage(30);
    scav.beRepaired(20);

    std::cout << "-----" << std::endl;

    frag.highFivesGuys();
    frag.attack("target");
    frag.takeDamage(60);
    frag.beRepaired(40);

    std::cout << "-----" << std::endl;

    FragTrap copyFrag(frag);
    copyFrag.highFivesGuys();

    std::cout << "-----" << std::endl;

    return 0;
}
