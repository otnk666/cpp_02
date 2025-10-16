/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:25:16 by skomatsu          #+#    #+#             */
/*   Updated: 2025/10/16 21:25:32 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0) 
{
    std::cout << "Constractor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value_(other.value_)
{
    std::cout << "Copy construtor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        value_ = other.value_;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "destracted" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (this->value_);
}

void Fixed::setRawBits(int const raw)
{
    this->value_= raw;
}