/**
 * @file    reymond_labo3.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Programme qui calcule la durée entre deux heures
 * @version 1.1
 * @date    2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
using namespace std;

int main() {
    int start_h, start_m, end_h, end_m;

    // Entrée de l'heure de début
    cout << "Entrez l'heure de départ (hh mm): ";
    cin >> start_h >> start_m;

    // Entrée de l'heure de fin
    cout << "Entrez l'heure d'arrivée (hh mm): ";
    cin >> end_h >> end_m;

    // Convertir les heures et minutes en minutes depuis 00:00
    int start_total = start_h * 60 + start_m;
    int end_total = end_h * 60 + end_m;

    // Ajouter 1440 minutes (24 heures) à l'heure d'arrivée pour garantir que le résultat est toujours positif
    int duration = (end_total - start_total + 1440) % 1440;

    // Calcul des heures et minutes de la durée
    int duration_h = duration / 60;
    int duration_m = duration % 60;

    // Afficher le résultat
    cout << "La durée du trajet est: " << duration_h << " heure(s) et " << duration_m << " minute(s)\n";

    return 0;
}
