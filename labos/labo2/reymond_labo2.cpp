/**
 * @file reymond_labo2.cpp
 * @author Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief Programme qui convertit un nombre de secondes en semaines, jours, heures, minutes et secondes
 * @version 1.2
 * @date 2024-09-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

// Constantes pour les conversions
const int secondes_par_minute = 60;
const int secondes_par_heure = 3600;
const int jours_par_semaine = 7;
const int heures_par_jour = 24;

int main(void) {
    int duree; // duree entrée par l'utilisateur en secondes
    cout << "Veuillez entrer la durée en secondes à convertir : " << endl << "> ";
    cin >> duree;

    // Calculer le nombre de semaines
    int semaines = duree / (secondes_par_heure * heures_par_jour * jours_par_semaine);
    duree = duree % (secondes_par_heure * heures_par_jour * jours_par_semaine);

    // Calculer le nombre de jours
    int jours = duree / (secondes_par_heure * heures_par_jour);
    duree = duree % (secondes_par_heure * heures_par_jour);

    // Calculer le nombre d'heures
    int heures = duree / secondes_par_heure;
    duree = duree % secondes_par_heure;

    // Calculer le nombre de minutes
    int minutes = duree / secondes_par_minute;
    int secondes = duree % secondes_par_minute;

    // Afficher le résultat
    cout << semaines << " semaines, " 
         << jours << " jours, " 
         << heures << " heures, " 
         << minutes << " minutes et " 
         << secondes << " secondes" << endl;
}
