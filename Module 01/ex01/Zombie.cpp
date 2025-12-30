#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(): _name("noname") {}
Zombie::~Zombie() {
    std::cout << this->_name << " is destroyed" << std::endl;
}
void Zombie::setName(const std::string &name) { this->_name = name; }
void Zombie::announce(void) const {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
