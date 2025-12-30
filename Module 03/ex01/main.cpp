#include "ScavTrap.hpp"

int main()
{
    ClapTrap basic("Basic");
    basic.attack("training dummy");
    basic.takeDamage(5);
    basic.beRepaired(2);

    std::cout << "-----" << std::endl;

    ScavTrap guard("Serena");
    guard.attack("a dangerous enemy");
    guard.takeDamage(20);
    guard.beRepaired(10);
    guard.guardGate();

    std::cout << "-----" << std::endl;

    ScavTrap copy(guard);
    copy.guardGate();
    copy.attack("another enemy");

    std::cout << "-----" << std::endl;

    ScavTrap assigned;
    assigned = guard;
    assigned.attack("third enemy");

    std::cout << "-----" << std::endl;

    return 0;
}
