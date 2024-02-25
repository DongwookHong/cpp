#include "PmergeMe.hpp"



PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}


void PmergeMe::pendtomain(int idx, int bidx) {
  while (idx > bidx) {
    binaryinsert(Dpair[idx - 1].second, 0, idx + z);
    idx--;
  }
}

void PmergeMe::binaryinsert(int value, int left, int right) {
  if (left >= right) {
    if (mainchain[left] > value) {
      z++;
      mainchain.insert(mainchain.begin() + left, value);
    } else {
      mainchain.insert(mainchain.begin() + left + 1, value);
    }
    return;
  }
  int mid = (left + right) / 2;
  if (mainchain[mid] == value) {
    mainchain.insert(mainchain.begin() + mid, value);
    return;
  } else if (mainchain[mid] < value) {
    binaryinsert(value, mid + 1, right);
  } else {
    binaryinsert(value, left, mid);
  }
}

void PmergeMe::jacobstal(int n) {
  jcob.push_back(0);
  jcob.push_back(1);
  for (int i = 2; i <= n + 1; ++i) {
    int next = (jcob[i - 1]) + (jcob[i - 2] * 2);
    jcob.push_back(next);
  }
}


void PmergeMe::mainSort(int left, int pivot, int right) {
  std::vector<std::pair<int, int> > Lvec(pivot - left + 1);
  std::vector<std::pair<int, int> > Rvec(right - pivot);
  int lsize = Lvec.size();
  int rsize = Rvec.size();
  
  for (int i = 0; i < lsize; i++) Lvec[i] = Dpair[left + i];
  for (int i = 0; i < rsize; i++) Rvec[i] = Dpair[pivot + 1 + i];

  int i = 0;
  int j = 0;
  int k = left;

  while (i < lsize && j < rsize) {
    if (Lvec[i].first <= Rvec[j].first) {
      Dpair[k++] = Lvec[i++];
    } else {
      Dpair[k++] = Rvec[j++];
    }
  }
  while (i < lsize) Dpair[k++] = Lvec[i++];
  while (j < rsize) Dpair[k++] = Rvec[j++];
}


void PmergeMe::sortPair(int left, int right) {
  if (left < right) {
    int pivot = (left + right) / 2;
    sortPair(left, pivot);
    sortPair(pivot + 1, right);
    mainSort(left, pivot, right);
  }
}


void PmergeMe::pair(){
 for (int i = 0; i < midSize; i++) {
    if (vec[i] > vec[i + midSize])
      Dpair.push_back(std::make_pair(vec[i], vec[i + midSize]));
    else
      Dpair.push_back(std::make_pair(vec[i + midSize], vec[i]));
  }
  sortPair(0, midSize - 1);
}

void PmergeME::pendingorder(void) {
  int j = 1;
  int ssize = jacob.size();
  while (j < ssize) {
    if (midSize < jacob[j]) {
      pendtomain(midSize, jacob[j - 1]);
      if (_vecsize % 2 != 0) {
        int msize = mainchain.size();
        binaryinsert(oddvec, 0, msize - 1);
      }
      break;
    } else {
      pendtomain(jacob[j], jacob[j - 1]);
      j++;
    }
  }
}

void PmergeMe::pairSet(){
  pair();
  jacobstal(midSize+1);
  for (int i = 0; i < midSize; ++i) mainchain.push_back(Dpair[i].first);
  pendingorder();
}

void PmergeMe::insertValue(int ac, char ** av)
{
    double num =0;
    char *end = NULL;

    for (int i =1 ; i<ac; i++ )
    {
        num = strtod(av[i],&end);
       if (*end != '\0' || num > static_cast<double>(INT_MAX) || num < 0)
            throw std::runtime_error("Invalid input or out of range");
        else
            vec.push_back(num); 
    }
    
    vecSize = vec.size();
    midSize = vecSize/2;
    isSorted = true;
    // for (int i =0;  i <vecSize; i++ )
    // {
    //     std::cout <<vec[i]<<" ";
    // }
    //  std::cout << std::endl; 
             
    for (int i = 0; i < vecSize-1; i++)
    {
        if (vec[i]> vec[i+1])
        {
            isSorted = false;
            break;
        }
    }
    if (isSorted)
      throw std::runtime_error("Error: already sorted");
    if (vecSize % 2 != 0) {
      oddNum = vec[vecSize - 1];
    }
}



void PmergeMe::start(int ac, char ** av){
insertValue(ac,av);    
vecstart = clock();
pairSet();
}