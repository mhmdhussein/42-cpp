#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("DiamondTrap_default_clap_name"),
      ScavTrap("DiamondTrap_default"),
      FragTrap("DiamondTrap_default"),
      name("DiamondTrap_default")
{
    hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 30;

    std::cout << "DiamondTrap default constructor called for "
              << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      name(name)
{
    hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 30;

    std::cout << "DiamondTrap name constructor called for "
              << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "DiamondTrap copy constructor called for "
              << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for "
              << name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name
              << " | ClapTrap name: " << ClapTrap::name
              << std::endl;
}
