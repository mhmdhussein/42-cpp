#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    std::cout << "-----" << std::endl;

    a.attack("a target dummy");
    a.takeDamage(5);
    a.beRepaired(3);
    a.takeDamage(10);
    a.attack("another dummy");
    a.beRepaired(5);

    std::cout << "-----" << std::endl;

    b.attack("random dummy");
    b.takeDamage(2);
    b.beRepaired(2);

    std::cout << "-----" << std::endl;

    ClapTrap c(a);
    c.attack("copy target");

    std::cout << "-----" << std::endl;

    ClapTrap d;
    d = b;
    d.attack("assigned target");

    std::cout << "-----" << std::endl;

    return 0;
}
