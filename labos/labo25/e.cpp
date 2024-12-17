#include "Setbase.hpp"
#include "Unsigned.hpp"
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    cout << "\nTest des opérateurs de comparaison\n";
    Unsigned u(25), v{"1000"s};
    cout << (u < v) << endl;
    cout << (u > v) << endl;
    cout << (u <= v) << endl;
    cout << (u >= v) << endl;
    cout << (u == v) << endl;
    cout << (u != v) << endl;
    u = 8;
    cout << (u < v) << endl;
    cout << (u > v) << endl;
    cout << (u <= v) << endl;
    cout << (u >= v) << endl;
    cout << (u == v) << endl;
    cout << (u != v) << endl;
}