/**
 * @file nicolas_reymond_labo24.hpp
 * @author Nicolas Reymond (nolan.evard@bluewin.ch)
 * @brief Entêtes des classes utilisées pour les labos 24 et 25
 * @version 0.1
 * @date 02.12.2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef Unsigned_H
#define Unsigned_H

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <exception>

using namespace std;
/**
 * @brief Permet la modification de bases au sein de la classe Unsigned
 * 
 */
class Setbase{
    public:
        static Setbase set_base(int base);
        friend ostream& operator<<(ostream& os, Setbase a);
};
/**
 * @brief Permet la manipulation de nombres non-signés via ses fonctions membres et plusieurs opérateurs redéfinis
 * 
 */
class Unsigned{
    private:
        string valeur;
        static int base;
        string convertirEnBase()const;
        static pair<Unsigned,Unsigned> quotient_reste(const Unsigned & a, const Unsigned & b);
    public:
        Unsigned(string binaire);
        Unsigned(uint64_t n = 0);

        //getter
        string data()const;

        //Surcharge des opérateurs
        friend bool operator<(const Unsigned& a, const Unsigned& b);
        friend bool operator<=(const Unsigned& a, const Unsigned& b);
        friend bool operator>(const Unsigned& a, const Unsigned& b);
        friend bool operator>=(const Unsigned& a, const Unsigned& b);
        friend bool operator==(const Unsigned& a, const Unsigned& b);
        friend bool operator!=(const Unsigned& a, const Unsigned& b);
        friend Unsigned& operator+=(Unsigned& a, const Unsigned& b);
        friend Unsigned& operator-=(Unsigned& a, const Unsigned& b);
        friend Unsigned operator+(Unsigned a, const Unsigned& b);
        friend Unsigned operator-(Unsigned a, const Unsigned& b);
        friend Unsigned& operator*=(Unsigned& a, const Unsigned & b);
        friend Unsigned operator*(Unsigned a, const Unsigned & b);
        friend Unsigned& operator/=(Unsigned& a, const Unsigned & b);
        friend Unsigned operator/(Unsigned a, const Unsigned& b);
        friend Unsigned& operator%=(Unsigned& a, const Unsigned & b);
        friend Unsigned operator%(Unsigned a, const Unsigned& b);
        friend ostream& operator<<(ostream &os, const Unsigned& a);
        friend Unsigned operator++(Unsigned& a, int);
        friend Unsigned& operator++(Unsigned& a);
        friend Unsigned operator--(Unsigned& a, int);
        friend Unsigned& operator--(Unsigned& a);
        operator uint64_t() const;

        static Unsigned random(size_t length);

        //Fonction setbase
        friend Setbase Setbase::set_base(int base);       

};
#endif