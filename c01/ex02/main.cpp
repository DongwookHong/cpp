#include <iostream>
#include <string>


int main() {
  
  std::string str;
  str = "HI THIS IS BRAIN";

  std::string *stringPTR = &str;
  std::string &stringREF= str;


  std::cout<<"-----------------check address------------------"<<std::endl;
  std::cout<< "The Memory address of the string variable is : "<<&str<<std::endl;
  std::cout<< "The memory address held by stringPTR         : "<<stringPTR <<std::endl;
  std::cout<< "The memory address held by stringREF         : "<<&stringREF<<std::endl;

  std::cout <<std::endl;
  std::cout<<"-----------------check value------------------"<<std::endl;
  std::cout<< "The value of the string variable  is   : "<<str<<std::endl;
  std::cout<< "The value pointed to by stringPTR is   : "<<*stringPTR <<std::endl;
  std::cout<< "The value pointed to by stringREF is   : "<<stringREF<<std::endl;


  return 0;
}