#ifndef REYMOND_LABO24_HPP
#define REYMOND_LABO24_HPP

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class Setbase
{
public:
    static int base;
    Setbase(int b);
    Setbase set_base(int base);
    friend ostream &operator<<(ostream &os, const Setbase &);
};

class Unsigned
{
private:
    string value;

public:
    Unsigned(const string &binary);
    Unsigned(uint64_t number);
    string to_base(int base) const;
    friend bool operator==(const Unsigned &left, const Unsigned &right);
    Unsigned &operator+=(const Unsigned &right);
    Unsigned &operator-=(const Unsigned &right);
    Unsigned &operator*=(const Unsigned &right);
    Unsigned &operator/=(const Unsigned &right);
    bool operator<(const Unsigned &right) const;
    bool operator<=(const Unsigned &right) const;
    bool operator>(const Unsigned &right) const;
    bool operator>=(const Unsigned &right) const;
    Unsigned &operator%=(const Unsigned &right);
    friend Unsigned operator+(Unsigned left, const Unsigned &right);
    friend Unsigned operator-(Unsigned left, const Unsigned &right);
    friend Unsigned operator*(Unsigned left, const Unsigned &right);
    friend Unsigned operator/(Unsigned left, const Unsigned &right);
    friend Unsigned operator%(Unsigned left, const Unsigned &right);
    friend ostream &operator<<(ostream &os, const Unsigned &number);
    Unsigned &operator++();
    Unsigned operator++(int);
    Unsigned &operator--();
    Unsigned operator--(int);
    string data() const;
};

#endif // REYMOND_LABO24_HPP