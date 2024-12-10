#include "./reymond_labo24.hpp"
#include <iostream>
#include <exception>

using namespace std;

void TestAddition() {
    try {
        Unsigned u1("1010");   // 10 in binary
        Unsigned u2(10);       // 10 in decimal
        Unsigned u3 = u1 + u2; // 20 in binary
        if (u3.to_base(10) != "20") throw runtime_error("TestAddition failed");

        Unsigned u4("1111");   // 15 in binary
        Unsigned u5(5);        // 5 in decimal
        Unsigned u6 = u4 + u5; // 20 in binary
        if (u6.to_base(10) != "20") throw runtime_error("TestAddition failed");

        // Additional tests
        Unsigned u7("0");
        Unsigned u8(0);
        Unsigned u9 = u7 + u8;
        if (u9.to_base(10) != "0") throw runtime_error("TestAddition failed");

        Unsigned u10("1001");  // 9 in binary
        Unsigned u11(1);       // 1 in decimal
        Unsigned u12 = u10 + u11; // 10 in binary
        if (u12.to_base(10) != "10") throw runtime_error("TestAddition failed");

        cout << "TestAddition passed" << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void TestSubtraction() {
    try {
        Unsigned u1("1010");   // 10 in binary
        Unsigned u2(10);       // 10 in decimal
        Unsigned u4 = u1 - u2; // 0 in binary
        if (u4.to_base(10) != "0") throw runtime_error("TestSubtraction failed");

        Unsigned u5("1111");   // 15 in binary
        Unsigned u6(5);        // 5 in decimal
        Unsigned u7 = u5 - u6; // 10 in binary
        if (u7.to_base(10) != "10") throw runtime_error("TestSubtraction failed");

        // Additional tests
        Unsigned u8("1000");   // 8 in binary
        Unsigned u9(3);        // 3 in decimal
        Unsigned u10 = u8 - u9; // 5 in binary
        if (u10.to_base(10) != "5") throw runtime_error("TestSubtraction failed");

        Unsigned u11("1010");  // 10 in binary
        Unsigned u12(0);       // 0 in decimal
        Unsigned u13 = u11 - u12; // 10 in binary
        if (u13.to_base(10) != "10") throw runtime_error("TestSubtraction failed");

        cout << "TestSubtraction passed" << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void TestMultiplication() {
    try {
        Unsigned u1("1010");   // 10 in binary
        Unsigned u2(10);       // 10 in decimal
        Unsigned u5 = u1 * u2; // 100 in binary
        if (u5.to_base(10) != "100") throw runtime_error("TestMultiplication failed");

        Unsigned u6("111");    // 7 in binary
        Unsigned u7(3);        // 3 in decimal
        Unsigned u8 = u6 * u7; // 21 in binary
        if (u8.to_base(10) != "21") throw runtime_error("TestMultiplication failed");

        // Additional tests
        Unsigned u9("0");
        Unsigned u10(5);
        Unsigned u11 = u9 * u10;
        if (u11.to_base(10) != "0") throw runtime_error("TestMultiplication failed");

        Unsigned u12("101");   // 5 in binary
        Unsigned u13(4);       // 4 in decimal
        Unsigned u14 = u12 * u13; // 20 in binary
        if (u14.to_base(10) != "20") throw runtime_error("TestMultiplication failed");

        cout << "TestMultiplication passed" << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void TestFactorial() {
    try {
        Unsigned result("1");
        int i;
        for (i = 1; i <= 5; ++i) {
            result *= Unsigned(i);
        }
        if (result.to_base(10) != "120") throw runtime_error("TestFactorial failed");

        result = Unsigned("1");
        for (i = 1; i <= 7; ++i) {
            result *= Unsigned(i);
        }
        if (result.to_base(10) != "5040") throw runtime_error("TestFactorial failed");

        // Additional tests
        result = Unsigned("1");
        for (i = 1; i <= 0; ++i) {
            result *= Unsigned(i);
        }
        if (result.to_base(10) != "1") throw runtime_error("TestFactorial failed");

        result = Unsigned("1");
        for (i = 1; i <= 3; ++i) {
            result *= Unsigned(i);
        }
        if (result.to_base(10) != "6") throw runtime_error("TestFactorial failed");

        cout << "TestFactorial passed" << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void TestFibonacci() {
    try {
        Unsigned a("0");
        Unsigned b("1");
        Unsigned c("0");
        int i;
        for (i = 0; i < 10; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        if (a.to_base(10) != "55") throw runtime_error("TestFibonacci failed");

        a = Unsigned("0");
        b = Unsigned("1");
        for (i = 0; i < 15; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        if (a.to_base(10) != "610") throw runtime_error("TestFibonacci failed");

        // Additional tests
        a = Unsigned("0");
        b = Unsigned("1");
        for (i = 0; i < 5; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        if (a.to_base(10) != "5") throw runtime_error("TestFibonacci failed");

        a = Unsigned("0");
        b = Unsigned("1");
        for (i = 0; i < 20; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        if (a.to_base(10) != "6765") throw runtime_error("TestFibonacci failed");

        a = Unsigned("0");
        b = Unsigned("1");
        for (i = 0; i < 100; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        if (a.to_base(10) != "3736710778780434371") throw runtime_error("TestFibonacci failed");

        cout << "TestFibonacci passed" << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

int main() {
    TestAddition();
    TestSubtraction();
    TestMultiplication();
    TestFactorial();
    TestFibonacci();
    return 0;
}
