#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()){
	std::cout << "Cat: Default Constructor called." << std::endl;
}

Cat::~Cat(){
	delete brain;
	std::cout << "Cat: Destructor called." << std::endl;	
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat: Copy Constructor called." << std::endl;
}

Cat&	Cat::operator=(const Cat &other){
	std::cout << "Cat: Copy Assignment operator called." << std::endl;
	if (this != &other)
	{
		this->brain = new Brain(*other.brain);
		*(this->brain) = *(other.brain);
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << type << ": wan wan wan" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}
