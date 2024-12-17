#include <gtest/gtest.h>
#include "../reymond_labo24.hpp"
#include <iostream>
#include <exception>

using namespace std;

class TestAddition : public ::testing::Test {};
class TestSubtraction : public ::testing::Test {};
class TestMultiplication : public ::testing::Test {};
class TestFactorial : public ::testing::Test {};
class TestFibonacci : public ::testing::Test {};
class TestDivision : public ::testing::Test {};
class TestModulo : public ::testing::Test {};
class TestShortBinary : public ::testing::Test {};
class TestLongBinary : public ::testing::Test {};
class ShowBinary : public ::testing::Test {};
class TestSetBase : public ::testing::Test {};

TEST_F(TestDivision, LargeNumbers)
{
    Unsigned u1("13763753091226345046315979581580902400000000");
    Unsigned u2("371993326789901217467999448150835200000000");
    Unsigned u3 = u1 / u2;
    EXPECT_EQ(u3.to_base(10), "37");
    EXPECT_NE(u3.to_base(10), "36");

    Unsigned u4("10333147966386144929666651337523200000000");
    Unsigned u5("295232799039604140847618609643520000000");
    Unsigned u6 = u4 / u5;
    EXPECT_EQ(u6.to_base(10), "35");
    EXPECT_NE(u6.to_base(10), "34");
}

TEST_F(TestModulo, LargeNumbers)
{
    Unsigned u1("13763753091226345046315979581580902400000000");
    Unsigned u2("371993326789901217467999448150835200000000");
    Unsigned u3 = u1 % u2;
    EXPECT_EQ(u3.to_base(10), "0");
    EXPECT_NE(u3.to_base(10), "1");

    Unsigned u4("10333147966386144929666651337523200000000");
    Unsigned u5("295232799039604140847618609643520000000");
    Unsigned u6 = u4 % u5;
    EXPECT_EQ(u6.to_base(10), "0");
    EXPECT_NE(u6.to_base(10), "1");
}

TEST_F(ShowBinary, LargeNumbers)
{
    Unsigned u1("13763753091226345046315979581580902400000000");
    EXPECT_EQ(u1.to_base(36), "DX80IZ5DFNBWN51XC0000000");
    EXPECT_NE(u1.to_base(36), "DX80IZ5DFNBWN51XC0000001");

    Unsigned u2("371993326789901217467999448150835200000000");
    EXPECT_EQ(u2.to_base(36), "S7XULVW9L4T5CO8N71F0000");
    EXPECT_NE(u2.to_base(36), "S7XULVW9L4T5CO8N71F0001");

    Unsigned u3("10333147966386144929666651337523200000000");
    EXPECT_EQ(u3.to_base(36), "1MPGR1D8L2PPC8WST73HBU0");
    EXPECT_NE(u3.to_base(36), "1MPGR1D8L2PPC8WST73HBU1");

    Unsigned u4("295232799039604140847618609643520000000");
    EXPECT_EQ(u4.to_base(36), "3E2JRL77RF2MDNB1112600");
    EXPECT_NE(u4.to_base(36), "3E2JRL77RF2MDNB1112601");
}

TEST_F(TestDivision, DivisionByZero)
{
    Unsigned u1("10");
    Unsigned u2("0");
    EXPECT_THROW(u1 / u2, std::invalid_argument);
}

TEST_F(TestSubtraction, NegativeResult)
{
    Unsigned u1("10");
    Unsigned u2("20");
    EXPECT_THROW(u1 - u2, std::invalid_argument);
}

TEST_F(TestAddition, BasicTests) {
    Unsigned u1("1010");   // 10 in binary
    Unsigned u2(10);       // 10 in decimal
    Unsigned u3 = u1 + u2; // 20 in binary
    cout << u1 << endl;
    cout << u2 << endl;
    cout << u3 << endl;
    EXPECT_EQ(u3.to_base(10), "20");
    EXPECT_NE(u3.to_base(10), "21");

    Unsigned u4("1111");   // 15 in binary
    Unsigned u5(5);        // 5 in decimal
    Unsigned u6 = u4 + u5; // 20 in binary
    EXPECT_EQ(u6.to_base(10), "20");
    EXPECT_NE(u6.to_base(10), "19");

    // Additional tests
    Unsigned u7("0");
    Unsigned u8(0);
    Unsigned u9 = u7 + u8;
    EXPECT_EQ(u9.to_base(10), "0");
    EXPECT_NE(u9.to_base(10), "1");

    Unsigned u10("1001");  // 9 in binary
    Unsigned u11(1);       // 1 in decimal
    Unsigned u12 = u10 + u11; // 10 in binary
    EXPECT_EQ(u12.to_base(10), "10");
    EXPECT_NE(u12.to_base(10), "11");
}

TEST_F(TestSubtraction, BasicTests) {
    Unsigned u1("1010");   // 10 in binary
    Unsigned u2(10);       // 10 in decimal
    Unsigned u4 = u1 - u2; // 0 in binary
    EXPECT_EQ(u4.to_base(10), "0");
    EXPECT_NE(u4.to_base(10), "1");

    Unsigned u5("1111");   // 15 in binary
    Unsigned u6(5);        // 5 in decimal
    Unsigned u7 = u5 - u6; // 10 in binary
    EXPECT_EQ(u7.to_base(10), "10");
    EXPECT_NE(u7.to_base(10), "9");

    // Additional tests
    Unsigned u8("1000");   // 8 in binary
    Unsigned u9(3);        // 3 in decimal
    Unsigned u10 = u8 - u9; // 5 in binary
    EXPECT_EQ(u10.to_base(10), "5");
    EXPECT_NE(u10.to_base(10), "6");

    Unsigned u11("1010");  // 10 in binary
    Unsigned u12(0);       // 0 in decimal
    Unsigned u13 = u11 - u12; // 10 in binary
    EXPECT_EQ(u13.to_base(10), "10");
    EXPECT_NE(u13.to_base(10), "11");
}

TEST_F(TestMultiplication, BasicTests) {
    Unsigned u1("1010");   // 10 in binary
    Unsigned u2(10);       // 10 in decimal
    Unsigned u5 = u1 * u2; // 100 in binary
    EXPECT_EQ(u5.to_base(10), "100");
    EXPECT_NE(u5.to_base(10), "101");

    Unsigned u6("111");    // 7 in binary
    Unsigned u7(3);        // 3 in decimal
    Unsigned u8 = u6 * u7; // 21 in binary
    EXPECT_EQ(u8.to_base(10), "21");
    EXPECT_NE(u8.to_base(10), "22");

    // Additional tests
    Unsigned u9("0");
    Unsigned u10(5);
    Unsigned u11 = u9 * u10;
    EXPECT_EQ(u11.to_base(10), "0");
    EXPECT_NE(u11.to_base(10), "1");

    Unsigned u12("101");   // 5 in binary
    Unsigned u13(4);       // 4 in decimal
    Unsigned u14 = u12 * u13; // 20 in binary
    EXPECT_EQ(u14.to_base(10), "20");
    EXPECT_NE(u14.to_base(10), "21");
}
TEST_F(TestDivision, BasicTests){
    Unsigned u1("1010");   // 10 in binary
    Unsigned u2(10);       // 10 in decimal
    Unsigned u5 = u1 / u2; // 1 in binary
    EXPECT_EQ(u5.to_base(10), "1");
    EXPECT_NE(u5.to_base(10), "2");

    Unsigned u6("111");    // 7 in binary
    Unsigned u7(3);        // 3 in decimal
    Unsigned u8 = u6 / u7; // 2 in binary
    EXPECT_EQ(u8.to_base(10), "2");
    EXPECT_NE(u8.to_base(10), "3");

    // Additional tests
    Unsigned u9("0");
    Unsigned u10(5);
    Unsigned u11 = u9 / u10;
    EXPECT_EQ(u11.to_base(10), "0");
    EXPECT_NE(u11.to_base(10), "1");

    Unsigned u12("101");   // 5 in binary
    Unsigned u13(4);       // 4 in decimal
    Unsigned u14 = u12 / u13; // 1 in binary
    EXPECT_EQ(u14.to_base(10), "1");
    EXPECT_NE(u14.to_base(10), "2");
}

TEST_F(TestModulo, BasicTests){
    Unsigned u1("1010");   // 10 in binary
    Unsigned u2(10);       // 10 in decimal
    Unsigned u5 = u1 % u2; // 0 in binary
    EXPECT_EQ(u5.to_base(10), "0");
    EXPECT_NE(u5.to_base(10), "1");

    Unsigned u6("111");    // 7 in binary
    Unsigned u7(3);        // 3 in decimal
    Unsigned u8 = u6 % u7; // 1 in binary
    EXPECT_EQ(u8.to_base(10), "1");
    EXPECT_NE(u8.to_base(10), "2");

    // Additional tests
    Unsigned u9("0");
    Unsigned u10(5);
    Unsigned u11 = u9 % u10;
    EXPECT_EQ(u11.to_base(10), "0");
    EXPECT_NE(u11.to_base(10), "1");

    Unsigned u12("101");   // 5 in binary
    Unsigned u13(4);       // 4 in decimal
    Unsigned u14 = u12 % u13; // 1 in binary
    EXPECT_EQ(u14.to_base(10), "1");
    EXPECT_NE(u14.to_base(10), "2");
}

TEST_F(TestFactorial, BasicTests) {
    Unsigned result("1");
    int i;
    for (i = 1; i <= 5; ++i) {
        result *= Unsigned(i);
    }
    EXPECT_EQ(result.to_base(10), "120");
    EXPECT_NE(result.to_base(10), "121");

    result = Unsigned("1");
    for (i = 1; i <= 7; ++i) {
        result *= Unsigned(i);
    }
    EXPECT_EQ(result.to_base(10), "5040");
    EXPECT_NE(result.to_base(10), "5041");

    // Additional tests
    result = Unsigned("1");
    for (i = 1; i <= 0; ++i) {
        result *= Unsigned(i);
    }
    EXPECT_EQ(result.to_base(10), "1");
    EXPECT_NE(result.to_base(10), "2");

    result = Unsigned("1");
    for (i = 1; i <= 3; ++i) {
        result *= Unsigned(i);
    }
    EXPECT_EQ(result.to_base(10), "6");
    EXPECT_NE(result.to_base(10), "7");
}

TEST_F(TestFibonacci, BasicTests) {
    Unsigned a("0");
    Unsigned b("1");
    Unsigned c("0");
    int i;
    for (i = 0; i < 10; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    EXPECT_EQ(a.to_base(10), "55");
    EXPECT_NE(a.to_base(10), "56");

    a = Unsigned("0");
    b = Unsigned("1");
    for (i = 0; i < 15; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    EXPECT_EQ(a.to_base(10), "610");
    EXPECT_NE(a.to_base(10), "611");

    // Additional tests
    a = Unsigned("0");
    b = Unsigned("1");
    for (i = 0; i < 5; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    EXPECT_EQ(a.to_base(10), "5");
    EXPECT_NE(a.to_base(10), "6");

    a = Unsigned("0");
    b = Unsigned("1");
    for (i = 0; i < 20; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    EXPECT_EQ(a.to_base(10), "6765");
    EXPECT_NE(a.to_base(10), "6766");

    a = Unsigned("0");
    b = Unsigned("1");
    for (i = 0; i < 100; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    EXPECT_EQ(a.to_base(10), "3736710778780434371");
    EXPECT_NE(a.to_base(10), "3736710778780434372");
}

TEST_F(TestShortBinary, BasicTests) {
    Unsigned u1("1");   // 1 in binary
    Unsigned u2(1);     // 1 in decimal
    Unsigned u3 = u1 + u2; // 2 in binary
    EXPECT_EQ(u3.to_base(10), "2");
    EXPECT_NE(u3.to_base(10), "3");

    Unsigned u4("10");  // 2 in binary
    Unsigned u5(1);     // 1 in decimal
    Unsigned u6 = u4 - u5; // 1 in binary
    EXPECT_EQ(u6.to_base(10), "1");
    EXPECT_NE(u6.to_base(10), "0");

    Unsigned u7("11");  // 3 in binary
    Unsigned u8(2);     // 2 in decimal
    Unsigned u9 = u7 * u8; // 6 in binary
    EXPECT_EQ(u9.to_base(10), "6");
    EXPECT_NE(u9.to_base(10), "7");

    Unsigned u10("1");  // 1 in binary
    Unsigned u11(0);    // 0 in decimal
    Unsigned u12 = u10 - u11; // 1 in binary
    EXPECT_EQ(u12.to_base(10), "1");
    EXPECT_NE(u12.to_base(10), "2");
}

TEST_F(TestLongBinary, BasicTests) {
    Unsigned u1("0000000000");   // 0 in binary
    Unsigned u2(0);       // 0 in decimal
    Unsigned u3 = u1 + u2; // 0 in binary

    EXPECT_EQ(u3.to_base(10), "0");
    EXPECT_NE(u3.to_base(10), "1");
    
    Unsigned u4("00101");   // 5 in binary
    Unsigned u5(5);       // 5 in decimal
    Unsigned u6 = u4 + u5; // 10 in binary
    EXPECT_EQ(u6.to_base(10), "10");
    EXPECT_NE(u6.to_base(10), "11");

    Unsigned u7("0010110011");   // 179 in binary
    Unsigned u8(5);       // 5 in decimal
    Unsigned u9 = u7 + u8; // 184 in binary
    EXPECT_EQ(u9.to_base(10), "184");
    EXPECT_NE(u9.to_base(10), "321");
}

TEST_F(ShowBinary, BasicTests) {
    Unsigned u1("1010"); // 10 in binary
    EXPECT_EQ(u1.to_base(2), "1010");
    EXPECT_NE(u1.to_base(2), "1011");

    Unsigned u2("1111"); // 15 in binary
    EXPECT_EQ(u2.to_base(2), "1111");
    EXPECT_NE(u2.to_base(2), "1110");

    Unsigned u3("100000"); // 32 in binary
    EXPECT_EQ(u3.to_base(2), "100000");
    EXPECT_NE(u3.to_base(2), "100001");

    Unsigned u4("0"); // 0 in binary
    EXPECT_EQ(u4.to_base(2), "0");
    EXPECT_NE(u4.to_base(2), "1");
}

TEST_F(TestSetBase, BasicTests) {
    Unsigned number(42); // Decimal 42 -> Binary "101010"

    stringstream ss;
    ss << Setbase(2) << number;
    EXPECT_EQ(ss.str(), "101010");

    ss.str("");
    ss << Setbase(8) << number;
    EXPECT_EQ(ss.str(), "52");

    ss.str("");
    ss << Setbase(10) << number;
    EXPECT_EQ(ss.str(), "42");

    ss.str("");
    ss << Setbase(16) << number;
    EXPECT_EQ(ss.str(), "2a");

    ss.str("");
    ss << Setbase(4) << number;
    EXPECT_EQ(ss.str(), "222");


}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
