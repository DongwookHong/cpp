#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

void test1();
void test2();
void test3();
void test4();

int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}

void test1() {
  try {
    Bureaucrat test1("A", 150);
    test1.decrement();
    std::cout << test1 << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

void test2() {
  try {
    Bureaucrat test2("B", 2);
    test2.increment();
    std::cout << test2 << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

void test3() {
  try {
    Bureaucrat test3("C", 0);
    std::cout << test3 << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

void test4() {
  try {
    Bureaucrat test4("D", 30);
    std::cout << test4 << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
