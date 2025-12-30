#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _raw(other._raw)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl; if (this!=&other) _raw = other._raw; return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl; _raw = n << _fracBits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl; _raw = (int)roundf(f * (1 << _fracBits));
}

int Fixed::getRawBits(void) const
{
    return _raw;
}

void Fixed::setRawBits(int const raw)
{
    _raw = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_raw / (float)(1 << _fracBits);
}

int Fixed::toInt(void) const
{
    return _raw >> _fracBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
    os << fx.toFloat(); return os;
}
