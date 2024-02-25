#include  "PmergeMe.hpp"


int main(int ac, char **av) {
  try {
    if (ac < 2)
      throw std::runtime_error("Error : not enough arguments");
    else {
      PmergeMe pm;
      pm.start(ac, av);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}