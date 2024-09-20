/**
 * @file    reymond_labo4.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Programme qui convertit un angle en dixièmes de degré en minutes et secondes
 * @version 1.0
 * @date    20-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
using namespace std;

int main(void) {
    int angle;

    // Entrée de l'angle en dixièmes de degré
    cout << "Entrez l'angle en dixièmes de degrés : ";
    cin >> angle;

    int remaining_angle = 900 - angle; // On compte à partir de 900 (15 minutes)

    // Calculer le nombre de minutes
    int minutes = remaining_angle / 60;

    // Calculer le nombre de secondes restantes
    int seconds = (remaining_angle % 60);  // Chaque 1 dixième de degré = 6 secondes

    // Afficher le résultat
    cout << minutes << " minute(s) et " << seconds << " seconde(s)" << endl;

    return 0;
}