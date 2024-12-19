/**
 * @file    reymond_labo27.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Rational class header file
 * @version 1.0
 * @date    20-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <stdexcept>
#include <numeric> // Pour std::gcd

template <typename T>
class Rational
{
private:
    T numerator;
    T denominator;

    void simplify(){
        T gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0)
        { // Assurer que le dénominateur est positif
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructeurs
    Rational(T num = 0, T denom = 1) : numerator(num), denominator(denom){
        if (denom == 0)
            throw std::invalid_argument("Dénominateur ne peut pas être nul");
        simplify();
    }

    // Opérateurs arithmétiques
    Rational operator+(const Rational &other) const{
        T num = numerator * other.denominator + other.numerator * denominator;
        T denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational operator-(const Rational &other) const{
        T num = numerator * other.denominator - other.numerator * denominator;
        T denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational operator*(const Rational &other) const{
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational &other) const{
        if (other.numerator == 0)
            throw std::domain_error("Division par zéro");
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    // Opérateurs de comparaison
    bool operator==(const Rational &other) const{
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator<(const Rational &other) const{
        return numerator * other.denominator < other.numerator * denominator;
    }

    // Opérateurs de flux
    friend std::ostream &operator<<(std::ostream &os, const Rational &value){
        os << value.numerator << "/" << value.denominator;
        return os;
    }

    
};

#endif // RATIONAL_HPP
