/**
 * @file Reymond_labo29.cpp
 * @brief Main file for the labo29 
 * @version 1.2
 * @date 23.01.2025
 * 
 */

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
using Rat = Rationnel<Int>;

/**
 * @brief Pivot the matrix and resolve the system of linear equations.
 * 
 * @tparam T Type of the matrix elements
 * @param matrix Matrix to pivot
 * @param ligne Row of the pivot
 * @param colonne Column of the pivot
 */
template <typename T>
void pivote(vector<vector<T>>& matrix, size_t ligne, size_t colonne) {
    size_t nb_lignes = matrix.size();
    size_t nb_colonnes = matrix[0].size();

    for (size_t i = 0; i < nb_lignes; i++) {
        if (i != ligne) {
            for (size_t j = 0; j < nb_colonnes; j++) {
                if (j != colonne) {
                    matrix[i][j] = matrix[i][j] - matrix[i][colonne] * matrix[ligne][j] / matrix[ligne][colonne];
                }
            }
        }
    }

    for (size_t i = 0; i < nb_lignes; i++) {
        if (i != ligne) {
            matrix[i][colonne] = -matrix[i][colonne] / matrix[ligne][colonne];
        }
    }

    for (size_t j = 0; j < nb_colonnes; j++) {
        if (j != colonne) {
            matrix[ligne][j] = matrix[ligne][j] / matrix[ligne][colonne];
        }
    }

    matrix[ligne][colonne] = T(1) / matrix[ligne][colonne];
}

/**
 * @brief Read the matrix from the given file
 * 
 * @param nomFichier File containing the matrix
 * @return vector<vector<Rat>> Matrix read from the file
 */
template <typename T>
vector<vector<T>> readMatrix(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw runtime_error("Impossible to open the file!");
    }

    vector<vector<T>> matrice;
    string ligne;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        istringstream iss(ligne);
        vector<T> ligne_matrice;
        string valeur;
        while (getline(iss, valeur, ' ')) {
            if (valeur.empty()) continue;
            T temp(stoi(valeur));
            ligne_matrice.push_back(temp);
        }
        matrice.push_back(ligne_matrice);
    }
    fichier.close();
    return matrice;
}

/**
 * @brief Determine the order of pivots to perform
 * 
 * @param matrix Matrix to solve
 * @return vector<size_t> Order of pivots
 */
template <typename T>
vector<size_t> definePivots(const vector<vector<T>>& matrice) {
    size_t nb_lignes = matrice.size();
    vector<size_t> pivots;
    pivots.push_back(0);

    for (size_t i = 1; i < nb_lignes; i++) {
        size_t dernierPivot = pivots.back();
        if (matrice[i][i].abs() > matrice[dernierPivot][dernierPivot].abs()) {
            for (auto it = pivots.begin(); it != pivots.end(); it++) {
                if (matrice[i][i].abs() > matrice[*it][*it].abs()) {
                    pivots.insert(it, i);
                    break;
                }
            }
        } else {
            pivots.push_back(i);
        }
    }
    return pivots;
}

/**
 * @brief Solve the system of linear equations
 * 
 * @param matrix Matrix to solve
 */
template <typename T>
void solveSystem(vector<vector<T>>& matrix) {
    size_t nb_lignes = matrix.size();
    size_t nb_colonnes = matrix[0].size();

    for (size_t i = 0; i < nb_lignes; ++i) {
        size_t pivot_row = i;
        for (size_t j = i + 1; j < nb_lignes; ++j) {
            if (matrix[j][i].abs() > matrix[pivot_row][i].abs()) {
                pivot_row = j;
            }
        }

        if (pivot_row != i) {
            swap(matrix[i], matrix[pivot_row]);
        }

        if (matrix[i][i] == T(0)) {
            throw runtime_error("Matrix is singular and cannot be solved.");
        }

        pivote(matrix, i, i);
    }
}

/**
 * @brief Display the solution of the system
 * 
 * @param matrice Solved matrix
 */
template <typename T>
void displaySolution(const vector<vector<T>>& matrice) {
    for (size_t i = 0; i < matrice.size(); ++i) {
        cout << "x" << i << " = " << setprecision(3) << fixed << matrice[i].back() << endl;
    }
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
    const int largeur_colonne = 5;
    const int precision = 3;

    for (const vector<T>& ligne : matrice) {
        os << "│";
        for (size_t i = 0; i < ligne.size(); ++i) {
            if (i == ligne.size() - 1) {
                os << " │";
            }
            os << setw(largeur_colonne) << fixed << setprecision(precision) << ligne[i] << " ";
        }
        os << " │" << endl;
    }
    return os;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file>" << endl;
        return 1;
    }

    string nomFichier = argv[1];
    try {
        vector<vector<Rat>> t2 = readMatrix<Rat>(nomFichier);
        cout << "Matrix read: " << endl << t2 << endl;
        solveSystem(t2);
        displaySolution(t2);
    } catch (const ifstream::failure& e) {
        cerr << "File error: " << e.what() << endl;
        return 1;
    } catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
