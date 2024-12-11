
#include <iostream>
#include <vector>
#include <random>
using namespace std;
int compteur_fusion = 0;
/**
 * @brief Effectue un tri par insertion sur un vector d'entiers
 *
 * @param v Vector d'entiers
 */
int tri_insertion(vector<int> &v){
    int compteurComp = 0;
    // Appliquer un tri par insertion standard
    for (size_t i = 1; i < v.size(); ++i)
    {
        auto tmp = v[i];
        size_t j = i;
        while (j > 0 and v[j - 1] > tmp)
        {
            v[j] = v[j - 1];
            --j;
            compteurComp++;
        }
        v[j] = tmp;
    }
    return compteurComp;
}
/**
 * @brief Tri combiné combinant tri à peigne et tri par insertion pour trier un vector d'entiers
 *
 * @param v Vector d'entiers
 * @param shrink Facteur de réduction de l'écart des dents du peigne
 * @param min_gap Ecart minimum entre les dents du peigne
 */
int comb_sort(vector<int> &v, double shrink, size_t min_gap){
    int compteurComp = 0;
    size_t gap = v.size();
    // trier grossièrement avec un peigne aux dents écartées
    while (gap > min_gap)
    {
        gap *= shrink; // Diminuer l’écart des dents du peigne
        for (size_t i = 0; i < v.size() - gap; ++i)
            if ((++compteurComp) && (v[i + gap] < v[i]))
            {
                swap(v[i], v[i + gap]);
            }
    }
    compteurComp += tri_insertion(v);
    return compteurComp;
}
/**
 * @brief Fusionne 2 vectors et retourne leur union
 *
 * @param va Vector a
 * @param vb Vector b
 * @return vector<int>
 */
vector<int> fusion(vector<int> va, vector<int> vb){
    vector<int> resultat;
    int i = 0, j = 0;
    // Fusionner les deux vecteurs
    while (i < va.size() && j < vb.size())
    {
        if ((++compteur_fusion) && (va[i] <= vb[j]))
        {
            resultat.push_back(va[i]);
            i++;
        }
        else
        {
            resultat.push_back(vb[j]);
            j++;
        }
    }
    // Ajouter les éléments restants du vecteur gauche (s'il y en a)
    while (i < va.size())
    {
        resultat.push_back(va[i]);
        i++;
    }
    // Ajouter les éléments restants du vecteur droit (s'il y en a)
    while (j < vb.size())
    {
        resultat.push_back(vb[j]);
        j++;
    }
    return resultat;
}
/**
 * @brief Tri par fusion de vector sur un vector d'entiers
 *
 * @param v Vector d'entiers
 */
void tri_fusion(vector<int> &v){
    if (v.size() < 2) // Déjà trié,on ne fait rien
        return;
    vector<int> va, vb;
    va.insert(va.begin(), v.begin(), v.begin() + v.size() / 2); // début de v
    vb.insert(vb.begin(), v.begin() + v.size() / 2, v.end());   // fin de v
    tri_fusion(va);
    tri_fusion(vb);
    v = fusion(va, vb);
}
/**
 * @brief Surcharge de l'opérateur "<<" pour le vecteur d'entiers
 *
 * @param stream flux de sortie
 * @param v vecteur d'entier
 * @return ostream&
 */
ostream &operator<<(ostream &stream, const vector<int> &v){
    for (const int &e : v)
        stream << e << " ";
    return stream;
}
int main(){
    // Trouver les meilleurs paramètres
    // Generer un vector d'entier de taille 10 et de composition aléatoire
    //  const int nbElements = 100;
    vector<int> liste;
    // for(int i = 0; i < nbElements; i++){
    //     liste.push_back(rand());
    // }

    cout << "algorithme,nbElements,nbComparaisons" << endl;
    for (int i = 100; i <= 100000; i *= 2)
    {
        int combo_comp = 0, fusion_comp = 0, inser_comp = 0;
        for (int j = 0; j < i; j++)
        {
            liste.push_back(rand());
        }
        vector<int> v = liste;
        cout << "combo," << i << "," << comb_sort(v, .7, 4) << endl;
        v = liste;
        cout << "insertion," << i << "," << tri_insertion(v) << endl;
        v = liste;
        tri_fusion(v);
        cout << "fusion," << i << "," << compteur_fusion << endl;
        compteur_fusion = 0;
    }
    // cout << "Taille de la liste a trier: " << nbElements << " elements" << endl;
    // cout << "Nombre minimal de comparaisons trouve: " << comp << " comparaisons avec shrink = " << found_shrink << " et min_gap = " << found_gap << endl;
    //  cout << "Liste: " << liste << endl;
    //  cout << "Tri de la liste..." << endl;
    //  int nbComp = comb_sort(liste, .8, 5);
    //  cout << "Liste triee: " << liste << endl;
    //  cout << "Nb comparaisons: " << nbComp << " comparaisons" << endl;
    return 0;
}
