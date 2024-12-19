/**
 * @file    reymond_labo27.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Main file for the Rational class
 * @version 1.0
 * @date    20-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Rational.hpp" // Include the Rational header file

int main(){
    Rational<int> r1(1, 2);
    Rational<int> r2(3, 4);

    std::cout << "r1: " << r1 << std::endl;
    std::cout << "r2: " << r2 << std::endl;

    Rational<int> r3 = r1 + r2;
    std::cout << "r1 + r2: " << r3 << std::endl;

    Rational<int> r4 = r1 - r2;
    std::cout << "r1 - r2: " << r4 << std::endl;

    Rational<int> r5 = r1 * r2;
    std::cout << "r1 * r2: " << r5 << std::endl;

    Rational<int> r6 = r1 / r2;
    std::cout << "r1 / r2: " << r6 << std::endl;

    std::cout << "r1 == r2: " << (r1 == r2) << std::endl;
    std::cout << "r1 < r2: " << (r1 < r2) << std::endl;
    std::cout << "r1 == r1: " << (r1 == r1) << std::endl;
    std::cout << "r1 < r1: " << (r1 < r1) << std::endl;

    return 0;
}
