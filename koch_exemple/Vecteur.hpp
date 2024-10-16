// Illustration de la conception d'une bibliothèque élémentaire pour la gestion de Vecteurs euclidiens
// Fichier d'en-tête Vecteur.hpp

#pragma once // Prévenir les inclusions multiples
struct Vecteur {double x; double y;};

// Opérateurs arithmétiques
Vecteur operator-(const Vecteur & v);
Vecteur & operator+=(Vecteur & gauche, const Vecteur & droit);
Vecteur operator+(Vecteur gauche, const Vecteur & droit);
Vecteur & operator-=(Vecteur & gauche, const Vecteur & droit);
Vecteur operator-(Vecteur gauche, const Vecteur & droit);
Vecteur operator/(const Vecteur & gauche, double facteur);
// etc.

// Retourne un vecteur perpendiculaire à v, de même longueur
Vecteur perpendiculaire(Vecteur v);
