/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:25:16 by skomatsu          #+#    #+#             */
/*   Updated: 2026/01/05 22:15:49 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) 
{
    std::cout << "Constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    _value = value << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    _value = static_cast<int>(roundf(value * ( 1 << _fractionalBits)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy construtor called" << std::endl;
    this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        _value = other._value;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destractor called" << std::endl;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _value >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value= raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
    os << rhs.toFloat();
    return os;
}
