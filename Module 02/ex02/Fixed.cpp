#include "Fixed.hpp"
#include <cmath>
#include <stdexcept>

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _raw(other._raw) {}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this!=&other) _raw = other._raw; return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int n)
{
    _raw = n << _fracBits;
}

Fixed::Fixed(const float f)
{
    _raw = (int)roundf(f * (1 << _fracBits));
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

bool Fixed::operator>(const Fixed& rhs) const
{
    return _raw > rhs._raw;
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return _raw < rhs._raw;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return _raw >= rhs._raw;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return _raw <= rhs._raw;
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return _raw == rhs._raw;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return _raw != rhs._raw;
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed r;
    r.setRawBits(_raw + rhs._raw);
    return r;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed r;
    r.setRawBits(_raw - rhs._raw); 
    return r;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed r;
    long tmp = (long)_raw * (long)rhs._raw; r.setRawBits((int)(tmp >> _fracBits));
    return r;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{ Fixed r;
    if (rhs._raw == 0) throw std::runtime_error("Division by zero");
    long tmp = ((long)_raw << _fracBits) / rhs._raw; r.setRawBits((int)tmp);
    return r;
}

Fixed& Fixed::operator++()
{
    ++_raw;
    return *this;
}

Fixed  Fixed::operator++(int)
{
    Fixed t(*this);
    ++_raw; return t;
}

Fixed& Fixed::operator--()
{
    --_raw;
    return *this;
}

Fixed  Fixed::operator--(int)
{
    Fixed t(*this);
    --_raw; return t;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
    os << fx.toFloat();
    return os;
}
