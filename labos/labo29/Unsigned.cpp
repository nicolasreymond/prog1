/**
 * @file nicolas_reymond_labo24.cpp
 * @brief Lab on classes and manipulation of unsigned integers. This file also contains lab 25.
 * @version 0.1
 * @date 02.12.2024
 * 
 */
#include "Unsigned.hpp"
#include <cmath>


// Default base value (10)
int Unsigned::base = 10;

string Unsigned::data() const {
    return valeur;
}

/**
 * @brief Construct a new Unsigned:: Unsigned object
 * 
 * @param binaire Binary number as a string
 */
Unsigned::Unsigned(string binaire) {
    // Verify that the string is a binary number
    for (char bit : binaire) {
        if (bit != '0' && bit != '1') {
            throw std::invalid_argument("Ill-formed string for Unsigned");
        }
    }
    // Remove leading zeros if necessary
    while (binaire.size() > 1 && binaire.front() == '0') {
        binaire.erase(binaire.begin());
    }
    valeur = binaire;
}

/**
 * @brief Construct a new Unsigned:: Unsigned object
 * 
 * @param n Unsigned number to convert to binary
 */
Unsigned::Unsigned(uint64_t n) {
    valeur = "";
    if (n == 0) valeur = "0";
    while (n > 0) {
        valeur = to_string(n % 2) + valeur;
        n /= 2;
    }
}

/**
 * @brief Overload the less than operator for the Unsigned class
 * 
 * @param a Unsigned a
 * @param b Unsigned b
 * @return true 
 * @return false 
 */
bool operator<(const Unsigned& a, const Unsigned& b) {
    if (a.valeur.size() != b.valeur.size())
        return a.valeur.size() < b.valeur.size(); // Longer is larger
    return a.valeur < b.valeur; // Lexicographical comparison
}

/**
 * @brief Overload the <= operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator<=(const Unsigned& a, const Unsigned& b) {
    return !(b < a);
}

/**
 * @brief Overload the > operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator>(const Unsigned& a, const Unsigned& b) {
    return b < a;
}

/**
 * @brief Overload the >= operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator>=(const Unsigned& a, const Unsigned& b) {
    return !(a < b);
}

/**
 * @brief Overload the == operator for the Unsigned class
 * 
 * @param a Unsigned a
 * @param b Unsigned b
 * @return true 
 * @return false 
 */
bool operator==(const Unsigned& a, const Unsigned& b) {
    return (a.valeur == b.valeur);
}

/**
 * @brief Overload the != operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator!=(const Unsigned& a, const Unsigned& b) {
    return !(a == b);
}

/**
 * @brief Overload the += operator for the Unsigned class
 * 
 * @param a Object undergoing the operation
 * @param b Object to add
 * @return Unsigned& 
 */
Unsigned& operator+=(Unsigned& a, const Unsigned& b) {
    string resultat("");
    size_t i = a.valeur.size(); // Index of the a string
    size_t j = b.valeur.size(); // Index of the b string
    int retenue = 0; // Carry

    // Traverse both strings
    while (i > 0 || j > 0 || retenue) {
        int bitA = (i > 0) ? a.valeur[--i] - '0' : 0; // Current bit of a or 0 if i == 0
        int bitB = (j > 0) ? b.valeur[--j] - '0' : 0; // Current bit of b or 0 if j == 0

        int sum = bitA + bitB + retenue; // Sum of bits + carry
        resultat += (sum % 2) + '0'; // Add the resulting bit to the string
        retenue = sum / 2; // Calculate the new carry
    }

    // The resulting string is reversed because we built the result from right to left
    std::reverse(resultat.begin(), resultat.end());

    a.valeur = resultat;
    return a;
}

/**
 * @brief Overload the -= operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return Unsigned& 
 */
Unsigned& operator-=(Unsigned& a, const Unsigned& b) {
    // Verify that b is smaller than a so that the result is not negative
    if (a < b) throw range_error("Negative result");
    string resultat("");
    size_t i = a.valeur.size();
    size_t j = b.valeur.size();
    int retenue = 0;

    while (i > 0 || j > 0 || retenue) {
        int bitA = (i > 0) ? a.valeur[--i] - '0' : 0; // Current bit of a or 0 if i == 0
        int bitB = (j > 0) ? b.valeur[--j] - '0' : 0; // Current bit of b or 0 if j == 0

        bitA -= retenue;

        if (bitA < bitB) {
            bitA += 2;
            retenue = 1;
        } else {
            retenue = 0;
        }
        resultat += (bitA - bitB) + '0'; // Add the resulting bit to the string
    }

    // Remove leading zeros
    while (resultat.size() > 1 && resultat.back() == '0') {
        resultat.pop_back();
    }

    // The resulting string is reversed because we built the result from right to left
    reverse(resultat.begin(), resultat.end());

    a.valeur = resultat;
    return a;
}

/**
 * @brief Overload the + operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator+(Unsigned a, const Unsigned& b) {
    return a += b;
}

/**
 * @brief Overload the - operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator-(Unsigned a, const Unsigned& b) {
    return a -= b;
}

/**
 * @brief Overload the *= operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return Unsigned& 
 */
Unsigned& operator*=(Unsigned& a, const Unsigned& b) {
    int i = a.valeur.size() - 1;
    int j = b.valeur.size() - 1;
    Unsigned resultat(0);
    string offset("");

    for (int i = a.valeur.size() - 1; i >= 0; i--) {
        // String of the current multiplication with the offset
        string multi(offset);
        int bitA = a.valeur[i] - '0'; // Current bit of a
        for (int j = b.valeur.size() - 1; j >= 0; j--) {
            int bitB = b.valeur[j] - '0'; // Current bit of b
            multi += to_string(bitA * bitB);
        }
        reverse(multi.begin(), multi.end());
        resultat += Unsigned(multi);
        // Shift to the left
        offset += '0';
    }

    a = resultat;
    return a;
}

/**
 * @brief Overload the * operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator*(Unsigned a, const Unsigned& b) {
    return a *= b;
}

/**
 * @brief Calculate the integer division of a by b and the remainder
 * 
 * @param a Dividend
 * @param b Divisor
 * @return pair<Unsigned, Unsigned> quotient, remainder
 */
pair<Unsigned, Unsigned> Unsigned::quotient_reste(const Unsigned& a, const Unsigned& b) {
    if (b.valeur == "0") throw runtime_error("Division by 0");
    if (a < b) return pair<Unsigned, Unsigned>(Unsigned("0"), a);

    Unsigned quotient(0), reste(0);

    for (char bit : a.valeur) {
        reste.valeur += bit;
        if (reste.valeur[0] == '0') reste.valeur.erase(0, 1);
        if (reste < b) {
            quotient.valeur += '0';
        } else {
            reste -= b;
            quotient.valeur += '1';
        }
    }

    // Remove leading zeros from the quotient
    while (quotient.valeur.size() > 1 && quotient.valeur[0] == '0') {
        quotient.valeur.erase(0, 1);
    }

    return {quotient, reste};
}

/**
 * @brief Overload the /= operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return Unsigned& 
 */
Unsigned& operator/=(Unsigned& a, const Unsigned& b) {
    a = Unsigned::quotient_reste(a, b).first;
    return a;
}

/**
 * @brief Overload the / operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator/(Unsigned a, const Unsigned& b) {
    return Unsigned::quotient_reste(a, b).first;
}

Unsigned& operator%=(Unsigned& a, const Unsigned& b) {
    a = Unsigned::quotient_reste(a, b).second;
    return a;
}

/**
 * @brief Overload the % operator for the Unsigned class
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator%(Unsigned a, const Unsigned& b) {
    return Unsigned::quotient_reste(a, b).second;
}

/**
 * @brief Convert an Unsigned to the requested base. If the base is 2, return the value directly
 * 
 * @return string : Converted value
 */
string Unsigned::convertToBase() const {
    if (this->base == 2) return this->valeur; // If base is binary, return the value directly

    const char nombres[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Unsigned n = *this;
    string resultat = "";

    while (n > Unsigned(0)) {
        Unsigned quotient, reste;
        tie(quotient, reste) = Unsigned::quotient_reste(n, Unsigned(this->base));
        resultat = nombres[static_cast<uint64_t>(reste)] + resultat;
        n = quotient;
    }

    return resultat.empty() ? "0" : resultat;
}

/**
 * @brief Overload the << operator for the Unsigned class
 * 
 * @param os Output stream
 * @param a Object to print
 * @return ostream& 
 */
ostream& operator<<(ostream& os, const Unsigned& a) {
    os << a.convertToBase();
    return os;
}

 /**
  * @brief Overload the post-increment operator for the Unsigned class
  * 
  * @param a 
  * @return Unsigned 
  */
Unsigned operator++(Unsigned& a, int) {
    Unsigned copie = a;
    a += Unsigned(1);
    return copie;
}

/**
 * @brief Overload the pre-increment operator for the Unsigned class
 * 
 * @param a 
 * @return Unsigned& 
 */
Unsigned& operator++(Unsigned& a) {
    return a += Unsigned(1);
}

/**
 * @brief Overload the post-decrement operator for the Unsigned class
 * 
 * @param a 
 * @return Unsigned 
 */
Unsigned operator--(Unsigned& a, int) {
    Unsigned copie = a;
    a -= Unsigned(1);
    return copie;
}

/**
 * @brief Overload the pre-decrement operator for the Unsigned class
 * 
 * @param a 
 * @return Unsigned& 
 */
Unsigned& operator--(Unsigned& a) {
    return a -= Unsigned(1);
}

/**
 * @brief Convert an Unsigned object to uint64_t
 * 
 * @return uint64_t 
 */
Unsigned::operator uint64_t() const {
    uint64_t decimal = 0;
    uint64_t basePower = 1;

    // Convert the binary string to decimal value
    for (int i = valeur.size() - 1; i >= 0; --i) {
        if (valeur[i] == '1') {
            decimal += basePower;
        }
        basePower *= 2;
    }

    return decimal;
}

/**
 * @brief Generate a random number of the desired size
 * 
 * @param length Size of the number
 * @return Unsigned 
 */
Unsigned Unsigned::random(size_t length) {
    string resultat = "";
    for (size_t i = 0; i < length; i++) {
        resultat += to_string(rand() % 2);
    }
    return Unsigned(resultat);
}

 /**
 * @brief Overload the operator for the Setbase class. Has a passive role, allows nothing to be returned when called in a cout.
 * 
 * @param os Output stream
 * @return ostream& 
 */
ostream& operator<<(ostream& os, Setbase) {
    return os;
}

/**
 * @brief Modify the base in the Unsigned class so that the display is done in the desired base
 * 
 * @param base 
 * @return Setbase 
 */
Setbase Setbase::set_base(int base) {
    if (base < 2 || base > 36) {
        Unsigned::base = 10;
    } else {
        Unsigned::base = base;
    }
    return Setbase();
}