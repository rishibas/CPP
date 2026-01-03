#include "Zombie.hpp"

int main(void)
{
	int N = 10;

	try{
		Zombie *zombie = zombieHorde(N, "rishibas");
		if (!zombie){
			std::cerr << "return NULLptr" << std::endl;
			return 1;
		}
		for (int i = 0; i < N; i++)
			zombie[i].announce();
		delete []zombie;
	}
	catch (std::bad_alloc& e){
		// メモリ確保に失敗
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
