#include <iostream>
using namespace std;


int minimum(int a, int b) {
    if (a < b) {
        return b;
    }
    return a;
}

int maximum(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

void echanger(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 3 , b = 5;

    cout << "a = " << a << " b = " << b << endl;

    echanger(a, b);

    cout << "a = " << a << " b = " << b << endl;

    return 0;
}