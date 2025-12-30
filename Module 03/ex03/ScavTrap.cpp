#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("ScavTrap_default")
{
    hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called for "
              << name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap name constructor called for "
              << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for "
              << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for "
              << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name
                  << " cannot attack because it has no hit points left" << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name
                  << " cannot attack because it has no energy points left" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name
              << " strikes " << target
              << ", causing " << attackDamage
              << " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name
              << " is now in Gate keeper mode" << std::endl;
}
