#include <numeric> // Pour std::gcd
#include <iostream>
#include "Rationnel.hpp"
#include <ostream>

Rationnel simplifier(Rationnel r) {
    // check for negative denominator
    if (r.den < 0)
    {
        r.num = -r.num;
        r.den = -r.den;
    }

    //check for division by 0
    if (r.den == 0)
    {
        std::cerr << "Division by 0" << std::endl;
        return r;
    }
    // Simplifier le rationnel
    int div = std::gcd(r.num, r.den);
    r.num /= div;
    r.den /= div;
    return r;
}

Rationnel operator-(const Rationnel & r) {
    return simplifier({-r.num, r.den});
}

Rationnel & operator+=(Rationnel & gauche, const Rationnel & droit) {
    gauche.num = gauche.num * droit.den + droit.num * gauche.den;
    gauche.den *= droit.den;
    return gauche = simplifier(gauche);
}

Rationnel operator+(Rationnel gauche, const Rationnel & droit) {
    return simplifier(gauche += droit);
}

Rationnel & operator-=(Rationnel & gauche, const Rationnel & droit) {
    return gauche += -droit;
}

Rationnel operator-(Rationnel gauche, const Rationnel & droit) {
    return simplifier(gauche -= droit);
}

Rationnel operator/(const Rationnel & gauche, int facteur) {
    return simplifier({gauche.num, gauche.den * facteur});
}

Rationnel operator*(const Rationnel & gauche, const Rationnel & droit) {
    return simplifier({gauche.num * droit.num, gauche.den * droit.den});
}

std::ostream &operator<<(std::ostream &os, const Rationnel &r)
{
    os << r.num << '/' << r.den;
    return os;
}
