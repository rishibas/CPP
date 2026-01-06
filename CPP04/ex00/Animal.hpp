#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include<iostream>
# include<string>

class Animal{
	protected:
		std::string type;

	public:
	Animal();
	~Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	Animal&	operator=(const Animal &other);

	std::string	getType();
	void		makeSound();
};

#endif