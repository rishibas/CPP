#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

//weaponがreferenceでないと、HumanAのコンストラクタでweaponと受取元のアドレスが異なってしまう。

class HumanA{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();

};

#endif
