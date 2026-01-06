#ifndef DOG_HPP
# define DOG_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class Dog : public Animal{
	private:
		Brain *brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		Brain *getBrain() const;
		void	makeSound() const ;
};

#endif
