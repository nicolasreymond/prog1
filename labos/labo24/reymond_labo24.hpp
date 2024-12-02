/**
 * @file    reymond_labo24.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief
 * @version 1.0
 * @date    20-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

class Unsigned {
    private:
        string value;

    public:

        Unsigned(const string &binary) : value(binary) {}
        Unsigned(uint64_t number)
        {
            value = "";
            // Convert the number to binary
            while (number > 0)
            {
                value = char((number % 2) + '0') + value;
                number /= 2;
            }
            if (value.empty())
            {
                value = "0";
            }
        }

        string to_decimal() const
        {
            uint64_t result = 0;
            uint64_t power = 1;
            for (int i = value.size() - 1; i >= 0; --i)
            {
                if (value[i] == '1')
                {
                    result += power;
                }
                power *= 2;
            }
            return to_string(result);
        }

        string getValue() {
            return value;
        }

        friend bool operator==(const Unsigned &left, const Unsigned &right)
        {
            return left.value == right.value;
        }

        Unsigned &operator+=(const Unsigned &right)
        {
            int carry = 0;
            int leftSize = value.size();
            int rightSize = right.value.size();
            string result = "";
            int i = 0;

            while (i < leftSize || i < rightSize || carry != 0)
            {
                int leftBit = 0;
                if (i < leftSize)
                {
                    leftBit = value[leftSize - 1 - i] - '0';
                }

                int rightBit = 0;
                if (i < rightSize)
                {
                    rightBit = right.value[rightSize - 1 - i] - '0';
                }

                int sum = leftBit + rightBit + carry;
                result = char((sum % 2) + '0') + result;
                carry = sum / 2;
                i++;
            }

            value = result;
            return *this;
        }

        Unsigned &operator-=(const Unsigned &right)
        {
            int borrow = 0;
            int leftSize = value.size();
            int rightSize = right.value.size();
            string result = "";
            int i = 0;

            while (i < leftSize || i < rightSize || borrow != 0)
            {
                int leftBit = 0;
                if (i < leftSize)
                {
                    leftBit = value[leftSize - 1 - i] - '0';
                }

                int rightBit = 0;
                if (i < rightSize)
                {
                    rightBit = right.value[rightSize - 1 - i] - '0';
                }

                int diff = leftBit - rightBit - borrow;
                if (diff < 0)
                {
                    diff += 2;
                    borrow = 1;
                }
                else
                {
                    borrow = 0;
                }

                result = char(diff + '0') + result;
                i++;
            }

            // Remove leading zeros
            while (result.size() > 1 && result[0] == '0')
            {
                result.erase(0, 1);
            }

            value = result;
            return *this;
        }

        Unsigned &operator*=(const Unsigned &right)
        {
            Unsigned result("0");
            Unsigned temp = *this;

            for (int i = right.value.size() - 1; i >= 0; --i)
            {
                if (right.value[i] == '1')
                {
                    result += temp;
                }
                temp.value += '0'; // Shift left by 1 bit
            }

            value = result.value;
            return *this;
        }

        friend Unsigned operator/= (Unsigned left, const Unsigned &right)
        {
            Unsigned result("0");
            Unsigned temp("0");

            for (char bit : left.value)
            {
                temp.value += bit;
                while (temp.value.size() > right.value.size() || 
                       (temp.value.size() == right.value.size() && temp.value >= right.value))
                {
                    temp -= right;
                    result.value += '1';
                }
                result.value += '0';
            }

            // Remove leading zeros
            while (result.value.size() > 1 && result.value[0] == '0')
            {
                result.value.erase(0, 1);
            }

            left.value = result.value;
            return left;
        }


        friend Unsigned operator+(Unsigned left, const Unsigned &right)
        {
            left += right;
            return left;
        }

        friend Unsigned operator-(Unsigned left, const Unsigned &right)
        {
            left -= right;
            return left;
        }

        friend Unsigned operator*(Unsigned left, const Unsigned &right)
        {
            left *= right;
            return left;
        }
    };

    // int main(void)
    // {
    //     Unsigned u1("1010");    // 10   in binary
    //     Unsigned u2(10);        // 10   in decimal
    //     Unsigned u3 = u1 + u2;  // 20   in binary
    //     Unsigned u4 = u1 - u2;  // 0    in binary
    //     Unsigned u5 = u1 * u2;  // 100  in binary

    //     cout << "u1 (binary 1010): " << u1.to_decimal() << " in decimal" << endl;
    //     cout << "u2 (decimal 10): " << u2.getValue() << " in binary" << endl;
    //     cout << "u3 (u1 + u2): " << u3.to_decimal() << " in decimal" << endl;
    //     cout << "u4 (u1 - u2): " << u4.to_decimal() << " in decimal" << endl;
    //     cout << "u5 (u1 * u2): " << u5.to_decimal() << " in decimal" << endl;
        
    //     return 0;
    // }