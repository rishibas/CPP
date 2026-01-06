#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()){
	std::cout << "Dog: Default Constructor called." << std::endl;
}

Dog::~Dog(){
	delete brain;
	std::cout << "Dog: Destructor called." << std::endl;	
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog: Copy Constructor called." << std::endl;
}

Dog&	Dog::operator=(const Dog &other){
	std::cout << "Dog: Copy Assignment operator called." << std::endl;
	if (this != &other)
	{
		this->brain = new Brain(*other.brain);
		*(this->brain) = *(other.brain);
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << type << ": wan wan wan" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->brain;
}
