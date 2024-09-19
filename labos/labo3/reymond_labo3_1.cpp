/**
 * @file    reymond_labo3.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Programme qui additionne deux longueurs en km, m, cm et mm
 * @version 1.0
 * @date    2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

using namespace std;

int main() {
    int km1, m1, cm1, mm1;
    int km2, m2, cm2, mm2;

    // Input for the first length
    cout << "Enter first length (km m cm mm): ";
    cin >> km1 >> m1 >> cm1 >> mm1;

    // Input for the second length
    cout << "Enter second length (km m cm mm): ";
    cin >> km2 >> m2 >> cm2 >> mm2;

    // Adding the respective parts of the lengths
    int total_km = km1 + km2;
    int total_m = m1 + m2;
    int total_cm = cm1 + cm2;
    int total_mm = mm1 + mm2;

    cout << "The sum is: " << total_km << " km, " << total_m << " m, " << total_cm << " cm, " << total_mm << " mm\n";
    return 0;
}