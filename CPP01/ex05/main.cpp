#include "Harl.hpp"

int main(){
	Harl harl;

	//level Test
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	
	std::cout << std::endl;

	//fail Test
	harl.complain("");
	harl.complain("RISHIBAS");
	
	return 0;
}
