
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

void test1();
void test2();
void test3();

int main() {
  test1();
  test2();
  test3();
}

void test1() {
  std::vector<int> vec;
  for (std::vector<int>::size_type i = 0; i < 5; i++) {
    vec.push_back(i);
  }
  try {
    std::cout << "find it " << '\n';
  } catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;
  }
}

void test2() {
  std::list<int> lst;
  for (std::vector<int>::size_type i = 0; i < 5; i++) {
    lst.push_back(i);
  }
  try {
    std::cout << "find it " << '\n';
  } catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;
  }
}

void test3() {
  std::deque<int> deq;
  for (std::vector<int>::size_type i = 0; i < 5; i++) {
    deq.push_back(i);
  }
  try {
    std::cout << "find it " << '\n';
  } catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;
  }
}