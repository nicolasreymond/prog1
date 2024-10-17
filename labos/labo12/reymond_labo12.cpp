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
#include <stdexcept> // For exception messages
#include "Rationnel.hpp"

using namespace std;

int main() {
    // Declare variables for numerator and denominator
    int numerator1, denominator1, numerator2, denominator2;

    // Input first rational number
    Rationnel rational1 = Rationnel{numerator1, denominator1};
    Rationnel rational2 = Rationnel{numerator2, denominator2};
    
    cout << "Enter numerator and denominator for first rational number: ";
    cin >> numerator1 >> denominator1;

    // Input second rational number
    cout << "Enter numerator and denominator for second rational number: ";
    cin >> numerator2 >> denominator2;

    // Test all operators
    // Addition
    Rationnel result = rational1 + rational2;
    cout << rational1 << " + " << rational2 << " = " << result << endl;

    // Subtraction
    result = rational1 - rational2;
    cout << rational1 << " - " << rational2 << " = " << result << endl;

    // Multiplication
    result = rational1 * rational2;
    cout << rational1 << " * " << rational2 << " = " << result << endl;

    // Division (handled inside the operator function)
    if (rational2.num == 0) {
        cerr << "Error: Division by zero is not allowed." << endl;
    } else {
        result = rational1 / rational2;
        cout << rational1 << " / " << rational2 << " = " << result << endl;
    }

    // Create two rational numbers
    Rationnel rational3 = {3, 4}; // 3/4
    Rationnel rational4 = {2, 4}; // 2/4

    // Simplify rationals
    rational3 = simplifier(rational3);
    rational4 = simplifier(rational4);

    // Display simplified rationals
    cout << "Simplified rationals:" << endl;
    afficher(rational3);
    afficher(rational4);

    // Test comparison operators

    // Test equality
    if (rational3 == rational4) {
        cout << "rational3: " << rational3 << ", rational4: " << rational4 << " are equal" << endl;
    } else {
        cout << "rational3: " << rational3 << ", rational4: " << rational4 << " are different " << endl;
    }

    // Test inequality
    if (rational3 != rational4) {
        cout << rational3 << " != " << rational4 << endl;
    } else {
        cout << rational3 << " == " << rational4 << endl;
    }

    // Test less than
    if (rational3 < rational4) {
        cout << rational3 << " < " << rational4 << endl;
    } else {
        cout << rational3 << " >= " << rational4 << endl;
    }

    // Test less than or equal
    if (rational3 <= rational4) {
        cout << rational3 << " <= " << rational4 << endl;
    } else {
        cout << rational3 << " > " << rational4 << endl;
    }

    // Test greater than
    if (rational3 > rational4) {
        cout << rational3 << " > " << rational4 << endl;
    } else {
        cout << rational3 << " <= " << rational4 << endl;
    }

    // Test greater than or equal
    if (rational3 >= rational4) {
        cout << rational3 << " >= " << rational4 << endl;
    } else {
        cout << rational3 << " < " << rational4 << endl;
    }

    // Return 0 to indicate success
    return 0;
}
