/**
 * @file    reymond_labo9.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Syracuse sequence and number of steps to reach 1
 * @version 1.0
 * @date    07.10.2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
using namespace std;

// Function to calculate the Syracuse sequence
void syracuse(int n){
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2 == 0)
            n = n / 2;
        else
            n = n * 3 + 1;
    }
    cout << 1 << endl;
}

// Function to show how many steps are needed to reach 1
void syracuseSteps(int n){
    int steps = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = n * 3 + 1;
        steps++;
    }
    cout << "Number of steps: " << steps << endl;
}

int main(){
    int n;
    cout << "Enter a number to calculate the Syracuse sequence: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    syracuse(n);
    syracuseSteps(n);

    return 0;
}
