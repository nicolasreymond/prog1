#include <iostream>

using namespace std;

void croix(int h){
    for (int i = 0; i < h-1; ++i){
        for (int j = 0; j <= i; j++)
            cout << " ";
        cout << "\\";
        for (int j = i; j < (h-1) - 2 + (h - i); j++)
            cout << " ";
        cout << "/";
    cout << "\n";
    }
    for (int i = 0; i < h; i++)
        cout << " ";
    cout << "X\n";
    for (int i = h-1; i > 0; --i)
    {
        for (int j = i; j > 0; j--)
            cout << " ";
        cout << "/";
        for (int j = 0; j <= (h - i) - 2 + (h - i); j++)
            cout << " ";
        cout << "\\";
        cout << "\n";
    }
}


int main(){
    cout << "donner la taille de la croix : ";
    int h;
    cin >> h; 
    croix(h);
}