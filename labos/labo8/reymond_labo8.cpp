/**
 * @file    reymond_labo8.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Nested squares drawing program
 * @version 1.1
 * @date    2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
using namespace std;

void drawNestedSquares(int n) {
    int size = 2 * n - 1;  // Total size of the grid

    // Loop for each row
    for (int i = 0; i < size; i++) {
        // Loop for each column
        for (int j = 0; j < size; j++) {
            // Find the minimum distance to the edges
            int minDist = min(min(i, j), min(size - 1 - i, size - 1 - j));

            // If drawing the central square
            if (n % 2 == 1 && i == j && i == size / 2) {
                cout << "■";
                continue;
            }

            // Draw corners, horizontal and vertical lines according to the minimum distance
            if (minDist % 2 == 0) {
                if (i == minDist && j == minDist) {
                    // Top left corner
                    cout << "┌";
                } else if (i == minDist && j == size - 1 - minDist) {
                    // Top right corner
                    cout << "┐";
                } else if (i == size - 1 - minDist && j == minDist) {
                    // Bottom left corner
                    cout << "└";
                } else if (i == size - 1 - minDist && j == size - 1 - minDist) {
                    // Bottom right corner
                    cout << "┘";
                } else if (i == minDist || i == size - 1 - minDist) {
                    // Horizontal lines
                    cout << "─";
                } else if (j == minDist || j == size - 1 - minDist) {
                    // Vertical lines
                    cout << "│";
                }
            } else {
                // Spaces between squares
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "How many nested squares? ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of squares must be greater than 0." << endl;
        return 1;
    }

    drawNestedSquares(n * 2 - 1);
    return 0;
}
