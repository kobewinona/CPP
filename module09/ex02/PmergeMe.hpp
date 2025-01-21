#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// 5 1 2 123 60 70 40
class PmergeMe {
private:
  int _comparisonsCount;
  std::vector<int> _vecContainer;
  std::deque<int> _deqContainer;

  template <typename Container> void _mergeInsertSort(Container &container);
  template <typename Container, typename T>
  typename Container::iterator _binarySearchInsert(Container &container,
                                                   const T &value,
                                                   int &comparisonCount);
  std::vector<int> _generateInsertionOrder(int size);

public:
  PmergeMe();
  PmergeMe(const std::vector<int> &input);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  template <typename Container>
  void printContainer(const std::string &message,
                      const Container &container) const;
  void execute();
};

#endif // PMERGE_ME_HPP
