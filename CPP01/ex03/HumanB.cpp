#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL){}

HumanB::~HumanB(){}

// ポインタで受け取ることでclubのアドレスをweaponに格納することが出来る。
void	HumanB::setWeapon(Weapon *club){
	this->weapon = club;
}

void	HumanB::attack(){
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
