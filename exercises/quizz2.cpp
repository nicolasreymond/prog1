#include <iostream>
using namespace std;
int main() {
  int n, p, q;
  n = 5; p = 2;

  q = n++ > p or p++ != 3;                           /* cas 1 */
  cout << "A : n = " << n << " p = " << p << " q = " << q << "\n";

  n = 5; p = 2;
  q = n++ < p or p++ != 3;                            /* cas 2 */
  cout << "B : n = " << n << " p = " << p << " q = " << q << "\n";

  n = 5; p = 2;
  q = ++n == 3 and ++p == 3;                         /* cas 3 */
  cout << "C : n = " << n << " p = " << p << " q = " << q << "\n";

  n = 5; p = 2;
  q = ++n == 6 and ++p == 3;                         /* cas 4 */
  cout << "D : n = " << n << " p = " << p << " q = " << q << "\n";
}