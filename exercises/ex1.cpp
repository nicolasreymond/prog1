#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int i;
    double x, racx;
    const int n_fois = 5;

    cout << "Bonjour\n";
    cout << "Je vais vous calculer " << n_fois << " racines carrees" << endl;

    for (i = 0; i < n_fois; i++) {
        cout << "Donnez un nombre : ";
        cin >> x;

        if (x < 0.0)
            cout << "Le nombre " << x << " ne possede pas de racine carree\n";
        else {
            racx = sqrt(x);
            cout << "Le nombre " << x << " a pour racine carree : " << racx << endl;
        }
    }

    cout << "Travail termine - au revoir\n";
}