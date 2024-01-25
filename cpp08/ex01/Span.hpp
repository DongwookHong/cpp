#pragma once

#include <iostream>
#include <numeric>
#include <vector>

class Span {
 private:
  std::vector<int> vec;
  unsigned int size;
  Span();

 public:
  Span(unsigned int N);
  ~Span();
  Span(const Span& ref);
  Span& operator=(const Span& ref);

  void addNumber(int number);

  struct AbsValue {
    int operator()(int diff) const { return std::abs(diff); }
  };

  std::size_t longestSpan() const;
  std::size_t shortestSpan() const;
};
