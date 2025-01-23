#ifndef MODULAR_MATH_HPP
#define MODULAR_MATH_HPP

#include "Unsigned.hpp"

Unsigned modExp(const Unsigned &base, const Unsigned &exp, const Unsigned &mod);
Unsigned gcdExtended(const Unsigned &a, const Unsigned &b, Unsigned &x, Unsigned &y);

#endif // MODULAR_MATH_HPP
