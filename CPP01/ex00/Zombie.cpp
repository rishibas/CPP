#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string n){
	name = n;
}

Zombie::~Zombie() {}

void Zombie::announce(void) {
	randomChump(name);
}

Zombie *newZombie(std::string name) {
	return new Zombie(name);
}

void randomChump(std::string name) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
