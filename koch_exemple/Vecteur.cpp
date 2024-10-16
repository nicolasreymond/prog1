// Fichier Vecteur.cpp: définition des fonctions déclarées dans Vecteur.hpp
// À compiler avec g++ -c Vecteur.cpp pour obtenir le fichier objet

#include "Vecteur.hpp"

Vecteur operator-(const Vecteur & v) {
  return {-v.x, -v.y};
}

Vecteur & operator+=(Vecteur & gauche, const Vecteur & droit) {
  gauche.x += droit.x; gauche.y += droit.y;
  return gauche;
}

Vecteur operator+(Vecteur gauche, const Vecteur & droit) {
  return gauche += droit;
}

Vecteur & operator-=(Vecteur & gauche, const Vecteur & droit) {
  return gauche += -droit;
}

Vecteur operator-(Vecteur gauche, const Vecteur & droit) {
  return gauche -= droit;
}

Vecteur operator/(const Vecteur & gauche, double facteur) {
  return {gauche.x/facteur, gauche.y/facteur};
}

Vecteur perpendiculaire(Vecteur v) {
  return {-v.y, v.x};
}
