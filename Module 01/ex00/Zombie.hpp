#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string _name;
public:
    Zombie();
    explicit Zombie(const std::string &name);
    ~Zombie();

    void setName(const std::string &name);
    void announce(void) const;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
