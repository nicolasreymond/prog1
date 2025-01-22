#include "Int.hpp"
#include "Rational.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <exception>
#include <numeric>
#include <algorithm>

using namespace std;
// using Int = long long int;
using Rat = Rationnel<Int>;
// using Rat = long double;

/**
 * @brief pivote la matrice t à la ligne et colonne donnée
 * 
 * @tparam T Type des éléments de la matrice
 * @param t matrice à pivoter
 * @param ligne
 * @param colonne 
 */
template <typename T>
void pivote(vector<vector<T>>& t, size_t ligne, size_t colonne) {
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

    t[ligne][colonne] = Rat(1) / t[ligne][colonne];
}

/**
 * @brief Surcharge de l'opérateur << pour afficher une matrice
 * 
 * @tparam T Type des éléments de la matrice
 * @param os Flux de sortie
 * @param matrice matrice à afficher
 * @return ostream& 
 */
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& matrice) {
    for (const vector<T>& ligne : matrice) {
        for (const T& val : ligne)
            os << scientific << val << " ";
        os << endl;
    }
    return os;
}

/**
 * @brief Lit la matrice depuis le fichier donné en paramètre
 * 
 * @param nomFichier fichier contenant la matrice
 * @return vector<vector<Rat>> matrice lue
 */
vector<vector<Rat>> lireMatrice(string nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier !");
    }
    vector<vector<Rat>> matrice;
    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        istringstream iss(ligne);
        vector<Rat> ligne_matrice;
        string valeur;
        while (getline(iss, valeur, ' ')) {
            if (valeur == "") continue;
            Int temp(stoi(valeur));
            ligne_matrice.push_back(Rat(temp));
        }
        matrice.push_back(ligne_matrice);
    }
    fichier.close();
    return matrice;
}

/**
 * @brief Détermine l'ordre des pivots à effectuer
 * 
 * @param matrice Matrice à résoudre
 * @return vector<size_t> 
 */
vector<size_t> definirPivots(const vector<vector<Rat>>& matrice) {
    size_t nb_lignes = matrice.size();
    vector<size_t> pivots;
    pivots.push_back(0); // On commence par insérer le premier pivot (indice 0)
    for (size_t i = 1; i < nb_lignes; i++) {
        size_t dernierPivot = pivots.back();
        if (matrice[i][i].abs() > matrice[dernierPivot][dernierPivot].abs()) { // Si le pivot est plus grand que le dernier pivot
            for (auto it = pivots.begin(); it != pivots.end(); it++) { // On cherche où insérer le pivot
                if (matrice[i][i].abs() > matrice[(*it)][(*it)].abs()) {
                    pivots.insert(it, i); // On l'insère 
                    break;
                }
            }
        } else pivots.push_back(i); // Sinon on l'ajoute à la fin
    }
    return pivots;
}

/**
 * @brief Résoud le système d'équations linéaires
 * 
 * @param matrice Matrice à résoudre
 */
void resoudreSysteme(vector<vector<Rat>>& matrice) {
    vector<size_t> pivots = definirPivots(matrice);
    while (!pivots.empty()) {
        for (auto it = pivots.begin(); it != pivots.end(); it++) {
            if (matrice[*it][*it] == Rat(0)) continue;
            pivote(matrice, *it, *it);
            pivots.erase(it);
            break; // Ensure we only erase one pivot at a time
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <fichier>" << endl;
        return 1;
    }
    string nomFichier = argv[1];
    try {
        vector<vector<Rat>> t2 = lireMatrice(nomFichier);
        cout << "Matrice lue: " << endl << t2 << endl;
        resoudreSysteme(t2);
        cout << t2;
    } catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}