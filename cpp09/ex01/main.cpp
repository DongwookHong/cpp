#include "RPN.hpp"

int main(int ac, char **av) {

    if (ac != 2)
    {
        std::cout << " Error" <<std::endl;
        return 1;
}
  RPN cal(av[1]);
  return 0;
}