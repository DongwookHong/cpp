#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat test("oriana", 30);
    std::cout << test << std::endl;

  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
