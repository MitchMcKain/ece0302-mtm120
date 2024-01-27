#include "bitset.hpp"
#include <iostream>
#include <cstdlib>

Bitset::Bitset() 
{
    bits = new uint8_t[8];
    n = 8;
    
    for (int i = 0; i < n; i++)
    {   bits[i] = 0;
        std::cout << bits[i]<<std::endl;    }
}

Bitset::Bitset(intmax_t size) 
{
    bits = new uint8_t[size];
    n = size;

    if (size <= 0)
    validity = false;
    
    for (int i = 0; i < n; i++)
    {   bits[i] = 0;    }
}

Bitset::Bitset(const std::string & value)
{
    bits = new uint8_t[value.length()];
    n = value.length();

    for (int i = 0; i < n; i++ )
        {
            if (value[i] == '0')
                bits[i] = 0;
            else if(value[i] == '1')
                bits[i] = 1;
            else
                validity = false;
        }
}

Bitset::~Bitset()
{   delete[] bits;    }

intmax_t Bitset::size() const
{ return n; }

bool Bitset::good() const
{   return validity; }

void Bitset::set(intmax_t index)
{
    if ((index < n) && (index >= 0))
        bits[index] = 1;
    else
        validity = false;
}

void Bitset::reset(intmax_t index)
{
    if ((index < n) && (index >= 0))
        bits[index] = 0;
    else
        validity = false;
}

void Bitset::toggle(intmax_t index)
{
    if ((index < n) && (index >= 0))
        {
            if (bits[index] == 0)
                bits[index] = 1;
            else
                bits[index] = 0;
        } 
    else
        validity = false;
}

bool Bitset::test(intmax_t index)
{
    if ((index < n) && (index >= 0))
        {
            if (bits[index] == 1)
                return true;
            else
                return false;
        }
    else
        {
            validity = false;
            return false;
        }
}

  std::string Bitset::asString() const
  {
    std::string result = "";
    for (int i = 0; i < n; i++)
    {
        result += bits[n];
    }
    return result;
  }
