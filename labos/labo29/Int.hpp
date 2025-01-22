/**
 * @file nicolas_reymond_labo26.hpp
 * @author Nicolas Reymond (nolan.evard@bluewin.ch)
 * @brief Classe Int permettant la manipulation d'entiers signés
 * @version 0.1
 * @date 17.12.2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef Int_H
#define Int_H
#include "Unsigned.hpp"
#include <iostream>
#include <type_traits>

using namespace std;

class Int{
    private:
        Unsigned valeur;
        bool signe;
    public:
        //Constructeurs
        Int(Unsigned valeur, bool signe);
        Int(int valeur=0);

        //Opérateurs unaires
        Int operator-() const;

        //Opérateurs d'affectation
        Int& operator+=(const Int& b);
        Int& operator-=(const Int& b);
        Int& operator*=(const Int& b);
        Int& operator/=(const Int& b);
        Int& operator%=(const Int& b);

        //Opérateurs opérations
        Int operator+(const Int& b) const;
        Int operator-(const Int& b) const;
        Int operator*(const Int& b) const;
        Int operator/(const Int& b) const;
        Int operator%(const Int& b) const;

        //Opérateurs de comparaison
        bool operator<(const Int& b) const;
        bool operator<=(const Int& b) const;
        bool operator>(const Int& b) const;
        bool operator>=(const Int& b) const;
        bool operator==(const Int& b) const;
        bool operator!=(const Int& b) const;

        //Opérateurs de flux
        friend ostream& operator<<(ostream& os, const Int& a);
        friend istream& operator>>(istream& is, Int& a);

        //Opérateurs d'incrémentation et de décrémentation
        Int operator++(int);
        Int& operator++();
        Int operator--(int);
        Int& operator--();

        //Conversion
        // operator int() const;

        //Getters  
        Unsigned getValeur() const { return valeur; }
        bool getSigne() const { return signe; }
};

#endif