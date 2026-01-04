#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap{
	protected: //継承先クラスにアクセス権限を与える。
		static const int MAX_HP = 100;
		static const int MAX_EP = 100;
		std::string		name;
		unsigned int	HitPoints;
		unsigned int	EnergyPoints;
		unsigned int	AttackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int HitPoints, unsigned int EnergyPoints, unsigned int AttackDamage);
		ClapTrap(const ClapTrap &other);
		ClapTrap&	operator=(const ClapTrap &other);
		virtual ~ClapTrap();

		//Task Requirements
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		//Additional Implement
		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
		void		Info() const;
};

#endif
