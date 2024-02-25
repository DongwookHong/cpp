#include "PmergeME.hpp"

int main(int ac, char **av) {
  try {
    if (ac <= 2 )
      throw std::runtime_error("Error : not enough arguments or already sorted");
    else {
      PmergeME pm;
      pm.execute(ac, av);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}