/********************************************************************
Programme de pivotage pour systèmes avec 3 lignes et 4 colonnes
Permet de résoudre des systèmes de 3 équations à 3 inconnues.
Par exemple, pour résoudre le système:
  x +  y + z =  6
 2x - 3y + z = -5
 3x + 2y - z =  7
On introduit la matrice
 1  1  1  6
 2 -3  1 -5
 3  2 -1  7
et on pivote une fois dans chaque ligne et chaque colonne:
 0 0
 1 1
 2 2
La matrice transformée devrait être:
5.263158e-002 1.578947e-001 2.105263e-001 1.000000e+000
2.631579e-001 -2.105263e-001 5.263158e-002 3.000000e+000
6.842105e-001 5.263158e-002 -2.631579e-001 2.000000e+000
La dernière colonne donne la solution: x = 1, y = 3 et z = 2.
******************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;
const size_t nb_colonnes = 4; /* Nombre de colonne du système, y compris second membre*/
const size_t nb_lignes = 3;   /* Nombre de lignes du système d'équations */

void imprime_ligne(const double ligne[])
{ 
  for (size_t j = 0; j < nb_colonnes; j++)
    cout << scientific << ligne[j] << " ";
  cout << endl;
}

void imprime_matrice(const double t[nb_lignes][nb_colonnes])
{ 
  cout << "----------------------" << endl;
  for (size_t i = 0; i < nb_lignes; i++)
    imprime_ligne(t[i]);
  cout << endl;
}


/*Opération de pivotage */
void pivote(double t[nb_lignes][nb_colonnes], 
            size_t ligne, size_t colonne)
{ 
  for (size_t i = 0; i < nb_lignes; i++) if (i != ligne)
    for (size_t j = 0; j < nb_colonnes; j++) if (j != colonne)
      t[i][j] = t[i][j]-t[i][colonne]* t[ligne][j]/ t[ligne][colonne];
    
  for (size_t i = 0; i < nb_lignes; i++) if (i != ligne)
    t[i][colonne] = -t[i][colonne] / t[ligne][colonne];

  for (size_t j = 0; j < nb_colonnes; j++) if (j != colonne)
    t[ligne][j] = t[ligne][j] / t[ligne][colonne];

  t[ligne][colonne] = 1.0/t[ligne][colonne];
}


int main(void)
{
  double t[nb_lignes][nb_colonnes];

  /* Lecture des éléments de la matrice + vecteur */
  for (size_t i = 0; i < nb_lignes; i++)
    for (size_t j = 0; j < nb_colonnes; j++)
    { cout << "Introduire l'element de la ligne " << i 
           << " et de la colonne " << j << endl;
      cin >> t[i][j];
    }

  /* Pivotages; arrêter le programme avec CTRL-C */
  while(1)
  {
    imprime_matrice(t);
    cout << "ligne et colonne du pivot\n";
    size_t i, j;
    cin >> i >> j;
    if (i < nb_lignes and j < nb_colonnes and t[i][j] != 0.0)
      pivote(t, i, j);
    else
      cout << "pivot non valide!\n";
  }
}




