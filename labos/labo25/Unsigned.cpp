#include "Unsigned.hpp"
#include "Setbase.hpp"
#include <stdexcept>
#include <algorithm> // pour std::max

/**
 * @brief Constructeur par défaut : initialise la valeur à "0".
 */
Unsigned::Unsigned() : value("0") {}

/**
 * @brief Constructeur à partir d'une chaîne représentant un entier binaire.
 * @param binary Chaîne de caractères représentant un entier binaire.
 * @throw invalid_argument Si la chaîne contient des caractères invalides.
 */
Unsigned::Unsigned(const string &binary) : value(binary)
{
    if (value.empty())
    {
        value = "0";
    }

    for (char bit : value)
    {
        if (bit != '0' && bit != '1')
        {
            throw invalid_argument("Ill-formed string for Unsigned");
        }
    }

    // Supprime les zéros non significatifs
    while (value.size() > 1 && value[0] == '0')
    {
        value.erase(0, 1);
    }
}

/**
 * @brief Constructeur à partir d'un entier non signé natif.
 * @param number Entier non signé.
 */
Unsigned::Unsigned(uint64_t number)
{
    value = "";
    while (number > 0)
    {
        value = char((number % 2) + '0') + value;
        number /= 2;
    }
    if (value.empty())
    {
        value = "0";
    }
}

/**
 * @brief Retourne la valeur sous forme de chaîne binaire.
 * @return Chaîne représentant l'entier.
 */
string Unsigned::data() const
{
    return value;
}

/**
 * @brief Convertit l'entier en une base donnée (entre 2 et 36).
 * @param base La base cible.
 * @return Chaîne représentant l'entier dans la base cible.
 * @throw invalid_argument Si la base est en dehors de l'intervalle [2, 36].
 */
string Unsigned::to_base(int base) const
{
    if (base < 2 || base > 36)
    {
        throw invalid_argument("Base must be between 2 and 36");
    }

    if (base == 2)
    {
        return value;
    }

    uint64_t decimalValue = to_uint64();

    // Convertit la valeur décimale dans la base cible
    string result = "";
    do
    {
        int remainder = decimalValue % base;
        result = char((remainder < 10 ? '0' + remainder : 'A' + remainder - 10)) + result;
        decimalValue /= base;
    } while (decimalValue > 0);

    return result;
}

/**
 * @brief Convertit l'objet Unsigned en uint64_t.
 * @return La valeur de l'objet en uint64_t.
 */
uint64_t Unsigned::to_uint64() const
{
    uint64_t decimalValue = 0;
    uint64_t basePower = 1;

    // Convertit la chaîne binaire en valeur décimale
    for (int i = value.size() - 1; i >= 0; --i)
    {
        if (value[i] == '1')
        {
            decimalValue += basePower;
        }
        basePower *= 2;
    }

    return decimalValue;
}

pair<Unsigned, Unsigned> Unsigned::divmod(const Unsigned &a, const Unsigned &b)
{
    if (b.value == "0")
        throw runtime_error("Division by 0");
    if (a < b)
        return pair<Unsigned, Unsigned>(Unsigned("0"), a);

    Unsigned quotient(0), reste(0);

    for (char bit : a.value)
    {
        reste.value += bit;
        if (reste.value[0] == '0')
            reste.value.erase(0, 1);
        if (reste < b)
        {
            quotient.value += '0';
        }
        else
        {
            reste -= b;
            quotient.value += '1';
        }
    }

    // Supression des zéros au début du quotient
    while (quotient.value.size() > 1 && quotient.value[0] == '0')
    {
        quotient.value.erase(0, 1);
    }

    return {quotient, reste};
}

/**
 * @brief Ajoute deux objets `Unsigned`.
 * @param right L'objet à ajouter.
 * @return Référence à l'objet actuel modifié.
 */
Unsigned &Unsigned::operator+=(const Unsigned &right)
{
    int carry = 0;
    int leftSize = value.size();
    int rightSize = right.value.size();
    string result = "";
    int i = 0;

    while (i < leftSize || i < rightSize || carry != 0)
    {
        int leftBit = (i < leftSize) ? value[leftSize - 1 - i] - '0' : 0;
        int rightBit = (i < rightSize) ? right.value[rightSize - 1 - i] - '0' : 0;

        int sum = leftBit + rightBit + carry;
        result = char((sum % 2) + '0') + result;
        carry = sum / 2;
        i++;
    }

    value = result;
    return *this;
}

/**
 * @brief Pré-incrémentation (++obj).
 */
Unsigned &Unsigned::operator++()
{
    *this += Unsigned("1");
    return *this;
}

/**
 * @brief Post-incrémentation (obj++).
 */
Unsigned Unsigned::operator++(int)
{
    Unsigned temp = *this;
    ++(*this); // Appel à la pré-incrémentation
    return temp;
}

/**
 * @brief Soustrait deux objets `Unsigned`.
 * @param right L'objet à soustraire.
 * @return Référence à l'objet actuel modifié.
 * @throw range_error Si le résultat est négatif (non défini pour `Unsigned`).
 */
Unsigned &Unsigned::operator-=(const Unsigned &right)
{
    if (*this < right)
    {
        throw range_error("Negative result not allowed in Unsigned");
    }

    int borrow = 0;
    int leftSize = value.size();
    int rightSize = right.value.size();
    string result = "";
    int i = 0;

    while (i < leftSize || i < rightSize)
    {
        int leftBit = (i < leftSize) ? value[leftSize - 1 - i] - '0' : 0;
        int rightBit = (i < rightSize) ? right.value[rightSize - 1 - i] - '0' : 0;

        int diff = leftBit - rightBit - borrow;
        if (diff < 0)
        {
            diff += 2;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result = char(diff + '0') + result;
        i++;
    }

    // Supprime les zéros non significatifs
    while (result.size() > 1 && result[0] == '0')
    {
        result.erase(0, 1);
    }

    value = result;
    return *this;
}


/**
 * @brief Pré-décrémentation (--obj).
 */
Unsigned &Unsigned::operator--()
{
    if (value == "0")
    {
        throw range_error("Cannot decrement below zero"); // Prevent decrementing below zero
    }
    *this -= Unsigned("1"); // Subtract 1 from the current value
    return *this;
}

/**
 * @brief Post-décrémentation (obj--).
 */
Unsigned Unsigned::operator--(int)
{
    Unsigned temp = *this; // Save the current value
    --(*this);             // Use pre-decrement
    return temp;           // Return the original value (before decrement)
}

/**
 * @brief Multiplie deux objets `Unsigned`.
 * @param right L'objet à multiplier.
 * @return Référence à l'objet actuel modifié.
 */
Unsigned &Unsigned::operator*=(const Unsigned &right)
{
    Unsigned result("0");
    Unsigned temp = *this;

    for (int i = right.data().size() - 1; i >= 0; --i)
    {
        if (right.data()[i] == '1')
        {
            result += temp;
        }
        temp.value += '0';
    }

    value = result.data();
    return *this;
}

/**
 * @brief Divise deux objets `Unsigned`.
 * @param right L'objet diviseur.
 * @return Référence à l'objet actuel modifié.
 * @throw runtime_error Si la division par zéro est tentée.
 */
Unsigned &Unsigned::operator/=(const Unsigned &right)
{
    if (right.data() == "0")
    {
        throw std::runtime_error("Division by zero");
    }

    auto [quotient, remainder] = divmod(*this, right);
    value = quotient.data();
    return *this;
}

/**
 * @brief Surcharge de l'opérateur `/`.
 * @param left Dividend.
 * @param right Divisor.
 * @return Nouveau `Unsigned` représentant le quotient.
 * @throw runtime_error Si la division par zéro est tentée.
 */
Unsigned operator/(Unsigned left, const Unsigned &right)
{
    if (right.data() == "0")
    {
        throw std::runtime_error("Division by zero");
    }
    return left /= right; // Réutilise l'opérateur `/=` déjà implémenté
}

/**
 * @brief Modulo de deux objets `Unsigned`.
 * @param right L'objet diviseur.
 * @return Référence à l'objet actuel modifié.
 */
Unsigned &Unsigned::operator%=(const Unsigned &right)
{
    if (right.data() == "0")
    {
        throw std::runtime_error("Division by zero");
    }

    auto [quotient, remainder] = divmod(*this, right);
    value = remainder.data();
    return *this;
}

/**
 * @brief Surcharge de l'opérateur de flux `<<`.
 * @param os Flux de sortie.
 * @param number L'objet `Unsigned` à afficher.
 * @return Flux de sortie.
 */
ostream &operator<<(ostream &os, const Unsigned &number)
{
    os << number.to_base(Setbase::base);
    return os;
}

/**
 * @brief Compare si un `Unsigned` est inférieur à un autre.
 * @param right L'objet à comparer.
 * @return true Si l'objet actuel est strictement inférieur à `right`.
 */
bool Unsigned::operator<(const Unsigned &right) const
{
    if (value.size() != right.value.size())
    {
        return value.size() < right.value.size();
    }
    return value < right.value;
}

/**
 * @brief Compare si un `Unsigned` est supérieur ou égal à un autre.
 * @param right L'objet à comparer.
 * @return true Si l'objet actuel est supérieur ou égal à `right`.
 */
bool Unsigned::operator>=(const Unsigned &right) const
{
    return !(*this < right);
}

/**
 * @brief Compare si un `Unsigned` est supérieur à un autre.
 * @param right L'objet à comparer.
 * @return true Si l'objet actuel est strictement supérieur à `right`.
 */
bool Unsigned::operator>(const Unsigned &right) const
{
    return right < *this;
}

/**
 * @brief Compare si un `Unsigned` est inférieur ou égal à un autre.
 * @param right L'objet à comparer.
 * @return true Si l'objet actuel est inférieur ou égal à `right`.
 */
bool Unsigned::operator<=(const Unsigned &right) const
{
    return !(*this > right);
}

/**
 * @brief Compare si un `Unsigned` est égal à un autre.
 * @param right L'objet à comparer.
 * @return true Si l'objet actuel est égal à `right`.
 */
bool Unsigned::operator==(const Unsigned &right) const
{
    return value == right.value;
}

/**
 * @brief Compare si un `Unsigned` est différent d'un autre.
 * @param right L'objet à comparer.
 * @return true Si l'objet actuel est différent de `right`.
 */
bool Unsigned::operator!=(const Unsigned &right) const
{
    return !(*this == right);
}

/**
 * @brief Conversion operator to uint64_t.
 */
Unsigned::operator uint64_t() const
{
    return to_uint64();
}
