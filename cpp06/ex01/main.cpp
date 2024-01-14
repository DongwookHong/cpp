#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
  Data data;
  data.num = 7;

  uintptr_t ptr = Serializer::serialize(&data);
  Data* dataPtr = Serializer::deserialize(ptr);

  std::cout << (uintptr_t)&data << std::endl;
  std::cout << ptr << std::endl;

  std::cout << data.num << std::endl;
  std::cout << dataPtr->num << std::endl;
}
