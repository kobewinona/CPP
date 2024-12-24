#pragma once

#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
private:
  std::vector<int> _vecContainer;
  std::deque<int> _deqContainer;

public:
  PmergeMe(const std::vector<int> &input);
  ~PmergeMe();

  template <typename Container> void mergeInsertSort(Container &container);

  template <typename Container>
  void printContainer(const std::string &message,
                      const Container &container) const;
  void execute();
};
