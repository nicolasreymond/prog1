/**
 * @file nicolas_reymond_labo26.cpp
 * @author Nicolas Reymond (nolan.evard@bluewin.ch)
 * @brief Labo sur les classes et la manipulation d'entiers signés
 * @version 0.1
 * @date 17.12.2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Int.hpp"

/**
 * @brief Constructeur de la classe Int
 * @param valeur Valeur non signée
 * @param signe Booléen indiquant si la valeur est négative
 */
Int::Int(Unsigned valeur, bool signe) : valeur(valeur), signe(signe) {}

/**
 * @brief Constructeur de la classe Int à partir d'un entier
 * @param valeur Valeur entière
 */
Int::Int(int valeur) : valeur(Unsigned(valeur < 0 ? -valeur : valeur)), signe(valeur < 0) {}

/**
 * @brief Opérateur unaire de négation
 * @return Un nouvel objet Int avec le signe inversé
 */
Int Int::operator-() const{
    return Int(valeur, !signe);
}

/**
 * @brief Opérateur d'addition et d'affectation
 * @param b Référence sur l'objet Int à ajouter
 * @return Référence sur l'objet Int modifié
 */
Int& Int::operator+=(const Int& b){
    if(signe == b.signe) {
        valeur += b.valeur;
    } else {
        if(valeur < b.valeur) {
            valeur = b.valeur - valeur;
            signe = !signe;
        } else {
            valeur -= b.valeur;
        }
    }
    return *this;
}

/**
 * @brief Opérateur de soustraction et d'affectation
 * @param b Référence sur l'objet Int à soustraire
 * @return Référence sur l'objet Int modifié
 */
Int& Int::operator-=(const Int& b){
    if(signe != b.signe) {
        valeur += b.valeur;
    } else {
        if(valeur < b.valeur) {
            valeur = b.valeur - valeur;
            signe = !signe;
        } else {
            valeur -= b.valeur;
        }
    }
    return *this;
}

/**
 * @brief Opérateur de multiplication et d'affectation
 * @param b Référence sur l'objet Int à multiplier
 * @return Référence sur l'objet Int modifié
 */
Int& Int::operator*=(const Int& b){
    valeur *= b.valeur;
    signe = signe != b.signe;
    return *this;
}

/**
 * @brief Opérateur de division et d'affectation
 * @param b Référence sur l'objet Int à diviser
 * @return Référence sur l'objet Int modifié
 */
Int& Int::operator/=(const Int& b){
    valeur /= b.valeur;
    signe = signe != b.signe;
    return *this;
}

/**
 * @brief Opérateur de modulo et d'affectation
 * @param b Référence sur l'objet Int à diviser
 * @return Référence sur l'objet Int modifié
 */
Int& Int::operator%=(const Int& b){
    valeur %= b.valeur;
    if(valeur == Unsigned(0)) signe = false;
    else signe = signe != b.signe;
    return *this;
}

/**
 * @brief Opérateur d'addition
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Un nouvel objet Int résultant de l'addition
 */
Int Int::operator+(const Int& b)const{
    Int copie = *this;
    copie += b;
    return copie;
}

/**
 * @brief Opérateur de soustraction
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Un nouvel objet Int résultant de la soustraction
 */
Int Int::operator-(const Int& b)const{
    Int copie = *this;
    copie -= b;
    return copie;
}

/**
 * @brief Opérateur de multiplication
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Un nouvel objet Int résultant de la multiplication
 */
Int Int::operator*(const Int& b)const{
    Int copie = *this;
    copie *= b;
    return copie;
}

/**
 * @brief Opérateur de division
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Un nouvel objet Int résultant de la division
 */
Int Int::operator/(const Int& b)const{
    Int copie = *this;
    copie /= b;
    return copie;
}

/**
 * @brief Opérateur de modulo
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Un nouvel objet Int résultant du modulo
 */
Int Int::operator%(const Int& b)const{
    Int copie = *this;
    copie %= b;
    return copie;
}

/**
 * @brief Opérateur de comparaison inférieure
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Vrai si a est inférieur à b, faux sinon
 */
bool Int::operator<(const Int& b) const {
    if(signe && not(b.signe)) return true;
    if(not(signe) && b.signe) return false;
    if(signe && b.signe) return valeur > b.valeur;
    return valeur < b.valeur;
}
/**
 * @brief Opérateur d'égalité
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Vrai si a est égal à b, faux sinon
 */
bool Int::operator==(const Int& b) const {
    return valeur == b.valeur && signe == b.signe;
}

/**
 * @brief Opérateur de comparaison inférieure ou égale
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Vrai si a est inférieur ou égal à b, faux sinon
 */
bool Int::operator<=(const Int& b) const {
    return (*this < b || *this == b);
}

/**
 * @brief Opérateur de comparaison supérieure
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Vrai si a est supérieur à b, faux sinon
 */
bool Int::operator>(const Int& b) const {
    return (not(*this < b) && *this != b);
}
/**
 * @brief Opérateur de comparaison supérieure ou égale
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Vrai si a est supérieur ou égal à b, faux sinon
 */
bool Int::operator>=(const Int& b) const {
    return (not(*this < b));
}

/**
 * @brief Opérateur de différence
 * @param a Référence sur le premier objet Int
 * @param b Référence sur le deuxième objet Int
 * @return Vrai si a est différent de b, faux sinon
 */
bool Int::operator!=(const Int& b) const {
    return (valeur != b.valeur || signe != b.signe);
}

/**
 * @brief Opérateur de flux de sortie
 * @param os Référence sur le flux de sortie
 * @param a Référence sur l'objet Int à afficher
 * @return Référence sur le flux de sortie
 */
ostream& operator<<(ostream& os, const Int& a){
    if(a.signe) os << '-';
    ios_base::fmtflags f(os.flags());
    if(f & ios_base::showpos) os << (a.signe ? "-":"+");
    if(f & ios_base::hex) os << Setbase::set_base(16);
    else if(f & ios_base::oct) os << Setbase::set_base(8);
    else if(f & ios_base::dec) os << Setbase::set_base(10);
    else if(f & ios_base::binary) os << Setbase::set_base(2);
    os << a.valeur;
    return os;
}

/**
 * @brief Opérateur de flux d'entrée
 * @param is Référence sur le flux d'entrée
 * @param a Référence sur l'objet Int à modifier
 * @return Référence sur le flux d'entrée
 */
istream& operator>>(istream& is, Int& a){
    string str;
    getline(is, str);
    a = Int(stoi(str));
    return is;
}

/**
 * @brief Opérateur d'incrémentation postfixée
 * @param a Référence sur l'objet Int à incrémenter
 * @param int Paramètre fictif pour différencier la version postfixée
 * @return Une copie de l'objet Int avant l'incrémentation
 */
Int Int::operator++(int){
    Int copie = *this;
    *this+=Int(1);
    return copie;
}

/**
 * @brief Opérateur d'incrémentation préfixée
 * @param a Référence sur l'objet Int à incrémenter
 * @return Référence sur l'objet Int après l'incrémentation
 */
Int& Int::operator++(){
    return *this+=Int(1);
}

/**
 * @brief Opérateur de décrémentation postfixée
 * @param a Référence sur l'objet Int à décrémenter
 * @param int Paramètre fictif pour différencier la version postfixée
 * @return Une copie de l'objet Int avant la décrémentation
 */
Int Int::operator--(int){
    Int copie = *this;
    *this-=Int(1);
    return copie;
}

/**
 * @brief Opérateur de décrémentation préfixée
 * @param a Référence sur l'objet Int à décrémenter
 * @return Référence sur l'objet Int après la décrémentation
 */
Int& Int::operator--(){
    return *this-=Int(1);
}

// /**
//  * @brief Conversion de l'objet Int en entier
//  * @return La valeur entière correspondante
//  */
// Int::operator int() const {
//     return signe ? -static_cast<int>(valeur) : static_cast<int>(valeur);
// }