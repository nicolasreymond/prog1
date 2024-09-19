/**
 * @file    reymond_labo3.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Programme qui calcule la durée entre deux heures
 * @version 1.0
 * @date    2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

using namespace std;

// Function to calculate the difference between two times
void calculate_duration(int start_h, int start_m, int end_h, int end_m) {
    int start_total = start_h * 60 + start_m;  // Start time in minutes
    int end_total = end_h * 60 + end_m;        // End time in minutes

    // If the start time is greater than the end time, it means the time is over two days
    if (start_total > end_total) {
        end_total += 24 * 60;  // Add 24 hours in minutes to the end time
    }

    int duration = end_total - start_total;
    int duration_h = duration / 60;
    int duration_m = duration % 60;

    // Display the result
    cout << "The duration is: " << duration_h << " hour(s) and " << duration_m << " minute(s)\n";
}

int main() {
    int start_h, start_m, end_h, end_m;

    // Input for the start time
    cout << "Enter the start time (hh mm): ";
    cin >> start_h >> start_m;

    // Input for the end time
    cout << "Enter the end time (hh mm): ";
    cin >> end_h >> end_m;

    calculate_duration(start_h, start_m, end_h, end_m);

    return 0;
}