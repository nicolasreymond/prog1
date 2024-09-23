#include <iostream>
using namespace std;
int main() {
  int i, j, n;
  i = 0; n = i++;
  cout << "A : i = " << i << " n = " << n << "\n";

  i = 10; n = ++ i;
  cout << "B : i = " << i << " n = " << n << "\n";

  i = 20; j = 5; n = i++ * ++ j;
  cout << "C : i = " << i << " j = " << j << " n = " << n << "\n";

  i = 15; n = i += 3;
  cout << "D : i = " << i << " n = " << n << "\n";

  i = 3; j = 5; n = i *= --j;
  cout << "E : i = " << i << " j = " << j << " n = " << n << "\n";
}
