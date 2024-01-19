#pragma once
#include <iostream>

template <typename T>

void iter(T* arr, size_t len, void (*func)(T&)) {
  for (size_t i = 0; i < len; i++) {
    func(arr[i]);
  }
}

template <class T>

void iter(const T* arr, const size_t len, void (*func)(const T&)) {
  for (size_t i = 0; i < len; i++) {
    func(arr[i]);
  }
}
