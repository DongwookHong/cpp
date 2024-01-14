#pragma once
#include <stdint.h>
#include <iostream>

#include "Data.hpp"

class Serializer {
 private:
  Serializer();
  ~Serializer();
  Serializer(Serializer& copy);
  Serializer& operator=(const Serializer& ref);

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};
