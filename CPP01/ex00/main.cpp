#include "Zombie.hpp"

int main(void)
{
	try{
		Zombie *zombie = newZombie("rishibas1");
		zombie->announce();
		delete zombie;
		randomChump("rishibas2");
	}
	catch (std::bad_alloc& e){
		// メモリ確保に失敗
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
