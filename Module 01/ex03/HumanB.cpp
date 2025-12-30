#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _weapon(0) {}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void HumanB::attack(void) const {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon" << std::endl;
}
