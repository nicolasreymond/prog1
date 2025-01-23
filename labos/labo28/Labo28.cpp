#include "Unsigned.hpp"
#include <iostream>
#include <cstdlib>
#include <numeric>
#include <ctime>

class Int
{
private:
    bool sign;
    Unsigned value;

public:
    Int();
    Int(const std::string &binary);
    Int(int64_t number);
    std::string to_base(int base) const;
    int64_t to_int64() const;
    std::string data() const;
    operator int64_t() const;
    Int &operator+=(const Int &right);
    Int &operator-=(const Int &right);
    Int &operator*=(const Int &right);
    Int &operator/=(const Int &right);
    Int &operator%=(const Int &right);
    bool operator<(const Int &right) const;
    bool operator<=(const Int &right) const;
    bool operator>(const Int &right) const;
    bool operator>=(const Int &right) const;
    bool operator==(const Int &right) const;
    bool operator!=(const Int &right) const;
    bool operator<(int64_t right) const;
    bool operator<=(int64_t right) const;
    bool operator>(int64_t right) const;
    bool operator>=(int64_t right) const;
    bool operator==(int64_t right) const;
    bool operator!=(int64_t right) const;
    Int operator+(int64_t right) const;
    Int operator-(int64_t right) const;
    Int operator*(int64_t right) const;
    Int operator/(int64_t right) const;
    Int operator%(int64_t right) const;
    friend Int operator+(Int left, const Int &right);
    friend Int operator-(Int left, const Int &right);
    friend Int operator*(Int left, const Int &right);
    friend Int operator/(Int left, const Int &right);
    friend Int operator%(Int left, const Int &right);
    friend std::ostream &operator<<(std::ostream &os, const Int &number);
    Int &operator++();
    Int operator++(int);
    Int &operator--();
    Int operator--(int);

    // Function to perform modular exponentiation
    static Int modExp(Int base, Int exp, Int mod) {
        Int result(1);
        while (exp > Int(0)) {
            if (exp % Int(2) == Int(1)) {
                result = (result * base) % mod;
                exp = exp - Int(1);
            } else {
                base = (base * base) % mod;
                exp = exp / Int(2);
            }
        }
        return result;
    }

    // Function to check if a number is prime
    static bool isPrime(Int p) {
        if (p.to_int64() < 2) return false;
        if (p.to_int64() == 2) return true;
        for (int i = 0; i < 10; ++i) {
            Int a = Int(rand()) % (p - Int(1)) + Int(1);
            if (modExp(a, p - Int(1), p) != Int(1)) return false;
            Int q(Int(1)), u = p - Int(1);
            while (u % Int(2) == Int(0) && q == Int(1)) {
                u = u / Int(2);
                q = modExp(a, u, p);
                if (q != Int(1) && q != p - Int(1)) return false;
            }
        }
        return true;
    }

    // Function to generate RSA keys
    static void generateRSAKeys(Int& e, Int& d, Int& n) {
        srand(time(0));
        Int p, q;
        do { p = Int(rand() % 100 + 2); } while (!isPrime(p));
        do { q = Int(rand() % 100 + 2); } while (!isPrime(q) || q == p);
        n = p * q;
        Int phi = (p - Int(1)) * (q - Int(1));
        do { e = Int(rand() % (phi.to_int64() - 1) + 1); } while (std::gcd(e.to_int64(), phi.to_int64()) != 1);
        d = modInverse(e, phi);
    }

    // Function to compute modular inverse using Extended Euclidean Algorithm
    static Int modInverse(Int a, Int m) {
        Int m0 = m, t, q;
        Int x0(0), x1(1);
        if (m == Int(1)) return Int(0);
        while (a > Int(1)) {
            q = a / m;
            t = m;
            m = a % m, a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < Int(0)) x1 += m0;
        return x1;
    }

    // Function to encrypt a message
    static Int encrypt(Int m, Int e, Int n) {
        return modExp(m, e, n);
    }

    // Function to decrypt a message
    static Int decrypt(Int c, Int d, Int n) {
        return modExp(c, d, n);
    }
};

Int::Int() : sign(false), value(0) {}

Int::Int(const std::string &binary) {
    if (binary.empty()) {
        throw std::invalid_argument("Empty string");
    }
    sign = binary[0] == '-';
    value = Unsigned(sign ? binary.substr(1) : binary);}

Int::Int(int64_t number) {
    sign = number < 0;
    value = Unsigned(sign ? -number : number);}

int64_t Int::to_int64() const {
    uint64_t result = static_cast<uint64_t>(value);
    return sign ? -static_cast<int64_t>(result) : static_cast<int64_t>(result);}

Int::operator int64_t() const {return to_int64();}

Int &Int::operator+=(const Int &right) {
    if (sign == right.sign) {
        value += right.value;
    } else {
        if (value < right.value) {
            sign = !sign;
            value = right.value - value;
        } else {
            value -= right.value;
        }
    }
    return *this;
}

Int &Int::operator-=(const Int &right) {
    if (sign == right.sign) {
        if (value < right.value) {
            sign = !sign;
            value = right.value - value;
        } else {
            value -= right.value;
        }
    } else {
        value += right.value;
    }
    return *this;
}

Int &Int::operator*=(const Int &right) {
    sign = sign != right.sign;
    value *= right.value;
    return *this;
}

Int &Int::operator/=(const Int &right) {
    sign = sign != right.sign;
    value /= right.value;
    return *this;
}


bool Int::operator<(const Int &right) const {
    if (sign != right.sign) {
        return sign;
    }
    if (sign) {
        return value > right.value;
    }
    return value < right.value;
}

bool Int::operator<=(const Int &right) const {return *this < right || *this == right;}
bool Int::operator>(const Int &right) const {return !(*this <= right);}
bool Int::operator>=(const Int &right) const {return !(*this < right);}
bool Int::operator==(const Int &right) const {return sign == right.sign && value == right.value;}
bool Int::operator!=(const Int &right) const {return !(*this == right);}
bool Int::operator<(int64_t right) const {return *this < Int(right);}
bool Int::operator<=(int64_t right) const {return *this <= Int(right);}
bool Int::operator>(int64_t right) const {return *this > Int(right);}
bool Int::operator>=(int64_t right) const {return *this >= Int(right);}
bool Int::operator==(int64_t right) const {return *this == Int(right);}
bool Int::operator!=(int64_t right) const {return *this != Int(right);}
Int Int::operator+(int64_t right) const {return *this + Int(right);}
Int Int::operator-(int64_t right) const {return *this - Int(right);}
Int Int::operator*(int64_t right) const {return *this * Int(right);}
Int Int::operator/(int64_t right) const {return *this / Int(right);}
Int Int::operator%(int64_t right) const {return *this % Int(right);}
Int operator+(Int left, const Int &right) {
    left += right;
    return left;
}
Int operator-(Int left, const Int &right) {
    left -= right;
    return left;
}
Int operator*(Int left, const Int &right) {
    left *= right;
    return left;
}
Int operator/(Int left, const Int &right) {
    left /= right;
    return left;
}
Int operator%(Int left, const Int &right) {
    left %= right;
    return left;
}
Int& Int::operator%=(const Int& right) {
    value %= right.value;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Int &number) {
    if (number.sign) {
        os << '-';
    } else if (os.flags() & std::ios::showpos && !number.sign) {
        os << '+';
    }

    if (os.flags() & std::ios::showbase) {
        if (os.flags() & std::ios::hex) {
            os << "0x";
        } else if (os.flags() & std::ios::oct) {
            os << "0";
        }
    }

    os << number.value;
    return os;}

Int &Int::operator++() {
    *this += Int(1);
    return *this;
}

Int Int::operator++(int) {
    Int temp = *this;
    ++(*this);
    return temp;}

Int &Int::operator--() {
    *this -= Int(1);
    return *this;
}

Int Int::operator--(int) {
    Int temp = *this;
    --(*this);
    return temp;}

// Test the RSA implementation
int main() {
    Int e, d, n;
    Int::generateRSAKeys(e, d, n);
    std::cout << "Public Key: (" << e << ", " << n << ")\n";
    std::cout << "Private Key: (" << d << ", " << n << ")\n";

    Unsigned message("123456789009876543211234567890");
    Int encrypted = Int::encrypt(Int(message.data()), e, n);
    Int decrypted = Int::decrypt(encrypted, d, n);

    std::cout << "Original Message: " << message << "\n";
    std::cout << "Encrypted Message: " << encrypted << "\n";
    std::cout << "Decrypted Message: " << decrypted << "\n";

    return 0;}