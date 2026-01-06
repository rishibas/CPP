#include "Animal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal: Default Constructor called." << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal: Destructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type){
	std::cout << "AAnimal: Constructor with type called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other){
	std::cout << "AAnimal: Copy Constructor called." << std::endl;
	*this = other;
}

AAnimal&	AAnimal::operator=(const AAnimal &other){
	std::cout << "AAnimal: Copy Assignment operator called." << std::endl;
	if (this != &other)
		 this->type = other.type;
	return *this;
}

std::string	AAnimal::getType() const {
	return type;
}

void	AAnimal::makeSound() const {
	std::cout << type << ": AAnimal bark" << std::endl;
}
