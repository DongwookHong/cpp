#include "PmergeMe.hpp"

void PmergeME::vjacobstal(int n) {
  vJacobs.push_back(0);
  vJacobs.push_back(1);
  
  for (int i = 2; i <= n + 1; ++i) {
    int next = (vJacobs[i - 1]) + (vJacobs[i - 2] * 2);
    vJacobs.push_back(next);
  }
}

void PmergeME::mainsort(int left, int mid, int right) {
  std::vector<std::pair<int, int> > Lvector(mid - left + 1);
  std::vector<std::pair<int, int> > Rvector(right - mid);
  int lsize = Lvector.size();
  int rsize = Rvector.size();
  for (int i = 0; i < lsize; i++) Lvector[i] = vpair[left + i];
  for (int i = 0; i < rsize; i++) Rvector[i] = vpair[mid + 1 + i];

  int i = 0;
  int j = 0;
  int k = left;

  while (i < lsize && j < rsize) {
    if (Lvector[i].first <= Rvector[j].first) {
      vpair[k++] = Lvector[i++];
    } else {
      vpair[k++] = Rvector[j++];
    }
  }
  while (i < lsize) vpair[k++] = Lvector[i++];
  while (j < rsize) vpair[k++] = Rvector[j++];
}

void PmergeME::binaryinsert(int value, int left, int right) {
  if (left >= right) {
    if (vchain[left] > value) {
      k++;
      vchain.insert(vchain.begin() + left, value);
    } else {
      vchain.insert(vchain.begin() + left + 1, value);
    }
    return;
  }
  int mid = (left + right) / 2;
  if (vchain[mid] == value) {
    vchain.insert(vchain.begin() + mid, value);
    return;
  } else if (vchain[mid] < value) {
    binaryinsert(value, mid + 1, right);
  } else {
    binaryinsert(value, left, mid);
  }
}

void PmergeME::pendtomain(int idx, int bidx) {
  while (idx > bidx) {
    binaryinsert(vpair[idx - 1].second, 0, idx + k);
    idx--;
  }
}

void PmergeME::pendingorder(void) {
  int j = 1;
  int ssize = vJacobs.size();
  while (j < ssize) {
    if (pairsize < vJacobs[j]) {
      pendtomain(pairsize, vJacobs[j - 1]);
      if (vsize % 2 != 0) {
        int msize = vchain.size();
        binaryinsert(oddvec, 0, msize - 1);
      }
      break;
    } else {
      pendtomain(vJacobs[j], vJacobs[j - 1]);
      j++;
    }
  }
}

void PmergeME::sortpair(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    sortpair(left, mid);
    sortpair(mid + 1, right);
    mainsort(left, mid, right);
  }
}

void PmergeME::setVector(void) {
  int mid = pairsize;
  for (int i = 0; i < mid; i++) {
    if (vec[i] > vec[i + mid])
      vpair.push_back(std::make_pair(vec[i], vec[i + mid]));
    else
      vpair.push_back(std::make_pair(vec[i + mid], vec[i]));
  }
  sortpair(0, mid - 1);
}

void PmergeME::pairSet(void) {
  pairsize = vsize / 2;
  setVector();
  vjacobstal(pairsize + 1);
  for (int i = 0; i < pairsize; ++i) vchain.push_back(vpair[i].first);
  pendingorder();
}

void PmergeME::inputValue(int ac, char **av) {
    
    int i = 0;
    char *end = NULL;
    double input;

    while (av[++i]) {
      input = strtod(av[i], &end);
      if (*end != '\0') throw std::runtime_error("Error: not valid input");
      if (input > static_cast<double>(INT_MAX)) throw std::runtime_error("Error: not integer");
      vec.push_back(input);
      deq.push_back(input);
    }
    vsize = vec.size();
    dsize = vsize;
   
    isSorted = true;
    for (int i = 0; i < vsize - 1; i++) {
      if (vec[i] > vec[i + 1]) {
        isSorted =false;
        break;
      }
    }
    if (isSorted) {
      throw std::runtime_error("Error: already sorted");
    }
    k = 0;
    ic = 0;
    if (vsize % 2 != 0) {
      oddvec = vec[vsize - 1];
    }
}

void PmergeME::execute(int ac, char **av) {
  inputValue(ac, av);
  clock_t vecstart = clock();
  pairSet();
  clock_t vecend = clock();
  std::cout << "After: ";
  int i = -1;
  while (++i < vsize) std::cout << vchain[i] << " ";
  double usec = (((double)(vecend - vecstart)) * 10 / CLOCKS_PER_SEC);
  // double usec = ((double)(vecend - vecstart)) * 1000000;
  std::cout << "\nTime to process a range of " << vsize
            << " elements with std::vector : " << usec << " us\n";
  clock_t deqstart = clock();
  pairdeq();
  clock_t deqend = clock();
  i = -1;
  // while (++i < dsize) std::cout << deqmainchain[i] << " ";
  double usecdeq = (((double)(deqend - deqstart)) * 10 / CLOCKS_PER_SEC);
  std::cout << "Time to process a range of " << dsize
            << " elements with std::deque : " << usecdeq << " us\n";
}

void PmergeME::jnumdeq(int n) {
  dJacobs.push_back(0);
  dJacobs.push_back(1);
  for (int i = 2; i <= n + 1; ++i) {
    int next = (dJacobs[i - 1]) + (dJacobs[i - 2] * 2);
    dJacobs.push_back(next);
  }
}

void PmergeME::mainsortdeq(int left, int mid, int right) {
  std::deque<std::pair<int, int> > _L(mid - left + 1);
  std::deque<std::pair<int, int> > _R(right - mid);
  int lsize = _L.size();
  int rsize = _R.size();
  for (int i = 0; i < lsize; i++) _L[i] = dpair[left + i];
  for (int i = 0; i < rsize; i++) _R[i] = dpair[mid + 1 + i];

  int i = 0;
  int j = 0;
  int k = left;

  while (i < lsize && j < rsize) {
    if (_L[i].first <= _R[j].first) {
      dpair[k++] = _L[i++];
    } else {
      dpair[k++] = _R[j++];
    }
  }
  while (i < lsize) dpair[k++] = _L[i++];
  while (j < rsize) dpair[k++] = _R[j++];
}

void PmergeME::sortdeque(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    sortdeque(left, mid);
    sortdeque(mid + 1, right);
    mainsortdeq(left, mid, right);
  }
}

void PmergeME::binaryinsertdeq(int value, int left, int right) {
  if (left >= right) {
    if (deqmainchain[left] > value) {
      ic++;
      deqmainchain.insert(deqmainchain.begin() + left, value);
    } else {
      deqmainchain.insert(deqmainchain.begin() + left + 1, value);
    }
    return;
  }
  int mid = (left + right) / 2;
  if (deqmainchain[mid] == value) {
    deqmainchain.insert(deqmainchain.begin() + mid, value);
    return;
  } else if (deqmainchain[mid] < value) {
    binaryinsertdeq(value, mid + 1, right);
  } else {
    binaryinsertdeq(value, left, mid);
  }
}

void PmergeME::pendtomaindeq(int idx, int bidx) {
  while (idx > bidx) {
    binaryinsertdeq(vpair[idx - 1].second, 0, idx + ic);
    idx--;
  }
}

void PmergeME::pendingorderdeq(void) {
  int j = 1;
  int ssize = dJacobs.size();
  while (j < ssize) {
    if (pairsize < dJacobs[j]) {
      pendtomaindeq(pairsize, dJacobs[j - 1]);
      if (dsize % 2 != 0) {
        int msize = deqmainchain.size();
        binaryinsertdeq(oddvec, 0, msize - 1);
      }
      break;
    } else {
      pendtomaindeq(dJacobs[j], dJacobs[j - 1]);
      j++;
    }
  }
}

void PmergeME::pairdeque(void) {
  int mid = deq.size() / 2;
  for (int i = 0; i < mid; ++i) {
    if (deq[i] > deq[i + mid])
      dpair.push_back(std::make_pair(deq[i], deq[i + mid]));
    else
      dpair.push_back(std::make_pair(deq[i + mid], vec[i]));
  }
  sortdeque(0, mid - 1);
}

void PmergeME::pairdeq(void) {
  pairdeque();
  jnumdeq(pairsize + 1);
  for (int i = 0; i < pairsize; ++i) deqmainchain.push_back(dpair[i].first);
  pendingorderdeq();
}