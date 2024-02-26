#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
template <typename T>

class Array {
 private:
  T* array;
  size_t len;

 public:
  Array() : array(new T[0]), len(0) {}
  ~Array() { delete[] array; }

  Array(const Array& ref) : array(new T[ref.len]), len(ref.len) {
    for (size_t i = 0; i < len; i++) {
      array[i] = ref.array[i];
    }
  }

  Array& operator=(const Array& ref) {
    if (this != &ref) {
      delete[] array;
      array = new T[ref.len];
      len = ref.len;
      for (size_t i = 0; i < len; i++) {
        array[i] = ref.array[i];
      }
    }
    return *this;
  }

  Array(unsigned int n) : array(new T[n]), len(n){};

  const T& operator[](size_t idx) const throw(std::exception) {
    if (idx < 0 || idx >= len)
      throw std::out_of_range("out of range");
    else
      return array[idx];
  }

  T& operator[](size_t idx) throw(std::exception) {
    if (idx < 0 || idx >= len)
      throw std::out_of_range("out of range");
    else
      return array[idx];
  }

  size_t getSize() const { return len; }
};
