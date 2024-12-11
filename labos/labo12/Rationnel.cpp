#include <numeric> // For std::gcd
#include <iostream>
#include <stdexcept> // For std::runtime_error
#include "Rationnel.hpp"
#include <ostream>

Rationnel simplifier(Rationnel r){
    // Check for negative denominator and adjust signs accordingly
    if (r.den < 0)
    {
        r.num = -r.num;
        r.den = -r.den;
    }

    // Check for division by 0 and handle the error
    if (r.den == 0)
    {
        throw std::runtime_error("Denominator cannot be zero");
    }

    // Simplify the rational number by dividing both numerator and denominator by their greatest common divisor
    int div = std::gcd(r.num, r.den);
    r.num /= div;
    r.den /= div;

    // Return the simplified rational number
    return r;
}

void afficher(const Rationnel &r){
    std::cout << r.num << '/' << r.den << std::endl;
}

Rationnel operator-(const Rationnel &r){
    return simplifier({-r.num, r.den});
}

Rationnel &operator+=(Rationnel &gauche, const Rationnel &droit){
    gauche.num = gauche.num * droit.den + droit.num * gauche.den;
    gauche.den *= droit.den;
    return gauche = simplifier(gauche);
}

Rationnel operator+(Rationnel gauche, const Rationnel &droit){
    return simplifier(gauche += droit);
}

Rationnel &operator-=(Rationnel &gauche, const Rationnel &droit){
    return gauche += -droit;
}

Rationnel operator-(Rationnel gauche, const Rationnel &droit){
    return simplifier(gauche -= droit);
}

Rationnel operator/(const Rationnel &gauche, const Rationnel &droit){
    if (droit.num == 0)
    {
        throw std::runtime_error("Division by zero is not allowed");
    }
    return simplifier({gauche.num * droit.den, gauche.den * droit.num});
}

Rationnel &operator/=(Rationnel &gauche, const Rationnel &droit){
    gauche = gauche / droit;
    return gauche;
}

Rationnel operator*(const Rationnel &gauche, const Rationnel &droit){
    return simplifier({gauche.num * droit.num, gauche.den * droit.den});
}

bool operator==(const Rationnel &r1, const Rationnel &r2){
    Rationnel sr1 = simplifier(r1);
    Rationnel sr2 = simplifier(r2);
    return sr1.num == sr2.num && sr1.den == sr2.den;
}

bool operator!=(const Rationnel &r1, const Rationnel &r2){
    return !(r1 == r2);
}

bool operator<(const Rationnel &r1, const Rationnel &r2){
    return r1.num * r2.den < r2.num * r1.den;
}

bool operator<=(const Rationnel &r1, const Rationnel &r2){
    return (r1 < r2) || (r1 == r2);
}

bool operator>(const Rationnel &r1, const Rationnel &r2){
    return !(r1 <= r2);
}

bool operator>=(const Rationnel &r1, const Rationnel &r2){
    return !(r1 < r2);
}

std::ostream &operator<<(std::ostream &os, const Rationnel &r){
    os << r.num << '/' << r.den;
    return os;
}
