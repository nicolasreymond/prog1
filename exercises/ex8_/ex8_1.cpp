#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string vraiFaux(bool b){
    return b ? "vrai" : "faux";
}



int main() {
    //08_01_01
    char lettre_01;
    cout << "Entrer un char : ";
    cin >> lettre_01;

    cout << "Code ASCII de " << lettre_01 << " est " << int(lettre_01) << "\n";   
    cout << lettre_01 << " est une lettre_01 de l'alphabet : " << vraiFaux(isalpha(lettre_01)) << "\n";
    cout << lettre_01 << " est une lettre_01 minuscule : " << vraiFaux(islower(lettre_01)) << "\n";
    cout << lettre_01 << " est un chiffre : " << vraiFaux(isdigit(lettre_01)) << "\n";
    cout << lettre_01 << " est un caractere de ponctuation : " << vraiFaux(ispunct(lettre_01)) << "\n";

    cout << "\n\n\n";
    //08_03_01
    cout << "Exercice 08_03_01\n";
    string chaine_03;
    cout << "Entrer une chaine pour l'exercice 03 : ";
    cin >> chaine_03;
    if (chaine_03.size() % 2 == 0)
    //afficher le caractere du milieu de la chaine (2 caracteres si la chaine est de taille paire)
        cout << "le milieu de la chaine est : " << chaine_03[chaine_03.size() / 2 - 1] << chaine_03[chaine_03.size() / 2] << "\n";
    else
        cout << "le milieu de la chaine est : " << chaine_03[chaine_03.size() / 2] << "\n";

    cout << "\n\n\n";
    //08_03_02



    return 1;
}