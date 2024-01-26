#include "bitset.hpp"

Bitset::Bitset() 
{
    for (int i = 0; i < 8; i++)
    {
        bits[i] = 0;
    }
    validity = true;
}

Bitset::Bitset(intmax_t size) 
{
    if (size <= 0)
    validity = false;
    else
    validity = true;
    
    for (int i = 0; i < size; i++)
    {
        bits[i] = 0;
    }
}

Bitset::Bitset(const std::string & value)
{
    // TODO
}

Bitset::~Bitset()
{
    // TODO
}

intmax_t Bitset::size() const
{ return 0; }

bool Bitset::good() const
{
    return 0;
}

void Bitset::set(intmax_t index)
{

}

void Bitset::reset(intmax_t index)
{

}

void Bitset::toggle(intmax_t index)
{

}

bool Bitset::test(intmax_t index)
{
    return 0;
}

  std::string Bitset::asString() const
  {
    return "";
  }
