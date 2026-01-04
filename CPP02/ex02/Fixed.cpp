#include "Fixed.hpp"

Fixed::Fixed() : FixedPointNum(0) {}

Fixed::Fixed(const int num) {
	FixedPointNum = num << FractionalBits;
}

Fixed::Fixed(const float num){
	FixedPointNum = (int)((num * 256) + 0.5);
}

Fixed::Fixed(const Fixed &other){
	*this = other;
}

int	Fixed::getRawBits(void) const{
	return this->FixedPointNum;
}

void	Fixed::setRawBits(int const raw){
	FixedPointNum = raw;
}

Fixed& Fixed::operator=(const Fixed &other){
	if (this != &other){
		this->FixedPointNum = other.FixedPointNum;
	}
	return (*this);
}

Fixed::~Fixed(){}

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

	int num = this->FixedPointNum * other.getRawBits();
	res.setRawBits((int)(num / 256));
	return res;
}

Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed res;

	int num = this->FixedPointNum * 256;
	int resRaw = num / other.getRawBits(); 
	res.setRawBits((int)resRaw);
	return res;
}

Fixed	&Fixed::operator++(void){
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	&Fixed::operator--(void){
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed pre(*this); //Copy constructor
	this->operator++();
	return pre;
}

Fixed	Fixed::operator--(int){
	Fixed pre(*this); //Copy Constructor
	this->operator--();
	return pre;
}

Fixed&	Fixed::min(Fixed &a, Fixed &b){
	if (a > b)
		return b;
	return a;
}

const	Fixed&	Fixed::min(const Fixed &a, const Fixed &b){
	if (a > b)
		return b;
	return a;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return a;
	return b;
}

const	Fixed&	Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return a;
	return b;
}
