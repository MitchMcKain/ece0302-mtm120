/** @file bitset.cpp 
 * @author Mitch McKain
 * @date 1/28/2024*/

#include "bitset.hpp"
#include <iostream>
#include <cstdlib>

Bitset::Bitset() 
{
    bitset = new uint8_t[8];
    n = 8;
    
    for (intmax_t i = 0; i < n; i++)
    {   bitset[i] = 0;  }
}

Bitset::Bitset(intmax_t size) 
{
    n = size;

    if (n > 0)
        {
            validity = true;
            bitset = new uint8_t[n];
            for (intmax_t i = 0; i < n; i++)
                {   bitset[i] = 0;    }
        }
    else
        {
            bitset = new uint8_t[0];
            validity = false;
        }
}

Bitset::Bitset(const std::string & value)
{
    n = value.length();
    bitset = new uint8_t[n];

    for (intmax_t i = 0; i < n; i++ )
        {
            if (value[i] == '0')
                bitset[i] = 0;
            else if(value[i] == '1')
                bitset[i] = 1;
            else
                validity = false;
        }
}

Bitset::~Bitset()
{   delete bitset;    }

intmax_t Bitset::size() const
{ return n; }

bool Bitset::good() const
{   return validity; }

void Bitset::set(intmax_t index)
{
    if ((index < n) && (index >= 0))
        bitset[index] = 1;
    else
        validity = false;
}

void Bitset::reset(intmax_t index)
{
    if ((index < n) && (index >= 0))
        bitset[index] = 0;
    else
        validity = false;
}

void Bitset::toggle(intmax_t index)
{
    if ((index < n) && (index >= 0))
        {
            if (bitset[index] == 0)
                bitset[index] = 1;
            else
                bitset[index] = 0;
        } 
    else
        validity = false;
}

bool Bitset::test(intmax_t index)
{
    if ((index < n) && (index >= 0))
        {
            if (bitset[index] == 1)
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
    std::string result;

    for (intmax_t i = 0; i < n; i++)
    {
        if (*(bitset + i) == 1)
            result += "1";
        else
            result += "0";
    }

    return result;
  }