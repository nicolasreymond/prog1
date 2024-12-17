#ifndef UNSIGNED_HPP
#define UNSIGNED_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdint>

using namespace std;

/**
 * @class Unsigned
 * @brief Représente un entier non signé de taille arbitraire.
 *
 * Cette classe permet de manipuler des nombres non signés plus grands que ce
 * que les types intégrés supportent, avec des fonctionnalités pour les
 * conversions de base et les opérations arithmétiques.
 */
class Unsigned
{
private:
    /**
     * @brief Représentation interne de l'entier sous forme de chaîne de caractères.
     */
    string value;

public:
    // === Constructeurs ===

    /**
     * @brief Constructeur par défaut. Initialise l'objet à 0.
     */
    Unsigned();

    /**
     * @brief Constructeur à partir d'une chaîne représentant un entier.
     * @param binary Représentation en chaîne de l'entier (binaire ou autre base).
     * @throw invalid_argument Si la chaîne contient des caractères invalides.
     */
    Unsigned(const string &binary);

    /**
     * @brief Constructeur à partir d'un entier non signé natif.
     * @param number Entier non signé.
     */
    Unsigned(uint64_t number);

    // === Méthodes publiques ===

    /**
     * @brief Convertit l'entier dans une base donnée.
     * @param base La base cible (entre 2 et 36).
     * @return Une chaîne représentant l'entier dans la base donnée.
     * @throw invalid_argument Si la base est en dehors de l'intervalle [2, 36].
     */
    string to_base(int base) const;

    /**
     * @brief Convertit l'objet `Unsigned` en `uint64_t`.
     * @return La valeur de l'objet en `uint64_t`.
     */

    uint64_t to_uint64() const;

    /**
     * @brief Retourne la représentation interne de l'entier.
     * @return La valeur en tant que chaîne de caractères.
     */
    string data() const;

    // Conversion operator to uint64_t
    operator uint64_t() const;

    pair<Unsigned, Unsigned> divmod(const Unsigned &a, const Unsigned &b);

    // === Opérateurs d'affectation arithmétiques ===

    Unsigned &operator+=(const Unsigned &right);
    Unsigned &operator-=(const Unsigned &right);
    Unsigned &operator*=(const Unsigned &right);
    Unsigned &operator/=(const Unsigned &right);
    Unsigned &operator%=(const Unsigned &right);

    // === Opérateurs de comparaison ===

    bool operator<(const Unsigned &right) const;
    bool operator<=(const Unsigned &right) const;
    bool operator>(const Unsigned &right) const;
    bool operator>=(const Unsigned &right) const;
    bool operator==(const Unsigned &right) const;
    bool operator!=(const Unsigned &right) const;

    // === Opérateurs arithmétiques amis ===

    friend Unsigned operator+(Unsigned left, const Unsigned &right);
    friend Unsigned operator-(Unsigned left, const Unsigned &right);
    friend Unsigned operator*(Unsigned left, const Unsigned &right);
    friend Unsigned operator/(Unsigned left, const Unsigned &right);
    friend Unsigned operator%(Unsigned left, const Unsigned &right);

    // === Opérateurs de flux ===

    /**
     * @brief Surcharge de l'opérateur << pour afficher un entier `Unsigned`.
     * @param os Flux de sortie.
     * @param number Entier à afficher.
     * @return Le flux de sortie.
     */
    friend ostream &operator<<(ostream &os, const Unsigned &number);

    // === Opérateurs d'incrémentation et de décrémentation ===

    /**
     * @brief Pré-incrémentation (++obj).
     * @return Référence à l'objet incrémenté.
     */
    Unsigned &operator++();

    /**
     * @brief Post-incrémentation (obj++).
     * @return Une copie de l'objet avant incrémentation.
     */
    Unsigned operator++(int);

    /**
     * @brief Pré-décrémentation (--obj).
     * @return Référence à l'objet décrémenté.
     */
    Unsigned &operator--();

    /**
     * @brief Post-décrémentation (obj--).
     * @return Une copie de l'objet avant décrémentation.
     */
    Unsigned operator--(int);
};

Unsigned::Unsigned() : value("0") {}

Unsigned::Unsigned(const string &binary) {
    // Validate and initialize from string
    for (char c : binary) {
        if (!isdigit(c)) {
            throw invalid_argument("Invalid character in string");
        }
    }
    value = binary;
}

Unsigned::Unsigned(uint64_t number) {
    value = to_string(number);
}

string Unsigned::to_base(int base) const {
    if (base < 2 || base > 36) {
        throw invalid_argument("Base must be between 2 and 36");
    }
    // Conversion logic here
    return ""; // Placeholder
}

uint64_t Unsigned::to_uint64() const {
    return stoull(value);
}

string Unsigned::data() const {
    return value;
}

Unsigned::operator uint64_t() const {
    return to_uint64();
}

pair<Unsigned, Unsigned> Unsigned::divmod(const Unsigned &a, const Unsigned &b) {
    // Division and modulo logic here
    return {Unsigned(0), Unsigned(0)}; // Placeholder
}

Unsigned &Unsigned::operator+=(const Unsigned &right) {
    // Addition logic here
    return *this;
}

Unsigned &Unsigned::operator-=(const Unsigned &right) {
    // Subtraction logic here
    return *this;
}

Unsigned &Unsigned::operator*=(const Unsigned &right) {
    // Multiplication logic here
    return *this;
}

Unsigned &Unsigned::operator/=(const Unsigned &right) {
    // Division logic here
    return *this;
}

Unsigned &Unsigned::operator%=(const Unsigned &right) {
    // Modulo logic here
    return *this;
}

bool Unsigned::operator<(const Unsigned &right) const {
    return value < right.value;
}

bool Unsigned::operator<=(const Unsigned &right) const {
    return value <= right.value;
}

bool Unsigned::operator>(const Unsigned &right) const {
    return value > right.value;
}

bool Unsigned::operator>=(const Unsigned &right) const {
    return value >= right.value;
}

bool Unsigned::operator==(const Unsigned &right) const {
    return value == right.value;
}

bool Unsigned::operator!=(const Unsigned &right) const {
    return value != right.value;
}

Unsigned operator+(Unsigned left, const Unsigned &right) {
    left += right;
    return left;
}

Unsigned operator-(Unsigned left, const Unsigned &right) {
    left -= right;
    return left;
}

Unsigned operator*(Unsigned left, const Unsigned &right) {
    left *= right;
    return left;
}

Unsigned operator/(Unsigned left, const Unsigned &right) {
    left /= right;
    return left;
}

Unsigned operator%(Unsigned left, const Unsigned &right) {
    left %= right;
    return left;
}

ostream &operator<<(ostream &os, const Unsigned &number) {
    os << number.value;
    return os;
}

Unsigned &Unsigned::operator++() {
    // Pre-increment logic here
    return *this;
}

Unsigned Unsigned::operator++(int) {
    Unsigned temp = *this;
    ++(*this);
    return temp;
}

Unsigned &Unsigned::operator--() {
    // Pre-decrement logic here
    return *this;
}

Unsigned Unsigned::operator--(int) {
    Unsigned temp = *this;
    --(*this);
    return temp;
}

#endif
