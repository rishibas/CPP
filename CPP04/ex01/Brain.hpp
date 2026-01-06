#ifndef BRAIN_H
# define BRAIN_H

# include<iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		virtual ~Brain();

		void setIdeas(int num, const std::string& idea);
		std::string getIdeas(int num) const;
};

#endif
