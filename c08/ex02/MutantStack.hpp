#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack() : std::stack<T>(){};
  ~MutantStack(){};
  MutantStack(const MutantStack& ref) : std::stack<T>() { *this = ref; }
  MutantStack& operator=(const MutantStack& ref) {
    if (this != ref) {
      std::stack<T>::operator=(ref);
      *this = ref;
    }
    return (*this);
  };

  typedef typename MutantStack<T>::stack::container_type::iterator iterator;
  iterator begin(void) { return this->c.begin(); }
  iterator end(void) { return this->c.end(); }
};
