#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called for "
              << name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap name constructor called for "
              << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor called for "
              << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        name         = other.name;
        hitPoints    = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for "
              << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name
                  << " cannot attack because it has no hit points left" << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name
                  << " cannot attack because it has no energy points left" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name
              << " attacks " << target
              << ", causing " << attackDamage
              << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name
                  << " is already out of hit points" << std::endl;
        return;
    }

    int damage = static_cast<int>(amount);
    hitPoints -= damage;
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name
              << " takes " << damage
              << " points of damage, remaining HP = "
              << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name
                  << " cannot be repaired because it has no hit points left" << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name
                  << " cannot be repaired because it has no energy points left" << std::endl;
        return;
    }

    energyPoints--;
    int heal = static_cast<int>(amount);
    hitPoints += heal;

    std::cout << "ClapTrap " << name
              << " repairs itself for " << heal
              << " hit points, total HP = " << hitPoints
              << std::endl;
}
