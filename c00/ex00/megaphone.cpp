#include <iostream>

void to_change(std:: string &str);

int main(int ac , char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for(int i =1; av[i]; i++)
		{
			std::string str(av[i]);
			to_change(str);
			std::cout<<str;
		}
		std::cout<<std::endl;
	}
}

void to_change(std:: string &str)
{
	
	for(size_t i = 0;i<str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
}
