#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
int easyfind(T& container, int value) {
  typename T::iterator itr =
      std::find(container.begin(), container.end(), value);
  if (itr == container.end()) throw std::runtime_error("value is not find");
  return *itr;
}
