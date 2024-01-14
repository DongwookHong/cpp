#include <math.h>

#include <iostream>

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "valuse must be one" << std::endl;
    return 1;
  }
  std::string str = av[1];
  ScalarConverter::ConvertForm(str);
}
