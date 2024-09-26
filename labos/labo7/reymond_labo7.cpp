/**
 * @file    reymond_labo7.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Labo 7 - Mean and variance calculator
 * @version 1.0
 * @date    26-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <cmath> // For pow function

using namespace std;

int main()
{
    double num, sum = 0, sumOfSquares = 0;
    int count = 0;

    cout << "Entrez une suite de valeurs non négatives (nombre négatif pour terminer):" << endl;

    // Input loop using while
    while (true)
    {
        cin >> num;
        if (num < 0)
        {
            break; // Exit the loop when a negative number is entered
        }
        sum += num;                // Sum of all the numbers
        sumOfSquares += num * num; // Sum of squares of all the numbers
        count++;
    }

    if (count == 0)
    {
        cout << "Aucune valeur valide n'a été entrée." << endl;
    }
    else
    {
        // Calculate the mean
        double mean = sum / count;

        // Calculate the variance
        double variance = (sumOfSquares - (sum * sum) / count) / (count - 1);

        // Output the results
        cout << "Moyenne: " << mean << endl;
        cout << "Variance: " << variance << endl;
    }

    return 0;
}
