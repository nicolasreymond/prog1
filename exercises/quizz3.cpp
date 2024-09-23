#include <iostream>
using namespace std;
int main() {
  { double x;
    int n, p;
    p = 2;
    x = 15 / p;
    n = x + 0.5;
    cout << "1. " << p << ' ' << x << ' ' << n << endl;
  }

  { double x;
    int n, p;
    p = 2;
    x = 15./ p;
    n = x + 0.5;
    cout << "2. " << p << ' ' << x << ' ' << n << endl;
  }

  { int n, p;
    double x;
    n = 10;
    p = 7;
    x = 2.5;
    cout << "3. " << x + n % p << endl;
    cout << "4. " << x + p / n << endl;
    cout << "5. " << (x + p) / n << endl;
    cout << "6. " << .5 * n << endl;
    cout << "7. " << .5 * (double)n << endl;
    cout << "8. " << (int).5 * n << endl;
    cout << "9. " << (n + 1) / n << endl;
    cout << "10. " << (n + 1.0) / n << endl;
  }
}