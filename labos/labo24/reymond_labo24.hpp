#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

class Setbase {
public:
    static int base;
    Setbase(int b) {
        base = b;
    }

    Setbase set_base(int base) {
        Setbase::base = base;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Setbase &) {
        return os;
    }
};

int Setbase::base = 10;

class Unsigned {
private:
    string value;

public:
    Unsigned(const string &binary) : value(binary) {}
    Unsigned(uint64_t number) {
        value = "";
        // Convert the number to binary
        while (number > 0) {
            value = char((number % 2) + '0') + value;
            number /= 2;
        }
        if (value.empty()) {
            value = "0";
        }
    }

    // Removed incorrect set_base function

    string to_base(int base) const {
        if (base == 2) {
            return value;
        }

        uint64_t decimalValue = 0;
        uint64_t basePower = 1;

        // Convert binary to decimal
        for (int i = value.size() - 1; i >= 0; --i) {
            if (value[i] == '1') {
                decimalValue += basePower;
            }
            basePower *= 2;
        }

        // Convert decimal to the specified base
        string result = "";
        do {
            int remainder = decimalValue % base;
            result = char((remainder < 10 ? '0' + remainder : 'a' + remainder - 10)) + result;
            decimalValue /= base;
        } while (decimalValue > 0);
        return result;
    }

    friend bool operator==(const Unsigned &left, const Unsigned &right) {
        return left.value == right.value;
    }

    Unsigned &operator+=(const Unsigned &right) {
        int carry = 0;
        int leftSize = value.size();
        int rightSize = right.value.size();
        string result = "";
        int i = 0;

        while (i < leftSize || i < rightSize || carry != 0) {
            int leftBit = 0;
            if (i < leftSize) {
                leftBit = value[leftSize - 1 - i] - '0';
            }

            int rightBit = 0;
            if (i < rightSize) {
                rightBit = right.value[rightSize - 1 - i] - '0';
            }

            int sum = leftBit + rightBit + carry;
            result = char((sum % 2) + '0') + result;
            carry = sum / 2;
            i++;
        }

        // Pad the result with leading zeros if necessary
        while (result.size() < max(leftSize, rightSize)) {
            result = '0' + result;
        }

        value = result;
        return *this;
    }

    Unsigned &operator-=(const Unsigned &right) {
        int borrow = 0;
        int leftSize = value.size();
        int rightSize = right.value.size();
        string result = "";
        int i = 0;

        while (i < leftSize || i < rightSize || borrow != 0) {
            int leftBit = 0;
            if (i < leftSize) {
                leftBit = value[leftSize - 1 - i] - '0';
            }

            int rightBit = 0;
            if (i < rightSize) {
                rightBit = right.value[rightSize - 1 - i] - '0';
            }

            int diff = leftBit - rightBit - borrow;
            if (diff < 0) {
                diff += 2;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result = char(diff + '0') + result;
            i++;
        }

        // Remove leading zeros
        while (result.size() > 1 && result[0] == '0') {
            result.erase(0, 1);
        }

        value = result;
        return *this;
    }

    Unsigned &operator*=(const Unsigned &right) {
        Unsigned result("0");
        Unsigned temp = *this;

        for (int i = right.value.size() - 1; i >= 0; --i) {
            if (right.value[i] == '1') {
                result += temp;
            }
            // Shift left by 1 bit
            temp.value += '0'; 
        }

        value = result.value;
        return *this;
    }

    Unsigned &operator/=(const Unsigned &right) {
        if (right.value == "0") {
            throw std::invalid_argument("Division by zero");
        }

        Unsigned result("0");
        Unsigned temp("0");

        for (char bit : value) {
            temp.value += bit;
            if (temp.value[0] == '0') {
                temp.value.erase(0, 1);
            }
            result.value += '0';
            while (temp.value.size() > right.value.size() ||
                   (temp.value.size() == right.value.size() && temp.value >= right.value)) {
                temp -= right;
                result.value.back() = '1';
            }
        }

        // Remove leading zeros
        while (result.value.size() > 1 && result.value[0] == '0') {
            result.value.erase(0, 1);
        }

        value = result.value;
        return *this;
    }

    bool operator<(const Unsigned &right) const {
        if (value.size() != right.value.size()) {
            return value.size() < right.value.size();
        }
        return value < right.value;
    }

    bool operator<=(const Unsigned &right) const {
        return !(right < *this);
    }

    bool operator>(const Unsigned &right) const {
        return right < *this;
    }

    bool operator>=(const Unsigned &right) const {
        return !(*this < right);
    }

    Unsigned &operator%=(const Unsigned &right) {
        Unsigned temp("0");

        for (char bit : value) {
            temp.value += bit;
            while (temp.value.size() > right.value.size() ||
                   (temp.value.size() == right.value.size() && temp.value >= right.value)) {
                temp -= right;
            }
        }

        value = temp.value;
        return *this;
    }

    friend Unsigned operator+(Unsigned left, const Unsigned &right) {
        left += right;
        return left;
    }

    friend Unsigned operator-(Unsigned left, const Unsigned &right) {
        left -= right;
        return left;
    }

    friend Unsigned operator*(Unsigned left, const Unsigned &right) {
        left *= right;
        return left;
    }

    friend Unsigned operator/(Unsigned left, const Unsigned &right) {
        return left /= right;
    }

    friend Unsigned operator%(Unsigned left, const Unsigned &right) {
        return left %= right;
    }


    friend ostream &operator<<(ostream &os, const Unsigned &number) {
        os << number.to_base(Setbase::base);
        return os;
    }
    
};

