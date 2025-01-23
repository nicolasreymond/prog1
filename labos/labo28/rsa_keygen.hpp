#ifndef RSA_KEYGEN_HPP
#define RSA_KEYGEN_HPP

#include <utility>
#include "Unsigned.hpp"

std::pair<Unsigned, Unsigned> generateKeys(Unsigned &publicKey, Unsigned &privateKey);

#endif // RSA_KEYGEN_HPP
