#include "Setbase.hpp"
#include "Unsigned.hpp"
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    cout << "Test de l'addition avec la suite de Fibonacci\n";
    Unsigned u = 0, v = 1;
    size_t a = 0, b = 1;
    for (size_t i = 2; i < 10; ++i)
    {
        u += v;
        cout << u.data() << endl;
        swap(u, v);
        a += b;
        cout << hex << a << endl;
        swap(a, b);
    }

    cout << "\nTest de la soustraction (suite de Fibonacci à l'envers)\n";
    for (size_t i = 2; i < 10; ++i)
    {
        v -= u;
        cout << u.data() << endl;
        swap(u, v);
    }
}