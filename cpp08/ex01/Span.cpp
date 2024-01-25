#include "Span.hpp"

Span::Span(unsigned int N) : size(N) {}

Span::~Span() {}

Span::Span(const Span& ref) { *this = ref; }

Span& Span::operator=(const Span& ref) {
  if (this != &ref) {
    this->vec = ref.vec;
  }
  return *this;
}

void Span::addNumber(int number) {
  if (this->vec.size() + 1 >= this->size) {
    throw std::runtime_error("The span is full already.");
  }
  this->vec.push_back(number);
}

std::size_t Span::longestSpan() const {
  if (vec.size() <= 2) {
    throw std::logic_error("vector siz is not over 2");
  }
  std::vector<int>::const_iterator min_itr =
      std::min_element(vec.begin(), vec.end());
  std::vector<int>::const_iterator max_itr =
      std::max_element(vec.begin(), vec.end());
  return *max_itr - *min_itr;
}

std::size_t Span::shortestSpan() const {
  if (vec.size() <= 2) {
    throw std::logic_error("vector siz is not over 2");
  }
  std::vector<int> temp = vec;

  std::sort(temp.begin(), temp.end());
  std::adjacent_difference(temp.begin(), temp.end(), temp.begin());

  std::transform(temp.begin(), temp.end(), temp.begin(), AbsValue());
  return *std::min_element(temp.begin() + 1, temp.end());
}
