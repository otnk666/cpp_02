#include "Fixed.hpp"

int main (void)
{
    Fixed a;
    
    std::cout << a.getRawBits() << std::endl;
    a.setRawBits(42);
    std::cout << a.getRawBits() << std::endl;
    return (0);
}
