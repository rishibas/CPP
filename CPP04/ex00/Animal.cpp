#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Animal: Default Constructor called." << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal: Destructor called." << std::endl;
}

Animal::Animal(std::string type) : type(type) {}

Animal::Animal(const Animal &other){
	std::cout << "Animal: Copy Constructor called." << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal &other){
	std::cout << "Animal: Copy Assignment operator called." << std::endl;
	if (this != &other)
		 this->type = other.type;
	return *this;
}

std::string	Animal::getType(){
	return type;
}