#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap{
	private:
		static const int MAX_HP = 10;
		static const int MAX_EP = 10;
		std::string		name;
		unsigned int	HitPoints;
		unsigned int	EnergyPoints;
		unsigned int	AttackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap&	operator=(const ClapTrap &other);
		~ClapTrap();

		//Task Requirements
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		//Additional Implement
		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
};

#endif
