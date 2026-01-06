/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:25:43 by skomatsu          #+#    #+#             */
/*   Updated: 2026/01/05 22:23:47 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int     _value;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    Fixed& operator++();    // Pre-increment (++i)
    Fixed operator++(int);  // Post-increment (i++)
    Fixed& operator--();    // Pre-decrement (--i)
    Fixed operator--(int);  // Post-decrement (i--)

    // Static member functions (min / max)
    // lhs = Left Hand Side, rhs = Right Hand Side
    static Fixed& min(Fixed& lhs, Fixed& rhs);
    static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
    static Fixed& max(Fixed& lhs, Fixed& rhs);
    static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

    // Conversion functions
    float toFloat() const;
    int toInt() const;

    int     getRawBits(void) const;
    void    setRawBits(int const raw);        
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif
