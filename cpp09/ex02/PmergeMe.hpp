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
  int k;

  /* share */
  double oddvec;
  int pairsize;
  bool isSorted;

  /* deque */
  std::deque<int> deq;
  std::deque<std::pair<int, int> > dpair;
  std::deque<int> dJacobs;
  std::deque<int> deqmainchain;

  int dsize;
  int ic;

 public:
  /*vector function*/
  void vjacobstal(int n);
  void mainsort(int left, int mid, int right);
  void pendtomain(int index, int bindex);
  void binaryinsert(int value, int left, int right);
  void pendingorder(void);
  void sortpair(int left, int right);
  void setVector(void);
  void pairSet(void);

  /* share function */
  void inputValue(char **av);
  void execute(char **av);

  /*deque function*/
  void jnumdeq(int n);
  void mainsortdeq(int left, int mid, int right);
  void pendtomaindeq(int idx, int bidx);
  void binaryinsertdeq(int value, int left, int right);
  void pendingorderdeq(void);
  void sortdeque(int left, int right);
  void pairdeque(void);
  void pairdeq(void);

  PmergeMe(void);
  ~PmergeMe(void);
};
