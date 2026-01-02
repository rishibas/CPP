#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string.h>

class Weapon{
	private:
		std::string type;
	public:
		Weapon(std::string club);
		~Weapon();
		const std::string	&getType() const;
		void	setType(std::string type);
};

#endif
