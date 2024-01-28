/** @file bitset.hpp
 * @author Mitch McKain
 * @date 1/28/2024 */

#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

/** @class Bitset for reporting information on a series of bits */

class Bitset{
public:

  /** Default Constructor that creates a valid bitset of 8 bits all set to 0 
   * @post a bitset of 8 bits is created
  */
  Bitset();

  /** Alternate Constructor that creates a bitset of user defined size
   * @param size of type intmax_t to set the amount of bits in the bitset
   * @post a valid bitset of a user defined size is created with all bits set to 0
   * @throw error if the parameter size is less than or equal to 0 by setting validity to false
  */
  Bitset(intmax_t size);

  /** Alternate Constructor that creates a bitset identical to user entered bitset string
   * @param value is the bitset to be copied to an object
   * @post a valid bitset is created with user defined size and value
   * @throw error if the paramater value contains numbers other than 1 and 0 by setting validity to false
  */
  Bitset(const std::string & value);

  /** Destructor to destroy the memory allocated for bitset values
   * @pre a pointer for the bitset array must exist somewhere
   * @post the memory is deallocated and freed up
  */
  ~Bitset();

  /** Overloaded equals operator */
  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  /** Accessor method that returns the size of the bitset
   * @pre a bitset must exist
   * @post the user will know how many elements are in the bitset
   * @return the number of bits in the bitset as a type intmax_t
  */
  intmax_t size() const;

  /** Accessor method that returns if the bitset is valid or not
   * @pre a bitset must have been attempted to be created
   * @post the user will know if the bitset is a valid bitset to operate on
   * @return the private member validity of type bool that equals if bitset is valid or not
  */
  bool good() const;

  /** Mutator method that allows a user defined element of the bitset to be set to 1
   * @param index of type intmax_t to determine what element of the bitset is to be set
   * @pre a valid bitset must already exist
   * @post the user defined element of the bitset will now have a 1
   * @throw error if the parameter index is less than 0 or greater than n-1 by setting validity to false
  */
  void set(intmax_t index);

  /** Mutator method that allows a user defined element of the bitset to be set to 0
   * @param index of type intmax_t to determine what element of the bitset is to be set
   * @pre a valid bitset must already exist
   * @post the user defined element of the bitset will now have a 0
   * @throw error if the parameter index is less than 0 or greater than n-1 by setting validity to false
  */
  void reset(intmax_t index);

  /** Mutator methos that allows a user defined element to be toggled to the other value (0/1)
   * @param index of type intmax_t to determine what element of the bitset is to be toggled
   * @pre a valid bitset must already exist
   * @post the user defined element of the bitset will now be the opposite value of what it was
   * @throw error if the parameter index is less than 0 or greater than n-1 by setting validity to false
  */
  void toggle(intmax_t index);

  /** Method to determine if a user defined element of the bitset is set to 1
   * @param index of type intmac_t to determine what element of the bitset is to be evaluated
   * @pre a valid bitset must already exist
   * @post the user will know if their element of the bitset contains a 1 or a 0
   * @return bool that is true if their element of bitset is 1, or false if it is 0 or if index is invalid
   * @throw error if the parameter index is less than 0 or greater than n-1 by setting validity to false, and returning false to user
  */
  bool test(intmax_t index);

  /** Method that returns the bitset as a string
   * @pre a valid bitset must already exist
   * @post the user will have a string of their bitset
   * @return string that is made up of their bitset in 1s and 0s
  */
  std::string asString() const;

private:

  uint8_t *bitset; //array of bits
  bool validity = true; //determines if object is valid or invalid
  intmax_t n; //will be used to hold the size of the bits
};

#endif
