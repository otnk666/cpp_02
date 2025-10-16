#pragma once

#include <iostream>
#include <string.h>

class Fixed
{
    private:
        int     bits;


    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getBits(void) const;
        void    setBits(int const bits);

};