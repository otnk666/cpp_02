/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:25:16 by skomatsu          #+#    #+#             */
/*   Updated: 2026/01/05 22:39:10 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) 
{
    std::cout << "Constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _value = other._value;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const
{
    return _value > rhs._value;
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return _value < rhs._value;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return _value >= rhs._value;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return _value <= rhs._value;
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return _value == rhs._value;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return _value != rhs._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed result;
    result.setRawBits(_value + rhs._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed result;
    result.setRawBits(_value - rhs._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;
    float temp = this->toFloat() * rhs.toFloat();
    result = Fixed(temp);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    if (rhs._value == 0)
    {
        std::cout << "Error: Division by zero" << std::endl;
        return Fixed();
    }

    Fixed result;
    float temp = this->toFloat() / rhs.toFloat();
    result = Fixed(temp);
    return result;
}

// Increment & Decrement
Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    ++(*this);
    return old;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    --(*this);
    return old;
}

// Static member functions (min / max)
Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    return (lhs < rhs) ? lhs : rhs;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
    return (lhs < rhs) ? lhs : rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    return (lhs > rhs) ? lhs : rhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
    return (lhs > rhs) ? lhs : rhs;
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
    this->_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
    os << rhs.toFloat();
    return os;
}

