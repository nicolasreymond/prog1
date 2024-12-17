#ifndef SETBASE_HPP
#define SETBASE_HPP

#include <iostream> // Nécessaire pour `ostream`
using namespace std;

/**
 * @class Setbase
 * @brief Classe pour gérer les bases numériques (ex : binaire, décimal, hexadécimal).
 */
class Setbase
{
public:
    static int base; // Variable statique pour la base actuelle

    /**
     * @brief Constructeur. Initialise la base.
     * @param b La base à définir.
     */
    Setbase(int b);

    /**
     * @brief Définit une nouvelle base.
     * @param b La base à définir.
     * @return Un objet `Setbase` avec la base définie.
     */
    static Setbase set_base(int b);

    /**
     * @brief Surcharge de l'opérateur `<<` pour afficher la base.
     * @param os Flux de sortie.
     * @param sb Objet `Setbase` à afficher.
     * @return Le flux de sortie.
     */
    friend ostream &operator<<(ostream &os, const Setbase &sb);
};

#endif // SETBASE_HPP
