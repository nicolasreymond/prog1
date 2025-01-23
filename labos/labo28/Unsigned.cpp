#include "Unsigned.hpp"
#include <cmath>

//----------------------------------------------------- Méthodes et surcharges de la Classe Unsigned -----------------------------------------------//

//Valeur par défaut de la base (10)
int Unsigned::base = 10;

string Unsigned::data(){
    return valeur;
}

/**
 * @brief Construct a new Unsigned:: Unsigned object
 * 
 * @param binaire Nombre en binaire sous forme de string
 */
Unsigned::Unsigned(string binaire){
    //Vérifie que la chaine soit bien un nombre binaire
    for (char bit : binaire) {
        if (bit != '0' && bit != '1') {
            throw std::invalid_argument("Ill-formed string for Unsigned");
        }
    }
    //Enlève les zéros en début de chaine si nécessaire
    while(binaire.size() > 1 && binaire.front() == '0'){
        binaire.erase(binaire.begin());
    }
    valeur = binaire;
}

/**
 * @brief Construct a new Unsigned:: Unsigned object
 * 
 * @param n nombre non-signé à convertir en binaire
 */
Unsigned::Unsigned(uint64_t n){
    valeur = "";
    if(n == 0) valeur = "0";
    while(n > 0){
        valeur =  to_string(n % 2) + valeur;
        n/=2;
    }
}
/**
 * @brief Surcharge de l'opérateur plus petit que pour la classe Unsigned
 * 
 * @param a Unsigned a
 * @param b Unsigned b
 * @return true 
 * @return false 
 */
bool operator<(const Unsigned& a, const Unsigned& b){
    if (a.valeur.size() != b.valeur.size())
        return a.valeur.size() < b.valeur.size(); // Plus long est plus grand
    return a.valeur < b.valeur; // Comparaison lexicographique
}
/**
 * @brief Surcharge de l'opérateur '<=' pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator<=(const Unsigned& a, const Unsigned& b){
    return !(b < a);
}
/**
 * @brief Surcharge de l'opérateur '>' pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator>(const Unsigned& a, const Unsigned& b){
    return b < a;
}
/**
 * @brief Surcharge de l'opérateur '>=' pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator>=(const Unsigned& a, const Unsigned& b){
    return (!(a<b));
}
/**
 * @brief Surcharge de l'opérateur == pour la classe Unsigned
 * 
 * @param a Unsigned a
 * @param a Unsigned b
 * @return true 
 * @return false 
 */
bool operator==(const Unsigned& a, const Unsigned & b){
    return (a.valeur == b.valeur);
}
/**
 * @brief Surcharge de l'opérateur '!=' pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator!=(const Unsigned& a, const Unsigned& b){
    return !(a == b);
}
/**
 * @brief Surcharge de l'opérateur += pour la classe Unsigned
 * 
 * @param a Objet subissant l'opération
 * @param b Objet à ajouter
 * @return Unsigned& 
 */
Unsigned& operator+=(Unsigned& a, const Unsigned& b){
    string resultat("");
    size_t i = a.valeur.size(); // Indice de la chaîne a
    size_t j = b.valeur.size(); // Indice de la chaîne b
    int retenue = 0;        // Retenue

    // Parcourir les deux chaînes
    while (i > 0 || j > 0 || retenue) {
        int bitA = (i > 0) ? a.valeur[--i] - '0' : 0; // Bit actuel de a ou 0 si i == 0
        int bitB = (j > 0) ? b.valeur[--j] - '0' : 0; // Bit actuel de b ou 0 si j == 0

        int sum = bitA + bitB + retenue; // Somme des bits + retenue
        resultat += (sum % 2) + '0';     // Ajouter le bit résultant à la chaîne
        retenue = sum / 2;               // Calculer la nouvelle retenue
    }

    // La chaîne résultante est inversée, car nous avons construit le résultat de droite à gauche
    std::reverse(resultat.begin(), resultat.end());

    a.valeur = resultat;
    return a;
}
/**
 * @brief Surcharge de l'opérateur -= pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned& 
 */
Unsigned& operator-=(Unsigned& a, const Unsigned& b){
    // Vérifie que b est plus petit que a pour que le résultat ne soit pas négatif
    if (a < b) throw range_error("Negative result");
    string resultat("");
    size_t i = a.valeur.size();
    size_t j = b.valeur.size();
    int retenue = 0;

    while (i > 0 || j > 0 || retenue) {
        int bitA = (i > 0) ? a.valeur[--i] - '0' : 0; // Bit actuel de a ou 0 si i == 0
        int bitB = (j > 0) ? b.valeur[--j] - '0' : 0; // Bit actuel de b ou 0 si j == 0

        bitA -= retenue;

        if (bitA < bitB) {
            bitA += 2;
            retenue = 1;
        } else {
            retenue = 0;
        }
        resultat += (bitA - bitB) + '0'; // Ajouter le bit résultant à la chaîne
    }

    // Supprimer les zéros de tête
    while (resultat.size() > 1 && resultat.back() == '0') {
        resultat.pop_back();
    }

    // La chaîne résultante est inversée, car nous avons construit le résultat de droite à gauche
    reverse(resultat.begin(), resultat.end());

    a.valeur = resultat;
    return a;
}
/**
 * @brief Surcharge de l'opérateur + pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator+(Unsigned a, const Unsigned& b){
    return a += b;
}
/**
 * @brief Surcharge de l'opérateur - pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator-(Unsigned a, const Unsigned & b){
    return a -= b;
}
/**
 * @brief Surcharge de l'opérateur *= pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned& 
 */
Unsigned& operator*=(Unsigned& a, const Unsigned & b){
    int i = a.valeur.size() -1;
    int j = b.valeur.size() -1;
    Unsigned resultat(0);
    string offset("");

    for(int i = a.valeur.size() -1; i >= 0; i--){
        //String de la multiplication actuelle avec l'offset
        string multi(offset);
        int bitA = a.valeur[i] - '0'; // Bit actuel de a
        for(int j = b.valeur.size() -1; j >= 0; j--){
            int bitB = b.valeur[j] - '0'; // Bit actuel de b
            multi += to_string(bitA * bitB);
        }
        reverse(multi.begin(), multi.end());
        resultat += Unsigned(multi);
        //Décallage vers la gauche
        offset+='0';
    }

    a = resultat;
    return a;
}
/**
 * @brief Surcharge de l'opérateur * pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator*(Unsigned a, const Unsigned & b){
    return a *= b;
}
/**
 * @brief Calcule la division entière de a par b ainsi que le reste
 * 
 * @param a Dividende
 * @param b Diviseur
 * @return pair<Unsigned,Unsigned> quotient, reste
 */
pair<Unsigned,Unsigned> Unsigned::quotient_reste(const Unsigned & a, const Unsigned & b){
    if(b.valeur == "0") throw runtime_error("Division by 0");
    if(a<b) return pair<Unsigned,Unsigned>(Unsigned("0"),a);

    Unsigned quotient(0), reste(0);

    for(char bit : a.valeur){
        reste.valeur+=bit;
        if(reste.valeur[0] == '0') reste.valeur.erase(0,1);
        if(reste<b){
            quotient.valeur += '0';
        }
        else{
            reste -= b;
            quotient.valeur += '1';
        }
    }

    //Supression des zéros au début du quotient
    while (quotient.valeur.size() > 1 && quotient.valeur[0] == '0') {
        quotient.valeur.erase(0, 1);
    }

    return {quotient, reste};
}
/**
 * @brief Surcharge de la fonction '/=' pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned& 
 */
Unsigned& operator/=(Unsigned& a, const Unsigned & b){
    a = Unsigned::quotient_reste(a,b).first;
    return a;
}
/**
 * @brief Surcharge de la fonction '/' pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator/(Unsigned a, const Unsigned& b){
    return Unsigned::quotient_reste(a,b).first;
}
/**
 * @brief Surcharge de la fonction '%' pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned 
 */
Unsigned operator%(Unsigned a, const Unsigned& b){
    return Unsigned::quotient_reste(a,b).second;
}

/**
 * @brief Surcharge de l'opérateur '%=' pour la classe Unsigned
 * 
 * @param a 
 * @param b 
 * @return Unsigned& 
 */
Unsigned& operator%=(Unsigned& a, const Unsigned& b){
    a = Unsigned::quotient_reste(a,b).second;
    return a;
}

/**
 * @brief Convertit un Unsigned dans la base demandée. Si la base est 2, retourne la valeur directement
 * 
 * @return string : Valeur convertie
 */
string Unsigned::convertirEnBase() const {
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
 * @brief Surcharge de l'opérateur '<<' pour la classe Unsigned
 * 
 * @param os Stream de sortie
 * @param a Objet à imprimer
 * @return ostream& 
 */
ostream& operator<<(ostream& os, const Unsigned& a){
    os << a.convertirEnBase();
    return os;
}
 /**
  * @brief Surcharge de l'opérateur '++' post-fixé pour la classe Unsigned
  * 
  * @param a 
  * @return Unsigned 
  */
Unsigned operator++(Unsigned& a, int){
    Unsigned copie = a;
    a+=Unsigned(1);
    return copie;
}
/**
 * @brief Surcharge de l'opérateur '++' pré-fixé pour la classe Unsigned
 * 
 * @param a 
 * @return Unsigned& 
 */
 Unsigned& operator++(Unsigned& a){
    return a+=Unsigned(1);
 }
/**
 * @brief Surcharge de l'opérateur '--' post-fixé pour la classe Unsigned
 * 
 * @param a 
 * @return Unsigned 
 */
 Unsigned operator--(Unsigned& a, int){
    Unsigned copie = a;
    a-=Unsigned(1);
    return copie;
 }
/**
 * @brief Surcharge de l'opérateur '--' pré-fixé pour la classe Unsigned
 * 
 * @param a 
 * @return Unsigned& 
 */
 Unsigned& operator--(Unsigned& a){
    return a-=Unsigned(1);
 }
/**
 * @brief Converti un objet de la classe Unsigned en uint_64
 * 
 * @return uint64_t 
 */
Unsigned::operator uint64_t() const{
    uint64_t decimal = 0;
    uint64_t basePower = 1;

    // Convertit la chaîne binaire en valeur décimale
    for (int i = valeur.size() - 1; i >= 0; --i)
    {
        if (valeur[i] == '1')
        {
            decimal += basePower;
        }
        basePower *= 2;
    }

    return decimal;
}
//----------------------------------------------------- Méthodes et surcharges de la Classe Setbase -----------------------------------------------//

 /**
 * @brief Surcharge de l'opérateur pour la classe Setbase. A un rôle passif, permet de ne rien retourner lors de l'appel dans un cout.
 * 
 * @param os Stream de sortie
 * @return ostream& 
 */
ostream& operator<<(ostream& os, Setbase){
    return os;
}
/**
 * @brief Modifie la base dans la classe Unsigned pour que l'affichage soit fait dans la base souhaitée
 * 
 * @param base 
 * @return Setbase 
 */
Setbase Setbase::set_base(int base){
    if (base < 2 || base > 36) {
        Unsigned::base = 10;
    }
    else{
        Unsigned::base = base;
    }
    return Setbase();
}