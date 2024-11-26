#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void comb_sort(T start, T end)
{
    const double shrink = 1.3; // Best value found in previous lab
    size_t gap = distance(start, end);
    bool sorted = false;

    while (gap > 1 || !sorted)
    {
        if (gap > 1)
        {
            gap = static_cast<size_t>(gap / shrink);
        }

        sorted = true;
        for (T i = start; i + gap < end; ++i)
        {
            if (*(i + gap) < *i)
            {
                swap(*(i + gap), *i);
                sorted = false;
            }
        }
    }
}

/**
 * @brief Surcharge de l'opérateur "<<" pour le vecteur d'entiers
 *
 * @param stream flux de sortie
 * @param v vecteur d'entier
 * @return ostream&
 */
ostream &operator<<(ostream &stream, const vector<int> &v)
{
    for (const int &e : v)
        stream << e << " ";
    return stream;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    cout << "algorithme,nbElements,nbComparaisons" << endl;
    for (int i = 100; i <= 100000; i *= 2)
    {
        vector<int> liste;
        for (int j = 0; j < i; j++)
        {
            liste.push_back(rand());
        }
        vector<int> v = liste;
        cout << "combo," << i << ",";
        comb_sort(v.begin(), v.end());
        cout << endl;
    }
    return 0;
}
