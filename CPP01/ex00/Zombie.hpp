#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string.h>

class Zombie{
	private:
		std::string	name;


	public:
		Zombie();
		Zombie (std::string n);
		~Zombie();
		void	announce(void);

};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif
