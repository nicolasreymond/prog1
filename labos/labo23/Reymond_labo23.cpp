#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


template <typename T>
void pivot(vector<vector<T>>& t, size_t ligne, size_t colonne){
    size_t nb_lignes = t.size();
    size_t nb_colonnes = t[0].size();

    for (size_t i = 0; i < nb_lignes; i++)
        if (i != ligne)
            for (size_t j = 0; j < nb_colonnes; j++)
                if (j != colonne)
                    t[i][j] = t[i][j] - t[i][colonne] * t[ligne][j] / t[ligne][colonne];

    for (size_t i = 0; i < nb_lignes; i++)
        if (i != ligne)
            t[i][colonne] = -t[i][colonne] / t[ligne][colonne];

    for (size_t j = 0; j < nb_colonnes; j++)
        if (j != colonne)
            t[ligne][j] = t[ligne][j] / t[ligne][colonne];

    t[ligne][colonne] = 1.0 / t[ligne][colonne];
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& ligne){
    for (const T& val : ligne)
        os << scientific << val << " ";
    os << endl;
    return os;
}


int main(void){
    vector<vector<long double>> t2 = {
        {84, 91, 45, 73, 54, 43, 390},
        {84, 76, 39, 22, 36, 94, 351},
        {42, 99, 2,  92, 79, 80, 394},
        {48, 14, 72, 98, 63, 75, 370},
        {71, 85, 87, 10, 80, 47, 380},
        {65, 64, 36, 8,  38, 90, 301}
    };

    size_t nb_lignes = t2.size();
    size_t nb_colonnes = t2[0].size();

    /* Pivotages; arrêter le programme avec CTRL-C */
    while (1)    {
        cout << t2;
        cout << "ligne et colonne du pivot\n";
        size_t i, j;
        cin >> i >> j;
        if (i < nb_lignes and j < nb_colonnes and t2[i][j] != 0.0)
            pivot(t2, i, j);
        else
            cout << "pivot non valide!\n";
    }
}
