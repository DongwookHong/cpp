#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
void test1();
int main() {
  test1();

  return 0;
}

void test1() {
  try {
    Bureaucrat test1("A", 1);
    Form test2("B", 30, 0);
    test1.signForm(test2);
    test2.beSigned(test1);
    test1.signForm(test2);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}