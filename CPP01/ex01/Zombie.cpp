#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string n){
	name = n;
}

Zombie::~Zombie() {
	std::cout << name << ": deleted" << std::endl;
}

void Zombie::announce(void) {
	randomChump(name);
}

void randomChump(std::string name) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
