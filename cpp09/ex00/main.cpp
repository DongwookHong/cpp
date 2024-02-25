#include <sstream>
#include <string>
#include <iostream>

#include <sstream> // std::ostringstream 포함
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac ,char **av) 
{

    if (ac != 2)
    {
        std::cout << " Error" <<std::endl;
        return 1;
    }
    BitcoinExchange btc(av[1]);
  
}