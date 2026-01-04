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
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		//thisポインタが自動的に渡されるため、引数が1つでもtoo few argument errorが発生しない
		bool			operator>(const Fixed &other) const;
		bool			operator<(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;
		Fixed			operator+(const Fixed &other) const;
		Fixed			operator-(const Fixed &other) const;
		Fixed			operator*(const Fixed &other) const;
		Fixed			operator/(const Fixed &other) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);






#endif
