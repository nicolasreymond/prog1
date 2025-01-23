/**
 * @file Int.hpp
 * @brief Headers for the Int class
 * @version 1.3
 * @date 23.01.2025
 * 
 */
#ifndef Int_H
#define Int_H
#include "Unsigned.hpp"
#include <iostream>
#include <type_traits>

using namespace std;

class Int {
private:
    Unsigned valeur;
    bool signe;

public:
    // Constructors
    Int(Unsigned valeur, bool signe);
    Int(int valeur = 0);

    // Unary operators
    Int operator-() const;

    // Assignment operators
    Int& operator+=(const Int& b);
    Int& operator-=(const Int& b);
    Int& operator*=(const Int& b);
    Int& operator/=(const Int& b);
    Int& operator%=(const Int& b);

    // Arithmetic operators
    Int operator+(const Int& b) const;
    Int operator-(const Int& b) const;
    Int operator*(const Int& b) const;
    Int operator/(const Int& b) const;
    Int operator%(const Int& b) const;

    // Comparison operators
    bool operator<(const Int& b) const;
    bool operator<=(const Int& b) const;
    bool operator>(const Int& b) const;
    bool operator>=(const Int& b) const;
    bool operator==(const Int& b) const;
    bool operator!=(const Int& b) const;

    // Stream operators
    friend ostream& operator<<(ostream& os, const Int& a);
    friend istream& operator>>(istream& is, Int& a);

    // Increment and decrement operators
    Int operator++(int);
    Int& operator++();
    Int operator--(int);
    Int& operator--();

    // Conversion
    // operator int() const;

    // Getters  
    Unsigned getValeur() const { return valeur; }
    bool getSigne() const { return signe; }
};

#endif