#include "Zombie.hpp"

int main(void)
{
	int N = 100;

	try{
		Zombie *zombie = zombieHorde(N, "rishibas");
		for (int i = 0; i < N; i++)
			zombie->announce();
		delete []zombie;
	}
	catch (std::bad_alloc& e){
		// メモリ確保に失敗
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
