// Illustration de la conception d'une bibliothèque élémentaire pour le calcul sur les rationnels
// Fichier d'en-tête Rationnel.hpp

#pragma once // Prévenir les inclusions multiples

struct Rationnel{int num; int den;};
Rationnel simplifier(Rationnel r);

// Opérateurs arithmétiques
Rationnel operator-(const Rationnel & r);
Rationnel & operator+=(Rationnel & gauche, const Rationnel & droit);
Rationnel operator+(Rationnel gauche, const Rationnel & droit);
Rationnel & operator-=(Rationnel & gauche, const Rationnel & droit);
Rationnel operator-(Rationnel gauche, const Rationnel & droit);
Rationnel operator/(const Rationnel & gauche, int facteur);
Rationnel operator*(const Rationnel & gauche, const Rationnel & droit);
Rationnel operator<(const Rationnel & gauche, const Rationnel & droit);
Rationnel operator>(const Rationnel & gauche, const Rationnel & droit);
Rationnel operator==(const Rationnel & gauche, const Rationnel & droit);
Rationnel operator!=(const Rationnel & gauche, const Rationnel & droit);
std::ostream &operator<<(std::ostream &os, const Rationnel &r);