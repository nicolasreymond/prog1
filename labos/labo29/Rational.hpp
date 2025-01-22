/**
 * @file nicolas_reymond_labo27.hpp
 * @brief Headers for the Rationnel class to manipulate rational numbers. Taken from lab 12 but with genericity.
 * @version 0.1
 * @date 19.12.2024
 * 
 */
#ifndef RATIONNEL_H
#define RATIONNEL_H

#include <iostream>
#include <numeric>
#include <stdexcept>

// Forward declaration of the Rationnel class for stream operators
template<typename T> class Rationnel;

// Declaration of stream operators
template <typename T>
std::ostream& operator<<(std::ostream& os, const Rationnel<T>& r);

template<typename T>
std::istream& operator>>(std::istream& is, Rationnel<T>& r);

/**
 * @brief Generic class for manipulating rational numbers
 * 
 * @tparam T Type used in the rationals (usually integers)
 */
template <typename T>
class Rationnel {
private:
    T num;
    T den;

    // Methods
    void simplifie();

public:
    // Constructors
    Rationnel();
    Rationnel(T numerateur, T denominateur = 1);

    // Arithmetic operators
    Rationnel<T> operator+(const Rationnel<T>& r2) const;
    Rationnel<T> operator+() const;
    Rationnel<T> operator-(const Rationnel<T>& r2) const;
    Rationnel<T> operator-() const;
    Rationnel<T> operator*(const Rationnel<T>& r2) const;
    Rationnel<T> operator/(const Rationnel<T>& r2) const;
    Rationnel<T> operator!() const;

    // Assignment operators
    Rationnel<T>& operator+=(Rationnel<T> r2);
    Rationnel<T>& operator-=(Rationnel<T> r2);
    Rationnel<T>& operator*=(Rationnel<T> r2);
    Rationnel<T>& operator/=(Rationnel<T> r2);

    // Stream operators
    friend std::ostream& operator<< <T>(std::ostream& os, const Rationnel<T>& r);
    friend std::istream& operator>> <T>(std::istream& is, Rationnel<T>& r);

    // Comparison operators
    bool operator<(const Rationnel<T>& r) const;
    bool operator<=(const Rationnel<T>& r) const;
    bool operator>(const Rationnel<T>& r) const;
    bool operator>=(const Rationnel<T>& r) const;
    bool operator==(const Rationnel<T>& r) const;
    bool operator!=(const Rationnel<T>& r) const;

    Rationnel<T> abs() const;
    static T gcd(T a, T b);
    static T lcm(T a, T b);
};

template <typename T>
void Rationnel<T>::simplifie() {
    if (this->den < 0) {
        this->den *= -1;
        this->num *= -1;
    }
    T gcd = Rationnel<T>::gcd(this->num, this->den);
    this->num /= gcd;
    this->den /= gcd;
}

template <typename T>
Rationnel<T>::Rationnel() : num(0), den(1) {}

template <typename T>
Rationnel<T>::Rationnel(T numerateur, T denominateur) : num(numerateur), den(denominateur) {
    if (this->den == 0) {
        throw std::invalid_argument("Denominator is zero, impossible!");
    }
    this->simplifie();
}

// Arithmetic operators
template <typename T>
Rationnel<T> Rationnel<T>::operator+(const Rationnel<T>& r2) const {
    Rationnel<T> cpy = *this;
    return {cpy += r2};
}

template<typename T>
Rationnel<T> Rationnel<T>::operator+() const {
    return *this;
}

template<typename T>
Rationnel<T> Rationnel<T>::operator-(const Rationnel<T>& r2) const {
    Rationnel<T> cpy = *this;
    return {cpy -= r2};
}

template <typename T>
Rationnel<T> Rationnel<T>::operator-() const {
    if ((num < 0 && den < 0) || (num > 0 && den < 0)) return {num, -den};
    else return {-num, den};
}

template <typename T>
Rationnel<T> Rationnel<T>::operator*(const Rationnel<T>& r2) const {
    Rationnel<T> cpy = *this;
    return {cpy *= r2};
}

template <typename T>
Rationnel<T> Rationnel<T>::operator/(const Rationnel<T>& r2) const {
    Rationnel<T> cpy = *this;
    return {cpy /= r2};
}

template <typename T>
Rationnel<T> Rationnel<T>::operator!() const {
    if (num < 0) {
        return {-den, -num};
    }
    return {den, num};
}

// Assignment operators
template <typename T>
Rationnel<T>& Rationnel<T>::operator+=(Rationnel<T> r2) {
    if (this->den == r2.den) {
        this->num += r2.num;
    } else {
        T lcm = Rationnel<T>::lcm(this->den, r2.den);
        this->num = this->num * (lcm / this->den) + r2.num * (lcm / r2.den);
        this->den = lcm;
    }
    this->simplifie();
    return *this;
}

template <typename T>
Rationnel<T>& Rationnel<T>::operator-=(Rationnel<T> r2) {
    return *this += -r2;
}

template <typename T>
Rationnel<T>& Rationnel<T>::operator*=(Rationnel<T> r2) {
    this->num *= r2.num;
    this->den *= r2.den;
    this->simplifie();
    return *this;
}

template <typename T>
Rationnel<T>& Rationnel<T>::operator/=(Rationnel<T> r2) {
    return *this *= !r2;
}

// Stream operators
template <typename T>
std::ostream& operator<<(std::ostream& os, const Rationnel<T>& r) {
    os << r.num << "/" << r.den;
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, Rationnel<T>& r) {
    is >> r.num;
    is.ignore(1);
    is >> r.den;
    return is;
}

// Comparison operators
template <typename T>
bool Rationnel<T>::operator<(const Rationnel<T>& r) const {
    return this->num * r.den < r.num * this->den;
}

template <typename T>
bool Rationnel<T>::operator<=(const Rationnel<T>& r) const {
    return !(r < *this);
}

template <typename T>
bool Rationnel<T>::operator>(const Rationnel<T>& r) const {
    return r < *this;
}

template <typename T>
bool Rationnel<T>::operator>=(const Rationnel<T>& r) const {
    return !(*this < r);
}

template <typename T>
bool Rationnel<T>::operator==(const Rationnel<T>& r) const {
    return this->num * r.den == r.num * this->den;
}

template <typename T>
bool Rationnel<T>::operator!=(const Rationnel<T>& r) const {
    return !(*this == r);
}

// Member function definitions
template <typename T>
Rationnel<T> Rationnel<T>::abs() const {
    if (this->num < 0) {
        return -*this;
    } else return *this;
}

template <typename T>
T Rationnel<T>::gcd(T a, T b) {
    while (b != 0) {
        T t = b;
        b = a % b;
        a = t;
    }
    return a;
}

template <typename T>
T Rationnel<T>::lcm(T a, T b) {
    return a * b / gcd(a, b);
}

#endif // RATIONNEL_H