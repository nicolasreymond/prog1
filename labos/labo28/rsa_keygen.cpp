#include "Unsigned.hpp"
#include "rsa_keygen.hpp"
#include "is_prime.hpp"
#include "modular_math.hpp"
#include <cstdlib>
#include <ctime>

Unsigned generateLargePrime(int bitLength) {
    while (true) {
        Unsigned num = Unsigned::random(bitLength);
        if (isPrime(num)) return num;
    }
}

std::pair<Unsigned, Unsigned> generateKeys(Unsigned &publicKey, Unsigned &privateKey) {
    srand(time(0));
    Unsigned p = generateLargePrime(512); // Generate 512-bit primes
    Unsigned q = generateLargePrime(512);
    while (p == q) q = generateLargePrime(512);

    Unsigned n = p * q;
    Unsigned phi = (p - 1) * (q - 1);

    publicKey = 3;
    Unsigned x, y;
    while (gcdExtended(publicKey, phi, x, y) != 1) publicKey++;

    privateKey = gcdExtended(phi, publicKey, x, y);
    if (privateKey < 0) privateKey += phi;

    return {n, publicKey};
}
