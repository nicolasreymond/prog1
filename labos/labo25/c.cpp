#include "Setbase.hpp"
#include "Unsigned.hpp"
#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    cout << "\nTest constructeur string\n";
    Unsigned u("0"), v;
    cout << u.data() << endl;
    cout << v.data() << endl;
    v = "1000"s;
    cout << v.data() << endl;
    u = "0"s;
    cout << u.data() << endl;
    try
    {
        u = "10012001"s;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
    }
}