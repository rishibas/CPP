#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal: Default Constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal: Destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	std::cout << "WrongAnimal: Copy Constructor called." << std::endl;
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other){
	std::cout << "WrongAnimal: Copy Assignment operator called." << std::endl;
	if (this != &other)
		 this->type = other.type;
	return *this;
}

std::string	WrongAnimal::getType() const {
	return type;
}

void	WrongAnimal::makeSound() const {
	std::cout << type << ": WrongAnimal bark" << std::endl;
}
