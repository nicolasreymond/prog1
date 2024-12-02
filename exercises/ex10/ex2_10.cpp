#include <iostream>
#include <vector>
#include <array>

using namespace std;

template <typename T, size_t taille>
using Ligne = array<T, taille>;

template <typename T, size_t nb_ligne, size_t nb_colonne>
using Matrice = array<Ligne<T, nb_colonne>, nb_ligne>;


template <typename T, size_t nb_ligne, size_t nb_colonne>
T somme1(const Matrice<T, nb_ligne, nb_colonne>& matrice){
    T resultat = T(); // Initialisation de la somme
    for(size_t i_ligne = 0; i_ligne < nb_ligne; ++i_ligne){ // Pour chaque ligne
        for(size_t i_colonne = 0; i_colonne < nb_colonne; ++i_colonne){ // Pour chaque colonne
            resultat += matrice[i_ligne][i_colonne]; // Ajouter l'élément à la somme
        }
    }
    return resultat;
}

template <typename T, size_t nb_ligne, size_t nb_colonne>
T somme2(const Matrice<T, nb_ligne, nb_colonne>& matrice){
    T resultat = T(); // Initialisation de la somme
    for(const auto& ligne : matrice){ // Pour chaque ligne
        for(const auto& element : ligne){ // Pour chaque élément de la ligne
            resultat += element; // Ajouter l'élément à la somme
        }
    }
    return resultat;
}

int main(){
    using Matrice_int_2x3 = Matrice<int, 2, 3>;
    using Matrice_double_3x2 = Matrice<double, 3, 2>;

    Matrice<int, 2, 3> matrice = {{{1, 2, 3}, {4, 5, 6}}};
    Matrice_int_2x3 m1{{{{0, 1, 2}},
                        {{10, 11, 12}}}};

    Matrice_double_3x2 m2{{{{0.0, 1.1}},
                           {{1.0, 1.1}},
                           {{2.0, 2.1}}}};
    cout << "Somme1: " << somme1(matrice) << endl;
    cout << "Somme2: " << somme2(matrice) << endl;

    cout << "Somme1: " << somme1(m1) << endl;
    cout << "Somme2: " << somme2(m1) << endl;

    cout << "Somme1: " << somme1(m2) << endl;
    cout << "Somme2: " << somme2(m2) << endl;

    return 0;
}