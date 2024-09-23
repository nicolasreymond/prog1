#include <iostream>
using namespace std;
int main() {
  int n=10, p=5, q=10, r;
  r = n == (p = q);
  cout << "A : n = " << n << " p = " << p << " q = " << q
                          << " r = " << r << "\n";

  n = p = q = 5;
  n += p += q;
  cout << "B : n = " << n << " p = " << p << " q = " << q << "\n";

  q = n < p ? n++ : p++;
  cout << "C : n = " << n << " p = " << p << " q = " << q << "\n";

  q = n > p ? n++ : p++;
  cout << "D : n = " << n << " p = " << p << " q = " << q << "\n";
}