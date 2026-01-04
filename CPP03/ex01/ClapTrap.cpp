#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("clap"), HitPoints(10), EnergyPoints(10), AttackDamage(0){
	std::cout << "CrapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0){
	std::cout << "ClapTrap [" << this->name << "] created." << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int HitPoints, unsigned int EnergyPoints, unsigned int AttackDamage) : name(name), HitPoints(HitPoints), EnergyPoints(EnergyPoints), AttackDamage(AttackDamage){
	std::cout << "ClapTrap: detailed constructor called for " <<  std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other){
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	if (this != &other){
		name = other.name;
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << name << "は" << amount << "ポイントのダメージを受けた！" << std::endl;
	if (HitPoints <= amount){
		HitPoints = 0;
		std::cout << "ClapTrap " << name << "のヒットポイントは0になった。" << std::endl;
		return ;
	}
	HitPoints -= amount;
}

void	ClapTrap::attack(const std::string& target){
	if (this->HitPoints <= 0){
		HitPoints = 0;
		std::cout << "ClapTrap " << this->name << "は行動不能。" << std::endl;
		return ;
	}
	if (this->EnergyPoints <= 0){
		this->EnergyPoints = 0;
		std::cout << "ClapTrap " << this->name << "は攻撃することができない!" << std::endl;
		return ;	
	}
	std::cout << "ClapTrap " << this->name << "が" << target << "を攻撃し、" << this->AttackDamage << "ポイントのダメージを与えた！ (エネルギーポイント-1)" << std::endl;
	this->EnergyPoints--;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (HitPoints <= 0){
		HitPoints = 0;
		std::cout << "ClapTrap " << this->name << "は行動不能。" << std::endl;
		return ;
	}
	if (EnergyPoints <= 0){
		EnergyPoints = 0;
	std::cout << "ClapTrap " << this->name << "は回復魔法を使うことができない！" << std::endl;
		return ;
	}
	if (HitPoints == MAX_HP){
		std::cout << "ClapTrap " << this->name << "は回復魔法を使うことができない！" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << "は回復魔法を使用した。 (ヒットポイント+" << amount << ", エネルギーポイント-1)" << std::endl;
	HitPoints += amount;
	if (HitPoints > MAX_HP)
		HitPoints = MAX_HP;
	this->EnergyPoints--;
}

void	ClapTrap::Info() const {
    std::cout << std::endl;
	std::cout << "名前: " << name << std::endl;
	std::cout << "ヒットポイント: " << HitPoints << std::endl;
	std::cout << "エネルギーポイント" << EnergyPoints << std::endl;
	std::cout << "アタックダメージ: " << AttackDamage << std::endl;
}

std::string ClapTrap::getName() const {return name;}

unsigned int ClapTrap::getHitPoints() const {return HitPoints;}

unsigned int ClapTrap::getEnergyPoints() const {return EnergyPoints;}

unsigned int ClapTrap::getAttackDamage() const {return AttackDamage;}
