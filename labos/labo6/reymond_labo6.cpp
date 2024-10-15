/**
 * @file    reymond_labo6.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Labo 6 - Quadrilateral classification
 * @version 1.0
 * @date    26-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

using namespace std;

int main(){

    int x1, y1, x2, y2, x3, y3, x4, y4;

    // Input the coordinates of the four vertices
    cout << "Entrez les coordonnées des 4 sommets du quadrilatère (x y):\n";
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;

    int d1 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1); // distance squared from p1 to p2
    int d2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2); // distance squared from p2 to p3
    int d3 = (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3); // distance squared from p3 to p4
    int d4 = (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4); // distance squared from p4 to p1

    int dot1 = (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1); // dot product of p1p2 and p1p3
    int dot2 = (x3 - x2) * (x4 - x2) + (y3 - y2) * (y4 - y2); // dot product of p2p3 and p2p4

    // Check for square
    if (d1 == d2 && d2 == d3 && d3 == d4 && dot1 == 0 && dot2 == 0)
    {
        cout << "Le quadrilatère est un carré\n";
    }
    // Check for rectangle
    else if (d1 == d3 && d2 == d4 && dot1 == 0 && dot2 == 0)
    {
        cout << "Le quadrilatère est un rectangle\n";
    }
    // Check for rhombus
    else if (d1 == d2 && d2 == d3 && d3 == d4 && dot1 != 0 && dot2 != 0)
    {
        cout << "Le quadrilatère est un losange\n";
    }
    // Check for parallelogram
    else if (d1 == d3 && d2 == d4 && dot1 != 0 && dot2 != 0)
    {
        cout << "Le quadrilatère est un parallélogramme\n";
    }
    // Check for trapezoid (one pair of parallel sides)
    else if ((x2 - x1) * (y3 - y2) == (y2 - y1) * (x3 - x2) || (x3 - x2) * (y4 - y3) == (y3 - y2) * (x4 - x3) ||
             (x4 - x3) * (y1 - y4) == (y4 - y3) * (x1 - x4) || (x1 - x4) * (y2 - y1) == (y1 - y4) * (x2 - x1))
    {
        cout << "Le quadrilatère est un trapèze\n";
    }
    // If none of the above
    else
    {
        cout << "Le quadrilatère n'est aucune de ces formes\n";
    }
    return 0;
}