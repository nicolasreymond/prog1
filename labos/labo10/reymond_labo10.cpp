/**
 * @file    reymond_labo3.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Estimation of Pi using Monte Carlo method
 * @version 1.0
 * @date    07.10.2024
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <random>
// for INT_MAX
#include <climits> 

using namespace std;

// Function to estimate the value of Pi
double estimatePi(int numDraws)
{
    int insideCircle = 0;
    random_device rd;                          
    mt19937 gen(rd());                         
    uniform_real_distribution<> dis(0.0, 1.0); 

    // Drawing random points in the unit square
    for (int i = 0; i < numDraws; ++i)
    {
        double x = dis(gen); 
        double y = dis(gen); 
        // Check if the point is in the quarter circle
        if (x * x + y * y <= 1.0)
        {
            insideCircle++;
        }
    }

    // Estimation of Pi
    return 4.0 * insideCircle / numDraws;
}

int main()
{
    cout << "Estimation of Pi for powers of 2 up to INT_MAX:\n";

    // Estimate Pi for powers of 2 until we reach the limit of an int
    for (int i = 1; i > 0 && i <= INT_MAX / 2; i *= 2)
    {
        double piEstimate = estimatePi(i);
        cout << "Number of draws: " << i << " - Estimation of Pi: " << piEstimate << endl;
    }

    return 0;
}
