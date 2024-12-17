#include "Setbase.hpp"

// Initialisation de la variable statique
int Setbase::base = 10;

/**
 * @brief Constructeur : initialise la base.
 */
Setbase::Setbase(int b)
{
    set_base(b);
}

/**
 * @brief Définit une nouvelle base (entre 2 et 36).
 */
Setbase Setbase::set_base(int b)
{
    if (b < 2 || b > 36)
    {              // Validation de la base
        base = 10; // Base par défaut : décimale
    }
    else
    {
        base = b;
    }
    return Setbase(base);
}

/**
 * @brief Surcharge de l'opérateur `<<`.
 */
ostream &operator<<(ostream &os, const Setbase &sb)
{
    os << "Current base: " << Setbase::base;
    return os;
}
