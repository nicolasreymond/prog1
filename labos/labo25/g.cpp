#include "Setbase.hpp"
#include "Unsigned.hpp"
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    cout << "\nTest de la multiplication avec la factorielle\n";
    Unsigned u, v;
    v = u = 1;
    for (size_t i = 2; i < 40; ++i)
    {
        v *= u++;
        cout << v.data() << endl;
    }

    cout << "\nTest de la division, du reste et de l'affichage\n";
    try
    {
        for (size_t i = 40; i > 0; --i)
        {
            v = v / --u;
            cout << Setbase::set_base(i) << v << endl;
        }
    }
    catch (runtime_error &e)
    {
        cerr << e.what() << endl;
    }
    try
    {
        u--;
    }
    catch (range_error &e)
    {
        cerr << e.what() << endl;
    }
}