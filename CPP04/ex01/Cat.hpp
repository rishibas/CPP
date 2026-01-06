#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class Cat : public Animal{
	private:
		Brain *brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		Brain *getBrain() const;
		void	makeSound() const ;
};

#endif
