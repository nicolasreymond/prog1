/**
 * @file    reymond_labo28.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   RSA encryption and decryption
 * @version 1.0
 * @date    06-01-2025
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "is_prime.hpp"
#include "rsa_keygen.hpp"
#include "modular_math.hpp"
#include "Unsigned.hpp"
#include <iostream>

int main() {
    Unsigned publicKey, privateKey;
    auto [n, e] = generateKeys(publicKey, privateKey);

    std::cout << "Clé publique : (" << e.to_base(10) << ", " << n.to_base(10) << ")\n";
    std::cout << "Clé privée : " << privateKey.to_base(10) << "\n";

    Unsigned message = Unsigned::random(256);
    std::cout << "Message original : " << message.to_base(10) << "\n";

    Unsigned encrypted = modExp(message, publicKey, n);
    std::cout << "Message chiffré : " << encrypted.to_base(10) << "\n";

    Unsigned decrypted = modExp(encrypted, privateKey, n);
    std::cout << "Message déchiffré : " << decrypted.to_base(10) << "\n";

    return 0;
}
