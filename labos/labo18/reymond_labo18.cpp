/**
 * @file    reymond_labo18.cpp
 * @author  Nicolas Reymond
 * @brief   Sudoku grid display from file
 * @version 1.0
 * @date    20-09-2024
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printBorder(int size, int y, const string &left, const string &mid, const string &right, const string &innerMid){
    cout << left;
    for (int k = 0; k < size; k++)
    {
        cout << "━━━";
        if (k < size - 1)
        {
            cout << ((k + 1) % y == 0 ? mid : innerMid);
        }
    }
    cout << right << endl;
}

void printInnerBorder(int size, int y, const string &left, const string &mid, const string &right){
    cout << left;
    for (int k = 0; k < size; k++)
    {
        cout << "───";
        if (k < size - 1)
        {
            cout << ((k + 1) % y == 0 ? mid : "┼");
        }
    }
    cout << right << endl;
}

vector<vector<int>> readSudokuFromFile(const string &filename, int size){
    ifstream file(filename);
    vector<vector<int>> grid(size, vector<int>(size, 0));

    if (file.is_open())
    {
        // Skip the first line
        string dummyLine;
        getline(file, dummyLine);
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                file >> grid[i][j];
            }
        }
        file.close();
    }
    else
    {
        cerr << "Unable to open file" << endl;
    }

    return grid;
}

void displaySudokuFromFile(const vector<vector<int>> &grid, int x, int y){
    int size = x * y;

    // Print top border
    printBorder(size, y, "┏", "┳", "┓", "┯");

    // Print sudoku grid
    for (int i = 0; i < size; i++)
    {
        if (i % x == 0 && i != 0)
        {
            printBorder(size, y, "┣", "╋", "┫", "┿");
        }
        else if (i != 0)
        {
            printInnerBorder(size, y, "┠", "╂", "┨");
        }

        cout << "┃";
        for (int j = 0; j < size; j++)
        {
            int num = grid[i][j];
            if (num == 0)
            {
                cout << "   ";
            }
            else if (num < 10)
            {
                cout << " " << num << " ";
            }
            else
            {
                cout << num << " ";
            }
            if (j < size - 1)
            {
                if ((j + 1) % y == 0)
                {
                    cout << "┃";
                }
                else
                {
                    cout << "│";
                }
            }
        }
        cout << "┃" << endl;
    }

    // Print bottom border
    printBorder(size, y, "┗", "┻", "┛", "┷");
}

int main(int argc, char *argv[]){
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    // Ask for the dimensions of the sudoku
    // cout << "Enter two integer values for the dimensions of the sudoku: " << endl;
    int x, y;
    // cin >> x >> y;

    ifstream file(argv[1]);
    if (file.is_open())
    {
        file >> x >> y;
        file.close();
    }
    else
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    int size = x * y;
    vector<vector<int>> grid = readSudokuFromFile(argv[1], size);
    cout << "x = " << x << " y = " << y << endl;

    displaySudokuFromFile(grid, x, y);
    return 0;
}
