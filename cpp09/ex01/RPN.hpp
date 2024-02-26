#pragma once

#include <iostream>
#include <stack>

class RPN {
 private:
  std::stack<double> numberStack;

  double perform(double a, char op, double b);

  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);

 public:
  RPN(std::string);
  ~RPN();

  void executeRpn(std::string& str);
};

class Error : public std::exception {
 public:
  const char* what(void) const throw();
};
