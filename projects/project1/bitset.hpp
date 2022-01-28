#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>
#include <iostream>
#include <stdlib.h>

class Bitset{
public:

  // Default Constructor that makes a bitset with 8 bytes
  Bitset();

  // 2nd Constructor that make a bitset with the size that the user supplies
  Bitset(intmax_t size);

  // 3rd Constructor tha makes a bitset with the string inputted
  Bitset(const std::string & value);

  // Deletes the bitset array
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // Returns the size of the bitset
  intmax_t size() const;

  // Tells you if the bitset is valid or nah
  bool good() const;

  // Sets the bit at the index to 1
  void set(intmax_t index);

  // Sets the bit at the index to 0
  void reset(intmax_t index);

  // Sets the bit at the index to the opposite. For ex. if it is '1' it is set to '0'
  void toggle(intmax_t index);

  // Tells you if the value at that index is 1
  bool test(intmax_t index);

  // Returns your bitset as a string
  std::string asString() const;

private:

  // TODO
  bool valid = true; //tells us if valid or nah
  intmax_t bSize; //Size of bitArr
  intmax_t *bitArr = new intmax_t[8]; //Holds the bit array
  
};

#endif
