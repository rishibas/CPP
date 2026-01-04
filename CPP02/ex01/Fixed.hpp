#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	private:
		int 				FixedPointNum;
		static const int	FractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &other);
		Fixed&	operator=(const Fixed &other);
		~Fixed();
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
