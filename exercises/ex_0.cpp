#include <iostream>
using namespace std;

const size_t n = 5;

void a(long &&lg) { cout << "1\n"; }
void a(long &lg) { cout << "2\n"; }
void a(const long &lg) { cout << "3\n"; }
void a(long *lg) { cout << "4\n"; }
void a(const long *lg) { cout << "5\n"; }
// void a(long lg[n])      {cout << "6\n";} //!!! Même type que 4 !!!
// void a(long lg)         {cout << "7\n";} //!!! Déclaration possible, mais
// ambigüité lors des appels a(lg + 1L) (avec 1 et 3), a(lg) (avec 2 et 3)
// ou a(cst_lg) (avec 3) !!!

void b(const size_t *pts) { cout << "8\n"; }
void b(const size_t &size) { cout << "9\n"; }

void c(int i) { cout << "10\n"; }
void c(double d) { cout << "111\n"; }

int main()
{
    long lg, *pt_lg;
    const long cst_lg = 12;
    ////////////////////////  Types exacts
    a(lg + 1L); // 1 (r-value)
    a(lg);      // 2 (l-value modifiable)
    a(cst_lg);  // 3 (l-value non modifiable)
    a(pt_lg);
    a(&lg);     // 4
    a(&cst_lg); // 5

    //////////////////////  Conversion simple
    size_t s, *pts, tab_s[n];
    size_t *const pts_cst = &s;
    *pts_cst = 33;
    b(s);       // 9
    b(pts);     // 8
    b(tab_s);   // 8
    b(pts_cst); // 8

    /////////////////////   Promotion
    bool bol;
    char car;
    short sh;
    signed char sc;
    unsigned char uc;
    unsigned short us;
    float f;
    c(bol);
    c(car);
    c(sh);
    c(sc);
    c(uc);
    c(us); // 10 dans les 6 cas
    c(f);  // 11

    /////////////////////  Conversion de type
    long double ld;
    unsigned long long ull;
    unsigned u;
    a(ld);
    a(ull);
    a(u);   // 1 dans les 3 cas
    b(ull); // 9
            // c(ld) c(ull) et c(u);  //!!! Ambigüs: pas de préférence entre int et double
}
