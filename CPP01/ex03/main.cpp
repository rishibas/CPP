#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(){
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA bob("BoB", club);
		bob.attack();
		club.setType("iron club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(&club);
		jim.attack();
		club.setType("iron club");
		jim.attack();
	}
	return 0;
}
