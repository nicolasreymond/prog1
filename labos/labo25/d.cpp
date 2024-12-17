#include "Setbase.hpp"
#include "Unsigned.hpp"
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    cout << "\nTest constructeur (implicite), += et convertisseur de type\n";
    Unsigned u(6);
    for (size_t i = 0; i < 19; ++i)
    {
        u += 1; //
        cout << u.data() << endl;
        cout << uint64_t(u) << endl;
    }
}