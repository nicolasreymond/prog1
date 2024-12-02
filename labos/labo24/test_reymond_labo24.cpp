/**
 * @file    test_reymond_labo24.cpp
 * @brief   Unit tests for reymond_labo24.cpp
 * @version 1.0
 * @date    20-09-2024
 */

#include <iostream>
#include <cassert>
#include "reymond_labo24.hpp"

using namespace std;

void test_addition()
{
    Unsigned u1("1010");   // 10 in binary
    Unsigned u2(10);       // 10 in decimal
    Unsigned u3 = u1 + u2; // 20 in binary
    assert(u3.to_decimal() == "20");
}

void test_subtraction()
{
    Unsigned u1("1010");   // 10 in binary
    Unsigned u2(10);       // 10 in decimal
    Unsigned u4 = u1 - u2; // 0 in binary
    assert(u4.to_decimal() == "0");
}

void test_multiplication()
{
    Unsigned u1("1010");   // 10 in binary
    Unsigned u2(10);       // 10 in decimal
    Unsigned u5 = u1 * u2; // 100 in binary
    assert(u5.to_decimal() == "100");
}

void test_factorial()
{
    Unsigned result("1");
    for (int i = 1; i <= 5; ++i)
    {
        result *= Unsigned(i);
    }
    assert(result.to_decimal() == "120");
}

void test_fibonacci()
{
    Unsigned a("0");
    Unsigned b("1");
    Unsigned c("0");
    for (int i = 0; i < 10; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    assert(a.to_decimal() == "55");
}

int main(void)
{
    test_addition();
    test_subtraction();
    test_multiplication();
    test_factorial();
    test_fibonacci();

    cout << "All tests passed!" << endl;
    return 0;
}