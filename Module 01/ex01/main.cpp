#include "Zombie.hpp"
#include <iostream>

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zambie");
    if (!horde) return 0;

    for (int i = 0; i < N; ++i) horde[i].announce();
    delete [] horde;
    return 0;
}
