/* Transformation en pouces et pieds d’une longueur exprimée en mètres*/
#include <iostream>

using namespace std;

const int pouces_par_pied = 12;
const double metre_par_pouce = 0.0254;

int main()
{
  double longueur; // Longueur entrée par l'utilisateur
  cout << "Longueur en metres a transformer en pieds et pouces: " << endl;
  cin >> longueur;
  
  // arrondir la longueur en pouces uniquement
  int pouces = int(longueur/metre_par_pouce + 0.5);
  
  // calculer le nombre de pieds 
  int pieds = pouces/pouces_par_pied;
  
  // soustraire les pieds aux pouces 
  pouces = pouces % pouces_par_pied;
  
  // Afficher le résultat 
  cout << pieds << " pieds et " 
       << pouces << " pouces " << "font " 
       << (pieds*pouces_par_pied + pouces)*metre_par_pouce << " metres"
       << endl;
}
