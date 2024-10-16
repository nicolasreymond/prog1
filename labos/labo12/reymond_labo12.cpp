/**
 * @file    reymond_labo12.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   
 * @version 1.0
 * @date    14.10.2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Rationnel.hpp"
using namespace std;

int main() {
    // Declare variables for numerator and denominator
    int num1, den1, num2, den2;

    // Test for operator-
    num1 = 3; den1 = 4;
    num2 = 1; den2 = 4;
    Rationnel r2 = {num2, den2};
    cout << "Testing operator-: " << (Rationnel{num1, den1} - Rationnel{num2, den2}) << endl;

    // Test for operator+=
    Rationnel r1{1, 2};
    num1 = 1; den1 = 4;
    r1 += Rationnel{num1, den1};
    cout << "Testing operator+=: " << r1 << endl;

    // Test for operator+
    num1 = 1; den1 = 2;
    num2 = 1; den2 = 4;
    cout << "Testing operator+: " << (Rationnel{num1, den1} + Rationnel{num2, den2}) << endl;

    // Test for operator-=
    Rationnel r2{3, 4};
    num1 = 1; den1 = 4;
    r2 -= Rationnel{num1, den1};
    cout << "Testing operator-=: " << r2 << endl;

    // Test for operator/
    num1 = 1; den1 = 2;
    num2 = 1; den2 = 4;
    cout << "Testing operator/: " << (Rationnel{num1, den1} / 2) << endl;

    // Test for operator*
    num1 = 1; den1 = 2;
    num2 = 1; den2 = 4;
    cout << "Testing operator*: " << (Rationnel{num1, den1} * Rationnel{num2, den2}) << endl;

    // Test for operator<
    num1 = 1; den1 = 2;
    num2 = 1; den2 = 4;
    cout << "Testing operator<: " << (Rationnel{num1, den1} < Rationnel{num2, den2}) << endl;

    // Test for operator>
    num1 = 1; den1 = 2;
    num2 = 1; den2 = 4;
    cout << "Testing operator>: " << (Rationnel{num1, den1} > Rationnel{num2, den2}) << endl;

    // Test for operator==
    num1 = 1; den1 = 2;
    num2 = 1; den2 = 4;
    cout << "Testing operator==: " << (Rationnel{num1, den1} == Rationnel{num2, den2}) << endl;

    // Test for operator!=
    num1 = 1; den1 = 2;
    num2 = 1; den2 = 4;
    cout << "Testing operator!=: " << (Rationnel{num1, den1} != Rationnel{num2, den2}) << endl;

    return 0;
}
