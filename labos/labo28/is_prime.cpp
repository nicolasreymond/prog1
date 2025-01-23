/**
 * @file    is_prime.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Check if a number is prime
 * @version 1.0
 * @date    06-01-2025
 */

#include "is_prime.hpp"
#include "modular_math.hpp"
#include <cstdlib>
#include <cmath>



bool isPrime(const Unsigned &p) {
    if (p < 2) return false;
    if (p == 2) return true;

    for (int i = 0; i < 10; ++i) {
        Unsigned a = Unsigned::random(p.to_uint64() - 1) + 1;
        Unsigned result = modExp(a, p - 1, p);

        if (result != 1) return false;

        Unsigned q = 1;
        Unsigned u = p - 1;
        while (u % 2 == 0 && q == 1) {
            u /= 2;
            q = modExp(a, u, p);
        }
        if (q != 1 && q != p - 1) return false;
    }
    return true;
}
