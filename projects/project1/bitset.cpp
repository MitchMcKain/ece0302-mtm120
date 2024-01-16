#include "bitset.hpp"

Bitset::Bitset() 
{
    for (int i = 0; i < 8; i++)
    {
        byte[i] = 0;
        validity = true;
    }
}

Bitset::Bitset(intmax_t size) {
    // TODO
}

Bitset::Bitset(const std::string & value) {
    // TODO
}

Bitset::~Bitset() {
    // TODO
}

// TODO: other methods
