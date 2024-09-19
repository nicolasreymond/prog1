/**
 * @file reymond_labo2.cpp
 * @author Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief Programme qui convertit un nombre de secondes en semaines, jours, heures, minutes et secondes
 * @version 1.0
 * @date 2024-09-26
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

    // Afficher le résultat
    cout << semaines << " semaines, " 
         << jours << " jours, " 
         << heures << " heures, " 
         << minutes << " minutes et " 
         << secondes << " secondes" << endl;
}
