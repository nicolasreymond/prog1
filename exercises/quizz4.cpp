#include <iostream>
using namespace std;
int main() {
  // int i, j, n;
  // i = 0; n = i++;
  // cout << "A : i = " << i << " n = " << n << "\n";

  // i = 10; n = ++ i;
  // cout << "B : i = " << i << " n = " << n << "\n";

  // i = 20; j = 5; n = i++ * ++ j;
  // cout << "C : i = " << i << " j = " << j << " n = " << n << "\n";

  // i = 15; n = i += 3;
  // cout << "D : i = " << i << " n = " << n << "\n";

  // i = 3; j = 5; n = i *= --j;
  // cout << "E : i = " << i << " j = " << j << " n = " << n << "\n";

  int k = 0;
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j <= 4; ++j)
      k++;
    cout << k;

    cout << "\n";

  int i = 0;
  while(i++ < 10) {
    if (++i % 3) 
    continue;
      cout << i-- ;
  }

  cout << "\n";

  i = 0;
  while (i++ < 10)
  {
    if (++i % 2) continue;
      cout << i;
  }

  cout << "\n";

  for(int i = 0; i < 4; ++i) {
    switch (i) {
    default:  cout << "E";
    case 0:
              cout << "A";
              break;
    case 1:
              cout << "B"; 
              continue;   
    case 2:   cout << "C"; 
    }
    cout << "-";
  }

  cout << "\n";

  i = 0;
  for( ; i < 4; ++i) {
    if (i % 3){
      switch(i) {
        default: cout << ++i <<"a";
        case 1: cout << --i <<"b";
        case 2: cout << i-- <<"c";
      }
      cout << i;
    }
  }
}
