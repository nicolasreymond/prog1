/**
 * @file    reymond_labo28.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Modular math functions for RSA
 * @version 1.0
 * @date    06-01-2025
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "modular_math.hpp"
#include "Unsigned.hpp"

Unsigned modExp(const Unsigned &base, const Unsigned &exp, const Unsigned &mod) {
    Unsigned result(1);
    Unsigned baseMod = base % mod;
    Unsigned expCopy = exp;

    while (expCopy > Unsigned(0)) {
        if (expCopy % Unsigned(2) == Unsigned(1)) {
            result = (result * baseMod) % mod;
        }
        baseMod = (baseMod * baseMod) % mod;
        expCopy /= Unsigned(2);
    }
    return result;
}

Unsigned gcdExtended(const Unsigned &a, const Unsigned &b, Unsigned &x, Unsigned &y) {
    if (a == Unsigned(0)) {
        x = Unsigned(0);
        y = Unsigned(1);
        return b;
    }
    Unsigned x1, y1;
    Unsigned gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
