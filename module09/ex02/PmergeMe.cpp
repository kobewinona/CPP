#include "PmergeMe.hpp"

// @defgroup constructors
PmergeMe::PmergeMe(const std::vector<int> &input) {
  _vecContainer = input;
  _deqContainer.assign(input.begin(), input.end());
}

// @def destructor
PmergeMe::~PmergeMe() {}
// @defgroup member functions
template <typename Container, typename T>
typename Container::iterator
PmergeMe::_binarySearchInsert(Container &container, const T &value,
                              int &comparisonCount) {
  typename Container::iterator begin = container.begin();
  typename Container::iterator end = container.end();
  typename Container::iterator mid;

  while (begin != end) {
    mid = begin;
    std::advance(mid, std::distance(begin, end) / 2);

    comparisonCount++;
    if (*mid < value) {
      ++mid;
      begin = mid;
    } else {
      end = mid;
    }
  }

  return begin; // Position to insert
}

std::vector<int> PmergeMe::_generateInsertionOrder(int size) {
  std::vector<int> order;
  int bitLength = std::ceil(std::log2(size + 1));

  for (int i = 1; i <= size; ++i) {
    int reversed = 0;
    for (int j = 0; j < bitLength; ++j) {
      if (i & (1 << j)) {
        reversed |= 1 << (bitLength - 1 - j);
      }
    }
    if (reversed > 0 && reversed <= size) {
      order.push_back(reversed - 1);
    }
  }

  return order;
}

template <typename Container>
void PmergeMe::_mergeInsertSort(Container &numbers) {
  size_t n = numbers.size();
  if (n <= 1) {
    return;
  }

  // Step 1: Pair elements and split into two groups
  Container larger, smaller;

  for (size_t i = 0; i + 1 < n; i += 2) {
    _comparisonsCount++;
    if (numbers[i] > numbers[i + 1]) {
      larger.push_back(numbers[i]);
      smaller.push_back(numbers[i + 1]);
    } else {
      larger.push_back(numbers[i + 1]);
      smaller.push_back(numbers[i]);
    }
  }

  // Handle an odd element
  if (n % 2 != 0) {
    smaller.push_back(numbers.back());
  }

  // Step 2: Recursively sort the larger elements
  _mergeInsertSort(larger);

  // Step 3: Start merging into result
  Container result;
  result.push_back(larger[0]); // Start with the smallest larger element

  if (!smaller.empty()) {
    result.insert(result.begin(), smaller[0]); // Insert paired smaller element
  }

  // Step 4: Insert remaining smaller elements using bit-reversed order
  std::vector<int> insertionOrder = _generateInsertionOrder(smaller.size() - 1);

  for (size_t i = 0; i < insertionOrder.size(); ++i) {
    size_t index = insertionOrder[i];
    if (index + 1 < smaller.size()) {
      typename Container::iterator pos =
          _binarySearchInsert(result, smaller[index + 1], _comparisonsCount);
      result.insert(pos, smaller[index + 1]);
    }
  }

  // Step 5: Insert remaining sorted larger elements
  for (size_t i = 1; i < larger.size(); ++i) {
    result.push_back(larger[i]);
  }

  // Copy sorted result back
  numbers = result;
}

template <typename T>
void PmergeMe::printContainer(const std::string &message,
                              const T &container) const {
  std::cout << message;
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

// Execute the algorithm and measure performance
void PmergeMe::execute() {
  clock_t start, end;

  _comparisonsCount = 0;
  // Sort and time vector
  start = clock();
  _mergeInsertSort(_vecContainer);
  end = clock();
  double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  std::cout << std::endl;
  printContainer("Sorted vector: ", _vecContainer);
  std::cout << std::fixed;
  std::cout << "Time taken: " << vecTime << " seconds" << std::endl;
  std::cout << "Number of comparisons made: " << _comparisonsCount << std::endl;

  _comparisonsCount = 0;

  // Sort and time deque
  start = clock();
  _mergeInsertSort(_deqContainer);
  end = clock();
  double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  std::cout << std::endl;
  printContainer("Sorted deque: ", _deqContainer);
  std::cout << "Time taken: " << deqTime << " seconds" << std::endl;
  std::cout << "Number of comparisons made: " << _comparisonsCount << std::endl;

  std::cout << std::endl;
}
