#pragma once

#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

class PmergeMe {
 private:
  PmergeMe(const PmergeMe &instance);
  PmergeMe &operator=(const PmergeMe &rhs);

  /* vector */
  std::vector<int> vec;
  std::vector<std::pair<int, int> > vpair;
  std::vector<int> vJacobs;
  std::vector<int> vchain;
  int vsize;
  int vi;

  /* share */
  double oddvec;
  int pairsize;
  bool isSorted;
  int cnt;

  /* deque */
  std::deque<int> deq;
  std::deque<std::pair<int, int> > dpair;
  std::deque<int> dJacobs;
  std::deque<int> deqmainchain;

  int di;
  int dsize;

 public:
  /*vector function*/
  void vjacobstal(int);
  void mainsortvec(int, int, int);
  void ptomain(int, int);
  void binaryinsert(int, int, int);
  void porder(void);
  void sortVector(int, int);
  void setVector(void);
  void pairSet(void);

  /* share function */
  void inputValue(char **);
  void execute(char **);

  /*deque function*/
  void djacobstal(int);
  void mainsortdeq(int, int, int);
  void ptomaindeq(int, int);
  void binaryinsertdeq(int, int, int);
  void porderdeq(void);
  void sortDeque(int, int);
  void setDeque(void);
  void pairsetdeq(void);

  PmergeMe(void);
  ~PmergeMe(void);
};
