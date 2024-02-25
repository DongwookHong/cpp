#pragma once

#include <iostream>
#include <stack>

class RPN {
 private:
  std::stack<double> numberStack;

  double perform(double a, char op, double b);

 public:
  RPN();
  RPN(std::string );
  ~RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);

  void executeRpn(std::string& str);
};

class Error : public std::exception {
   public:
    const char* what(void) const throw();
  };


