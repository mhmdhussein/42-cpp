#include "Zombie.hpp"
#include <iostream>

int main() {
    randomChump("Zambie");
    Zombie* z = newZombie("Zizo");
    z->announce();
    delete z;

    Zombie local("Zaz");
    local.announce();
    return 0;
}
