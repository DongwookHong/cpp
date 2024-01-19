#pragma once
#include <iostream>
template <typename T>
void swap(T& num, T& num2) {
  T temp = num;
  num = num2;
  num2 = temp;
}

template <typename S>
S min(const S num, const S num2) {
  return ((num < num2) ? num : num2);
}

template <typename M>
M max(const M num, const M num2) {
  return ((num > num2) ? num : num2);
}