// von_koch.cpp: exemple d'utilisation de la bibliothèque Vecteur: dessin d'une courbe de Koch
// À compiler avec g++ Vecteur.o von_Koch.cpp

#include <iostream>
#include "Vecteur.hpp"
using namespace std;

// Dessin d'une courbe de von Koch de depart à arrivee
void von_koch(const Vecteur & depart, const Vecteur & arrivee, int niveau) {
  if (niveau == 0) 
    cout << arrivee.x << ' ' << arrivee.y // On dessine directement le tronçon
         << " lineto ";
  else { // Décomposer le tronçon en 4 parties: depart-a-b-c-arrivee
    Vecteur delta = arrivee - depart, 
            a = depart + delta/3,
            b = depart + delta/2 + perpendiculaire(delta/3),
            c = arrivee - delta/3;
    // Dessiner les 4 sous-tronçons
    von_koch(depart, a, niveau-1);
    von_koch(a, b, niveau-1);
    von_koch(b, c, niveau-1);
    von_koch(c, arrivee, niveau-1);
  }     
}  

int main() {
  cout << "%%!PostScript2.0\n";  // Informe l'utilitaire qu'il s'agit d'un fichier Postscript
  Vecteur depart = {100, 200}, arrivee = {500, 700};
  cout << "newpath " << depart.x << ' ' << depart.y << " moveto "; // Se déplacer au début
  von_koch(depart, arrivee, 4); // Construire une courbe de niveau 4
  cout << "stroke\nshowpage\n"; // Dessiner la courbe et afficher la page
}
