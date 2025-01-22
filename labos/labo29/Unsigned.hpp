/**
 * @file nicolas_reymond_labo24.hpp
 * @brief Headers for the classes used in labs 24 and 25
 * @version 0.1
 * @date 02.12.2024
 * 
 */
#ifndef Unsigned_H
#define Unsigned_H

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <exception>

using namespace std;

/**
 * @brief Allows modification of bases within the Unsigned class
 * 
 */
class Setbase {
public:
    static Setbase set_base(int base);
    friend ostream& operator<<(ostream& os, Setbase a);
};

/**
 * @brief Allows manipulation of unsigned numbers via its member functions and several overloaded operators
 * 
 */
class Unsigned {
private:
    string valeur;
    static int base;
    string convertToBase() const;
    static pair<Unsigned, Unsigned> quotient_reste(const Unsigned& a, const Unsigned& b);

public:
    Unsigned(string binaire);
    Unsigned(uint64_t n = 0);

    // Getter
    string data() const;

    // Overloaded operators
    friend bool operator<(const Unsigned& a, const Unsigned& b);
    friend bool operator<=(const Unsigned& a, const Unsigned& b);
    friend bool operator>(const Unsigned& a, const Unsigned& b);
    friend bool operator>=(const Unsigned& a, const Unsigned& b);
    friend bool operator==(const Unsigned& a, const Unsigned& b);
    friend bool operator!=(const Unsigned& a, const Unsigned& b);
    friend Unsigned& operator+=(Unsigned& a, const Unsigned& b);
    friend Unsigned& operator-=(Unsigned& a, const Unsigned& b);
    friend Unsigned operator+(Unsigned a, const Unsigned& b);
    friend Unsigned operator-(Unsigned a, const Unsigned& b);
    friend Unsigned& operator*=(Unsigned& a, const Unsigned& b);
    friend Unsigned operator*(Unsigned a, const Unsigned& b);
    friend Unsigned& operator/=(Unsigned& a, const Unsigned& b);
    friend Unsigned operator/(Unsigned a, const Unsigned& b);
    friend Unsigned& operator%=(Unsigned& a, const Unsigned& b);
    friend Unsigned operator%(Unsigned a, const Unsigned& b);
    friend ostream& operator<<(ostream& os, const Unsigned& a);
    friend Unsigned operator++(Unsigned& a, int);
    friend Unsigned& operator++(Unsigned& a);
    friend Unsigned operator--(Unsigned& a, int);
    friend Unsigned& operator--(Unsigned& a);
    operator uint64_t() const;

    static Unsigned random(size_t length);

    // Setbase function
    friend Setbase Setbase::set_base(int base);
};

#endif