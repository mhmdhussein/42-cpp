#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("FragTrap_default")
{
    hitPoints    = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called for "
              << name << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    hitPoints    = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap name constructor called for "
              << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for "
              << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for "
              << name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "FragTrap " << name
                  << " cannot attack because it has no hit points left" << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "FragTrap " << name
                  << " cannot attack because it has no energy points left" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name
              << " blasts " << target
              << ", causing " << attackDamage
              << " points of damage" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name
              << " requests a positive high five" << std::endl;
}
