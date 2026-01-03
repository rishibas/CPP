#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string.h>

class Harl{
	private:
		//void (Harl::*)(void)をHandlerPtr型として名付ける。
		typedef void (Harl::*HandlerPtr)();
		HandlerPtr levelHandlers[4];
		void	debug();
		void	info();
		void	warning();
		void	error();
	
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif
