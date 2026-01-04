#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("scav", 100, 50, 20){
	std::cout << "ScavTrap: Default constructor called" << std::endl;	
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
	std::cout << "ScavTrap: Copy Constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other){
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	if (this != &other){
		//親クラス部分をコピー
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20){
	std::cout << "ScavTrap: name constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

void	ScavTrap::guardGate(){
	if (HitPoints <= 0){
		std::cout << "ScavTrap " << name << "は行動不能。" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << "is now in Gate" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if (HitPoints <= 0){
		HitPoints = 0;
		std::cout << "ClapTrap " << name << "は行動不能。" << std::endl;
		return ;
	}
	if (EnergyPoints <= 0){
		EnergyPoints = 0;
		std::cout << "ClapTrap " << name << "は攻撃することができない!" << std::endl;
		return ;	
	}
	std::cout << "ClapTrap " << name << "が" << target << "を攻撃し、" << AttackDamage << "ポイントのダメージを与えた！ (エネルギーポイント-1)" << std::endl;
	EnergyPoints--;
}
