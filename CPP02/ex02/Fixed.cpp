#include "Fixed.hpp"

Fixed::Fixed() : FixedPointNum(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	FixedPointNum = num << FractionalBits;
} 

Fixed::Fixed(const float num){
	std::cout << "Float constructor called" << std::endl;
	FixedPointNum = (int)((num * 256) + 0.5);
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->FixedPointNum;
}

void	Fixed::setRawBits(int const raw){
	FixedPointNum = raw;
}

Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		this->FixedPointNum = other.FixedPointNum;
	}
	return (*this);
}

Fixed::~Fixed(){
std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt(void) const{
	return FixedPointNum >> FractionalBits;
}

float Fixed::toFloat(void) const{
	return ((float)FixedPointNum / 256);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return out;
}

bool	Fixed::operator>(const Fixed &other) const {
	return this->FixedPointNum > other.getRawBits();	
}

bool	Fixed::operator<(const Fixed &other) const {
	return this->FixedPointNum < other.getRawBits();
}

bool	Fixed::operator<=(const Fixed &other) const {
	return this->FixedPointNum <= other.getRawBits();
}

bool	Fixed::operator>=(const Fixed &other) const {
	return this->FixedPointNum >= other.getRawBits();
}

bool	Fixed::operator==(const Fixed &other) const {
	return this->FixedPointNum == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed &other) const {
	return this->FixedPointNum != other.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &other) const {
	Fixed res;

	res.setRawBits(this->FixedPointNum + other.getRawBits());
	return res;
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed res;

	res.setRawBits(this->FixedPointNum - other.getRawBits());
	return res;	
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed res;

	long long num = (long long)this->FixedPointNum * (long long)other.getRawBits();
	res.setRawBits((int)(num / 256));
	return res;
}

Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed res;

	long long num = ((long long)this->FixedPointNum * 256);
	long long resRaw = num / other.getRawBits(); 
	res.setRawBits((int)resRaw);
	return res;
}