#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("rishibas");
	zombie->announce();
	delete zombie;

	return (0);
}
