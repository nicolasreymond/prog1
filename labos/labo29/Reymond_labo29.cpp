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
 * @brief Pivot the matrix t at the given row and column
 * 
 * @tparam T Type of the matrix elements
 * @param t Matrix to pivot
 * @param ligne Row of the pivot
 * @param colonne Column of the pivot
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
 * @brief Overload the << operator to display a matrix
 * 
 * @tparam T Type of the matrix elements
 * @param os Output stream
 * @param matrice Matrix to display
 * @return ostream& 
 */
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& matrice) {
    const int largeur_colonne = 5; // Width of each column
    const int precision = 3;       // Number of digits after the decimal point

    for (const vector<T>& ligne : matrice) {
        os << "│";
        for (size_t i = 0; i < ligne.size(); ++i) {
            if (i == ligne.size() - 1) {
                os << " │"; // Separate the last column
            }
            os << setw(largeur_colonne) << fixed << setprecision(precision) << ligne[i] << " ";
        }
        os << " │" << endl;
    }
    return os;
}

/**
 * @brief Read the matrix from the given file
 * 
 * @param nomFichier File containing the matrix
 * @return vector<vector<Rat>> Matrix read from the file
 */
vector<vector<Rat>> readMatrix(string nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw runtime_error("Impossible to open the file!");
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
 * @brief Determine the order of pivots to perform
 * 
 * @param matrice Matrix to solve
 * @return vector<size_t> Order of pivots
 */
vector<size_t> definePivots(const vector<vector<Rat>>& matrice) {
    size_t nb_lignes = matrice.size();
    vector<size_t> pivots;
    pivots.push_back(0); // Start by inserting the first pivot (index 0)
    for (size_t i = 1; i < nb_lignes; i++) {
        size_t dernierPivot = pivots.back();
        if (matrice[i][i].abs() > matrice[dernierPivot][dernierPivot].abs()) { // If the pivot is larger than the last pivot
            for (auto it = pivots.begin(); it != pivots.end(); it++) { // Find where to insert the pivot
                if (matrice[i][i].abs() > matrice[(*it)][(*it)].abs()) {
                    pivots.insert(it, i); // Insert it
                    break;
                }
            }
        } else pivots.push_back(i); // Otherwise, add it to the end
    }
    return pivots;
}

/**
 * @brief Solve the system of linear equations
 * 
 * @param matrice Matrix to solve
 */
void solveSystem(vector<vector<Rat>>& matrice) {
    vector<size_t> pivots = definePivots(matrice);
    while (!pivots.empty()) {
        for (auto it = pivots.begin(); it != pivots.end(); it++) {
            if (matrice[*it][*it] == Rat(0)) continue;
            pivote(matrice, *it, *it);
            pivots.erase(it);
            break; // Ensure we only erase one pivot at a time
        }
    }
}

/**
 * @brief Display the solution of the system
 * 
 * @param matrice Solved matrix
 */
void displaySolution(const vector<vector<Rat>>& matrice) {
    for (const auto& row : matrice) {
        cout << "x" << &row - &matrice[0] << " = " << setprecision(3) << fixed << row.back() << endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file>" << endl;
        return 1;
    }
    string nomFichier = argv[1];
    try {
        vector<vector<Rat>> t2 = readMatrix(nomFichier);
        cout << "Matrix read: " << endl << t2 << endl;
        solveSystem(t2);
        displaySolution(t2);
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}