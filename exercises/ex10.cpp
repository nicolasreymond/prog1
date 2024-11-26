/**
 * @file tri_generique.cpp
 * @author Nolan Evard (nolan.evard@heig-vd.ch)
 * @brief
 * @version 0.1
 * @date 21.11.2024
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <vector>
#include <array>

using namespace std;

template <typename T>

void tri_generique(T &a)
{
    int n = a.size();
    for (int i = 0; i < n - 2; i++)
    {
        int min = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            swap(a[i], a[min]);
    }
}

int main()
{

    vector v{6, 2, 8, 7, 1, 3};
    array a{"chien"s, "chat"s, "souris"s, "poisson"s};
    double t[] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};

    cout << "v = ";
    for (auto e : v)
    {
        cout << e << " ";
    }
    tri_generique(v);

    cout << endl
         << "v = ";
    for (auto e : v)
    {
        cout << e << " ";
    }

    cout << endl
         << "a = ";
    for (auto e : a)
    {
        cout << e << " ";
    }
    tri_generique(a);
    cout << endl
         << "a = ";
    for (auto e : a)
    {
        cout << e << " ";
    }
    cout << endl
         << "t = ";
    for (auto e : t)
    {
        cout << e << " ";
    }
    // tri_generique(t);
    // cout << endl
    //      << "t = ";
    // for (auto e : t)
    // {
    //     cout << e << " ";
    // }

    return 0;
}