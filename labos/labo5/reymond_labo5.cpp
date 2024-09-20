/**
 * @file reymond_labo5.cpp
 * @author Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief Programme qui convertit un nombre de secondes en semaines, jours, heures, minutes et secondes
 * @version 1.0
 * @date 20-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

// Constantes pour les conversions
const int SECONDES_PAR_HEURE = 3600;
const int HEURES_PAR_JOUR = 24;
const int JOURS_PAR_SEMAINE = 7;
const int SECONDES_PAR_MINUTE = 60;

int main(void) {
    int duree; // duree entrée par l'utilisateur en secondes
    cout << "Veuillez entrer la durée en secondes à convertir : " << endl << "> ";
    cin >> duree;

    // Calculer le nombre total d'heures
    int total_heures = duree / SECONDES_PAR_HEURE;
    duree = duree % SECONDES_PAR_HEURE;

    // Calculer le nombre de semaines
    int semaines = total_heures / (HEURES_PAR_JOUR * JOURS_PAR_SEMAINE);
    int heures_restantes = total_heures % (HEURES_PAR_JOUR * JOURS_PAR_SEMAINE);

    // Calculer le nombre de jours
    int jours = heures_restantes / HEURES_PAR_JOUR;
    int heures = heures_restantes % HEURES_PAR_JOUR;

    // Calculer le nombre de minutes et de secondes restantes
    int minutes = duree / SECONDES_PAR_MINUTE;
    int secondes = duree % SECONDES_PAR_MINUTE;

    // Afficher le résultat en fonction des valeurs calculées
    bool first = true;
    if (semaines > 0) {
        cout << semaines << " semaine" << (semaines > 1 ? "s" : "");
        first = false;
    }
    if (jours > 0) {
        if (!first) cout << ", ";
        cout << jours << " jour" << (jours > 1 ? "s" : "");
        first = false;
    }
    if (heures > 0) {
        if (!first) cout << ", ";
        cout << heures << " heure" << (heures > 1 ? "s" : "");
        first = false;
    }
    if (minutes > 0) {
        if (!first) cout << ", ";
        cout << minutes << " minute" << (minutes > 1 ? "s" : "");
        first = false;
    }
    if (secondes > 0 || first) {
        if (!first) cout << " et ";
        cout << secondes << " seconde" << (secondes > 1 ? "s" : "");
    }
    cout << endl;

    return 0;
}
