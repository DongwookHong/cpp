#include "copy.hpp"

int main(int ac, char **av) {
 
	Copy co;
	if(ac !=4)
	{
		std::cout<<"Please Check Argument"<<std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string str1= av[2];
	std::string str2=av[3];
	
	if (!co.setCopy(filename))
		return 1;
	if(str1 =="")
	{
		std::cout<<"String1  cannot be empty!!"<<std::endl;
		return 1;
	}
	co.exe(str1,str2);
	
	
    return 0;
}
