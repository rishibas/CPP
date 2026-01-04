#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("frag", 100, 100, 30){
	std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30){
	std::cout << "FragTrap: name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other){
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap: Destrctor called" << std::endl;
}

void	FragTrap::highFivesGuys(){
	if (HitPoints <= 0){
		std::cout << "FlapTrap " << name << "は行動不能。" << std::endl;
		return ;
	}
	std::cout << "Let's high-five !!!!!!!!!!!!" << std::endl;	
}

void	FragTrap::attack(const std::string& target){
	if (HitPoints <= 0){
		HitPoints = 0;
		std::cout << "FlapTrap " << name << "は行動不能。" << std::endl;
		return ;
	}
	if (EnergyPoints <= 0){
		EnergyPoints = 0;
		std::cout << "FlapTrap " << name << "は攻撃することができない!" << std::endl;
		return ;	
	}
	std::cout << "FlapTrap " << name << "が" << target << "を攻撃し、" << AttackDamage << "ポイントのダメージを与えた！ (エネルギーポイント-1)" << std::endl;
	EnergyPoints--;
}
