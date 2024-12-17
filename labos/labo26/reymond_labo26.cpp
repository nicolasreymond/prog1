/**
 * @file    reymond_labo26.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief
 * @version 1.0
 * @date    20-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>
#include "Unsigned.hpp" // Réutilisation de la classe Unsigned

using namespace std;

class Int
{
private:
    bool sign;
    Unsigned value;

public:
    Int();
    Int(const string &binary);
    Int(int64_t number);
    string to_base(int base) const;
    int64_t to_int64() const;
    string data() const;
    operator int64_t() const;
    Int &operator+=(const Int &right);
    Int &operator-=(const Int &right);
    Int &operator*=(const Int &right);
    Int &operator/=(const Int &right);
    Int &operator%=(const Int &right);
    bool operator<(const Int &right) const;
    bool operator<=(const Int &right) const;
    bool operator>(const Int &right) const;
    bool operator>=(const Int &right) const;
    bool operator==(const Int &right) const;
    bool operator!=(const Int &right) const;
    friend Int operator+(Int left, const Int &right);
    friend Int operator-(Int left, const Int &right);
    friend Int operator*(Int left, const Int &right);
    friend Int operator/(Int left, const Int &right);
    friend Int operator%(Int left, const Int &right);
    friend ostream &operator<<(ostream &os, const Int &number);
    Int &operator++();
    Int operator++(int);
    Int &operator--();
    Int operator--(int);
};

Int::Int() : sign(false), value(0) {}

Int::Int(const string &binary) {
    if (binary.empty()) {
        throw invalid_argument("Empty string");
    }
    sign = binary[0] == '-';
    value = Unsigned(sign ? binary.substr(1) : binary);
}

Int::Int(int64_t number)
{
    sign = number < 0;
    value = Unsigned(sign ? -number : number);
}

int64_t Int::to_int64() const {
    int64_t result = static_cast<int64_t>(value.to_uint64());
    return sign ? -result : result;
}

string Int::data() const {
    return (sign ? "-" : "") + value.data();
}

string Int::to_base(int base) const
{
    return value.to_base(base);
}

Int::operator int64_t() const {
    return to_int64();
}

Int &Int::operator+=(const Int &right)
{
    if (sign == right.sign)
    {
        value += right.value;
    }
    else
    {
        if (value < right.value)
        {
            sign = !sign;
            value = right.value - value;
        }
        else
        {
            value -= right.value;
        }
    }
    return *this;
}

Int &Int::operator-=(const Int &right)
{
    if (sign == right.sign)
    {
        if (value < right.value)
        {
            sign = !sign;
            value = right.value - value;
        }
        else
        {
            value -= right.value;
        }
    }
    else
    {
        value += right.value;
    }
    return *this;
}

Int &Int::operator*=(const Int &right)
{
    sign = sign != right.sign;
    value *= right.value;
    return *this;
}

Int &Int::operator/=(const Int &right)
{
    sign = sign != right.sign;
    value /= right.value;
    return *this;
}

Int &Int::operator%=(const Int &right)
{
    sign = sign != right.sign;
    value %= right.value;
    return *this;
}

bool Int::operator<(const Int &right) const
{
    if (sign != right.sign)
    {
        return sign;
    }
    if (sign)
    {
        return value > right.value;
    }
    return value < right.value;
}

bool Int::operator<=(const Int &right) const
{
    return *this < right || *this == right;
}

bool Int::operator>(const Int &right) const
{
    return !(*this <= right);
}

bool Int::operator>=(const Int &right) const
{
    return !(*this < right);
}

bool Int::operator==(const Int &right) const
{
    return sign == right.sign && value == right.value;
}

bool Int::operator!=(const Int &right) const
{
    return !(*this == right);
}

Int operator+(Int left, const Int &right)
{
    left += right;
    return left;
}

Int operator-(Int left, const Int &right)
{
    left -= right;
    return left;
}

Int operator*(Int left, const Int &right)
{
    left *= right;
    return left;
}

Int operator/(Int left, const Int &right)
{
    left /= right;
    return left;
}

Int operator%(Int left, const Int &right)
{
    left %= right;
    return left;
}

ostream &operator<<(ostream &os, const Int &number)
{
    if (number.sign)
    {
        os << '-';
    }
    os << number.value;
    return os;
}

Int &Int::operator++() {
    *this += Int(1);
    return *this;
}

Int Int::operator++(int) {
    Int temp = *this;
    ++(*this);
    return temp;
}

Int &Int::operator--() {
    *this -= Int(1);
    return *this;
}

Int Int::operator--(int) {
    Int temp = *this;
    --(*this);
    return temp;
}

int main()
{
    Int num1(42);
    Int num2(-42);
    Int num3(0);

    cout << num1+num2 << endl;

    cout << showpos << num1 << endl;
    cout << showpos << num2 << endl;
    cout << showpos << num3 << endl;

    cout << noshowpos << num1 << endl;
    cout << noshowpos << num2 << endl;
    cout << noshowpos << num3 << endl;

    cout << showbase << num1 << endl;
    cout << showbase << num2 << endl;
    cout << showbase << num3 << endl;
}
