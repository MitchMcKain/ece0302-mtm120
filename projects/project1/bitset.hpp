#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{
public:

  // Default Constructor
  Bitset();

  // Alternate Constructor
  Bitset(intmax_t size);

  // TODO COMMENT
  Bitset(const std::string & value);

  // TODO COMMENT
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // TODO COMMENT
  intmax_t size() const;

  // TODO COMMENT
  bool good() const;

  // TODO COMMENT
  void set(intmax_t index);

  // TODO COMMENT
  void reset(intmax_t index);

  // TODO COMMENT
  void toggle(intmax_t index);

  // TODO COMMENT
  bool test(intmax_t index);

  // TODO COMMENT
  std::string asString() const;

private:

  bool byte[8]; //array of bits, why cant i have this array undefined size
  bool validity; //determines if object is valid or invalid
};

#endif
