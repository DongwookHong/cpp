#include <iostream>

#include "iter.hpp"
template <typename T>

void printInt(const T& check) {
  std::cout << check << std::endl;
}

template <typename T>
void squareInt(T& value) {
  value = value * value;
  std::cout << value << std::endl;
}

int main(void) {
  int arr[3] = {1, 2, 3};

  iter<int>(arr, 3, printInt);
  iter<int>(arr, 3, squareInt);
  iter<int>(arr, 3, printInt);
}