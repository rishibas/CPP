#include"Brain.hpp"

Brain::Brain(){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "rishibas";
	std::cout << "Brain: default constrctor called." << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain: destrctor called." << std::endl;
}

Brain::Brain(const Brain &other){
	std::cout << "Brain: copy constructor called." << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain &other){
	std::cout << "Brain: copy assignment operator called." << std::endl;
	if (this != &other){ 
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string Brain::getIdeas(int num) const {
	if (num >= 0 && num < 100)
		return this->ideas[num];
	return "";
}

void	Brain::setIdeas(int num, const std::string& idea){
	if (num >= 0 && num < 100)
		this->ideas[num] = idea;
}
