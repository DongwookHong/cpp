#pragma once

#include <iostream>
#include <stack>

class RPN {
 private:
  std::stack<double> numberStack;

  double perform(double, char, double);

  RPN();
  RPN(const RPN&);
  RPN& operator=(const RPN&);

 public:
  RPN(std::string);
  ~RPN();

  void executeRpn(std::string&);
};

class Error : public std::exception {
 public:
  const char* what(void) const throw();
};
