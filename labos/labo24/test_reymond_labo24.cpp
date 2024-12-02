#include "./reymond_labo24.hpp"
#include <cassert>
#include <iostream>
#include <exception>

using namespace std;

void test_addition()
{
    try
    {
        Unsigned u1("1010");   // 10 in binary
        Unsigned u2(10);       // 10 in decimal
        Unsigned u3 = u1 + u2; // 20 in binary
        assert(u3.to_decimal() == "20");

        Unsigned u4("1111");   // 15 in binary
        Unsigned u5(5);        // 5 in decimal
        Unsigned u6 = u4 + u5; // 20 in binary
        assert(u6.to_decimal() == "20");

        // Additional tests
        Unsigned u7("0");
        Unsigned u8(0);
        Unsigned u9 = u7 + u8;
        assert(u9.to_decimal() == "0");

        Unsigned u10("1001");  // 9 in binary
        Unsigned u11(1);       // 1 in decimal
        Unsigned u12 = u10 + u11; // 10 in binary
        assert(u12.to_decimal() == "10");

        cout << "Addition tests passed!" << endl;
    }
    catch (const exception& e)
    {
        cerr << "Addition tests failed: " << e.what() << endl;
    }
}

void test_subtraction()
{
    try
    {
        Unsigned u1("1010");   // 10 in binary
        Unsigned u2(10);       // 10 in decimal
        Unsigned u4 = u1 - u2; // 0 in binary
        assert(u4.to_decimal() == "0");

        Unsigned u5("1111");   // 15 in binary
        Unsigned u6(5);        // 5 in decimal
        Unsigned u7 = u5 - u6; // 10 in binary
        assert(u7.to_decimal() == "10");

        // Additional tests
        Unsigned u8("1000");   // 8 in binary
        Unsigned u9(3);        // 3 in decimal
        Unsigned u10 = u8 - u9; // 5 in binary
        assert(u10.to_decimal() == "5");

        Unsigned u11("1010");  // 10 in binary
        Unsigned u12(0);       // 0 in decimal
        Unsigned u13 = u11 - u12; // 10 in binary
        assert(u13.to_decimal() == "10");

        cout << "Subtraction tests passed!" << endl;
    }
    catch (const exception& e)
    {
        cerr << "Subtraction tests failed: " << e.what() << endl;
    }
}

void test_multiplication()
{
    try
    {
        Unsigned u1("1010");   // 10 in binary
        Unsigned u2(10);       // 10 in decimal
        Unsigned u5 = u1 * u2; // 100 in binary
        assert(u5.to_decimal() == "100");

        Unsigned u6("111");    // 7 in binary
        Unsigned u7(3);        // 3 in decimal
        Unsigned u8 = u6 * u7; // 21 in binary
        assert(u8.to_decimal() == "21");

        // Additional tests
        Unsigned u9("0");
        Unsigned u10(5);
        Unsigned u11 = u9 * u10;
        assert(u11.to_decimal() == "0");

        Unsigned u12("101");   // 5 in binary
        Unsigned u13(4);       // 4 in decimal
        Unsigned u14 = u12 * u13; // 20 in binary
        assert(u14.to_decimal() == "20");

        cout << "Multiplication tests passed!" << endl;
    }
    catch (const exception& e)
    {
        cerr << "Multiplication tests failed: " << e.what() << endl;
    }
}

void test_factorial()
{
    try
    {
        Unsigned result("1");
        int i;
        for (i = 1; i <= 5; ++i)
        {
            result *= Unsigned(i);
        }
        assert(result.to_decimal() == "120");

        result = Unsigned("1");
        for (i = 1; i <= 7; ++i)
        {
            result *= Unsigned(i);
        }
        assert(result.to_decimal() == "5040");

        // Additional tests
        result = Unsigned("1");
        for (i = 1; i <= 0; ++i)
        {
            result *= Unsigned(i);
        }
        assert(result.to_decimal() == "1");

        result = Unsigned("1");
        for (i = 1; i <= 3; ++i)
        {
            result *= Unsigned(i);
        }
        assert(result.to_decimal() == "6");

        cout << "Factorial tests passed!" << endl;
    }
    catch (const exception& e)
    {
        cerr << "Factorial tests failed: " << e.what() << endl;
    }
}

void test_fibonacci()
{
    try
    {
        Unsigned a("0");
        Unsigned b("1");
        Unsigned c("0");
        int i;
        for (i = 0; i < 10; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        assert(a.to_decimal() == "55");

        a = Unsigned("0");
        b = Unsigned("1");
        for (i = 0; i < 15; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        assert(a.to_decimal() == "610");

        // Additional tests
        a = Unsigned("0");
        b = Unsigned("1");
        for (i = 0; i < 5; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        assert(a.to_decimal() == "5");

        a = Unsigned("0");
        b = Unsigned("1");
        for (i = 0; i < 20; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        assert(a.to_decimal() == "6765");

        a = Unsigned("0");
        b = Unsigned("1");
        for (i = 0; i < 100; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        assert(a.to_decimal() == "3736710778780434371");

        cout << "Fibonacci tests passed!" << endl;
    }
    catch (const exception& e)
    {
        cerr << "Fibonacci tests failed: " << e.what() << endl;
    }
}

int main(void)
{
    test_addition();
    test_subtraction();
    test_multiplication();
    test_factorial();
    test_fibonacci();

    cout << "All tests passed!" << endl;
    return 0;
}
