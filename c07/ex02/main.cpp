#include <iostream>

#include "Array.hpp"

int main(void) {
  try {
    Array<int> arr(3);
    // const Array<const int> arr_const(3);

    // const int* ptr = new int[2]P;
    arr[0] = 3;
    std::cout << arr[0] << std::endl;
    // std::cout << arr_const[0] << std::endl;

    // arr[0] = 10;
    // arr[1] = 3;
    // arr[2] = 7;
    // std::cout << arr[0] << std::endl;
    // std::cout << arr[1] << std::endl;
    // std::cout << arr[2] << std::endl;
    // std::cout << arr[3] << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}