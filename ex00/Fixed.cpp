
#include "Fixed.hpp"

Fixed::Fixed() : bits(0) 
{
    std::cout << "created constractor" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "copy constractor" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{

}

Fixed::~Fixed()
{
    std::cout << "deconstracted" << std::endl;
}