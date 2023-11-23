#include "Harl.hpp"



int main(int ac, char **av)
{
	Harl hr;
	if (ac !=2)
	{
		std::cout<< "Can't Check Complain"<<std::endl;
		return 0;
	}
	hr.complain(av[1]);
}