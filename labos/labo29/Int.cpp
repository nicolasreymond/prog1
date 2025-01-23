/**
 * @file Int.cpp
 * @brief Implementation of the Int class
 * @version 1.3
 * @date 23.01.2025
 * 
 */
#include "Int.hpp"

/**
 * @brief Constructor for the Int class
 * @param valeur Unsigned value
 * @param signe Boolean indicating if the value is negative
 */
Int::Int(Unsigned valeur, bool signe) : valeur(valeur), signe(signe) {}

/**
 * @brief Constructor for the Int class from an integer
 * @param valeur Integer value
 */
Int::Int(int valeur) : valeur(Unsigned(valeur < 0 ? -valeur : valeur)), signe(valeur < 0) {}

/**
 * @brief Unary negation operator
 * @return A new Int object with the sign inverted
 */
Int Int::operator-() const {
    return Int(valeur, !signe);
}

/**
 * @brief Addition and assignment operator
 * @param b Reference to the Int object to add
 * @return Reference to the modified Int object
 */
Int& Int::operator+=(const Int& b) {
    if (signe == b.signe) {
        valeur += b.valeur;
    } else {
        if (valeur < b.valeur) {
            valeur = b.valeur - valeur;
            signe = !signe;
        } else {
            valeur -= b.valeur;
        }
    }
    return *this;
}

/**
 * @brief Subtraction and assignment operator
 * @param b Reference to the Int object to subtract
 * @return Reference to the modified Int object
 */
Int& Int::operator-=(const Int& b) {
    if (signe != b.signe) {
        valeur += b.valeur;
    } else {
        if (valeur < b.valeur) {
            valeur = b.valeur - valeur;
            signe = !signe;
        } else {
            valeur -= b.valeur;
        }
    }
    return *this;
}

/**
 * @brief Multiplication and assignment operator
 * @param b Reference to the Int object to multiply
 * @return Reference to the modified Int object
 */
Int& Int::operator*=(const Int& b) {
    valeur *= b.valeur;
    signe = signe != b.signe;
    return *this;
}

/**
 * @brief Division and assignment operator
 * @param b Reference to the Int object to divide
 * @return Reference to the modified Int object
 */
Int& Int::operator/=(const Int& b) {
    valeur /= b.valeur;
    signe = signe != b.signe;
    return *this;
}

/**
 * @brief Modulo and assignment operator
 * @param b Reference to the Int object to divide
 * @return Reference to the modified Int object
 */
Int& Int::operator%=(const Int& b) {
    valeur %= b.valeur;
    if (valeur == Unsigned(0)) signe = false;
    else signe = signe != b.signe;
    return *this;
}

/**
 * @brief Addition operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return A new Int object resulting from the addition
 */
Int Int::operator+(const Int& b) const {
    Int copie = *this;
    copie += b;
    return copie;
}

/**
 * @brief Subtraction operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return A new Int object resulting from the subtraction
 */
Int Int::operator-(const Int& b) const {
    Int copie = *this;
    copie -= b;
    return copie;
}

/**
 * @brief Multiplication operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return A new Int object resulting from the multiplication
 */
Int Int::operator*(const Int& b) const {
    Int copie = *this;
    copie *= b;
    return copie;
}

/**
 * @brief Division operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return A new Int object resulting from the division
 */
Int Int::operator/(const Int& b) const {
    Int copie = *this;
    copie /= b;
    return copie;
}

/**
 * @brief Modulo operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return A new Int object resulting from the modulo
 */
Int Int::operator%(const Int& b) const {
    Int copie = *this;
    copie %= b;
    return copie;
}

/**
 * @brief Less than comparison operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return True if a is less than b, false otherwise
 */
bool Int::operator<(const Int& b) const {
    if (signe && not(b.signe)) return true;
    if (not(signe) && b.signe) return false;
    if (signe && b.signe) return valeur > b.valeur;
    return valeur < b.valeur;
}

/**
 * @brief Equality comparison operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return True if a is equal to b, false otherwise
 */
bool Int::operator==(const Int& b) const {
    return valeur == b.valeur && signe == b.signe;
}

/**
 * @brief Less than or equal to comparison operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return True if a is less than or equal to b, false otherwise
 */
bool Int::operator<=(const Int& b) const {
    return (*this < b || *this == b);
}

/**
 * @brief Greater than comparison operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return True if a is greater than b, false otherwise
 */
bool Int::operator>(const Int& b) const {
    return (not(*this < b) && *this != b);
}

/**
 * @brief Greater than or equal to comparison operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return True if a is greater than or equal to b, false otherwise
 */
bool Int::operator>=(const Int& b) const {
    return (not(*this < b));
}

/**
 * @brief Inequality comparison operator
 * @param a Reference to the first Int object
 * @param b Reference to the second Int object
 * @return True if a is not equal to b, false otherwise
 */
bool Int::operator!=(const Int& b) const {
    return (valeur != b.valeur || signe != b.signe);
}

/**
 * @brief Output stream operator
 * @param os Reference to the output stream
 * @param a Reference to the Int object to display
 * @return Reference to the output stream
 */
ostream& operator<<(ostream& os, const Int& a) {
    if (a.signe) os << '-';
    ios_base::fmtflags f(os.flags());
    if (f & ios_base::showpos) os << (a.signe ? "-" : "+");
    if (f & ios_base::hex) os << Setbase::set_base(16);
    else if (f & ios_base::oct) os << Setbase::set_base(8);
    else if (f & ios_base::dec) os << Setbase::set_base(10);
    else if (f & ios_base::binary) os << Setbase::set_base(2);
    os << a.valeur;
    return os;
}

/**
 * @brief Input stream operator
 * @param is Reference to the input stream
 * @param a Reference to the Int object to modify
 * @return Reference to the input stream
 */
istream& operator>>(istream& is, Int& a) {
    string str;
    getline(is, str);
    a = Int(stoi(str));
    return is;
}

/**
 * @brief Postfix increment operator
 * @param a Reference to the Int object to increment
 * @param int Dummy parameter to differentiate the postfix version
 * @return A copy of the Int object before the increment
 */
Int Int::operator++(int) {
    Int copie = *this;
    *this += Int(1);
    return copie;
}

/**
 * @brief Prefix increment operator
 * @param a Reference to the Int object to increment
 * @return Reference to the Int object after the increment
 */
Int& Int::operator++() {
    return *this += Int(1);
}

/**
 * @brief Postfix decrement operator
 * @param a Reference to the Int object to decrement
 * @param int Dummy parameter to differentiate the postfix version
 * @return A copy of the Int object before the decrement
 */
Int Int::operator--(int) {
    Int copie = *this;
    *this -= Int(1);
    return copie;
}

/**
 * @brief Prefix decrement operator
 * @param a Reference to the Int object to decrement
 * @return Reference to the Int object after the decrement
 */
Int& Int::operator--() {
    return *this -= Int(1);
}