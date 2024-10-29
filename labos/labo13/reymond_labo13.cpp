/**
 * @file    reymond_labo13.cpp
 * @author  Nicolas Reymond
 * @brief   Display a sudoku grid with the given dimensions
 * @version 1.0
 * @date    28.10.2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

using namespace std;

void printBorder(int size, int y, const string& left, const string& mid, const string& right, const string& innerMid) {
    cout << left;
    for (int k = 0; k < size; k++) {
        cout << "━━━";
        if (k < size - 1) {
            cout << ((k + 1) % y == 0 ? mid : innerMid);
        }
    }
    cout << right << endl;
}

void printInnerBorder(int size, int y, const string& left, const string& mid, const string& right) {
    cout << left;
    for (int k = 0; k < size; k++) {
        cout << "───";
        if (k < size - 1) {
            cout << ((k + 1) % y == 0 ? mid : "┼");
        }
    }
    cout << right << endl;
}

void displaySudoku(int x, int y) {
    int size = x * y;

    // Print top border
    printBorder(size, y, "┏", "┳", "┓", "┯");

    // Print sudoku grid
    for (int i = 0; i < size; i++) {
        if (i % x == 0 && i != 0) {
            printBorder(size, y, "┣", "╋", "┫", "┿");
        } else if (i != 0) {
            printInnerBorder(size, y, "┠", "╂", "┨");
        }

        cout << "┃";
        for (int j = 0; j < size; j++) {
            int num = (i * y + i / x + j) % size + 1;
            if (num < 10) {
                cout << " " << num << " ";
            } else {
                cout << num << " ";
            }
            if (j < size - 1) {
                if ((j + 1) % y == 0) {
                    cout << "┃";
                } else {
                    cout << "│";
                }
            }
        }
        cout << "┃" << endl;
    }

    // Print bottom border
    printBorder(size, y, "┗", "┻", "┛", "┷");
}


int main() {
    // Ask for the dimensions of the sudoku
    cout << "Enter two integer values for the dimensions of the sudoku: " << endl;
    int x, y;
    cin >> x >> y;

    displaySudoku(x, y);
    return 0;
}
