
#include <cstddef>
#include <stdexcept>
#include <vector>
class Span {
private:
  std::vector<int> _numbers;
  std::size_t _max_size;

public:
  Span(std::size_t maxSize) : _max_size(maxSize) {}

  void addNumber(int value) {
    if (_numbers.size() < _max_size) {
      _numbers.push_back(value);
    } else {
      throw std::runtime_error("Cannot add number: Span is already full.");
    }
  }

  int shortestSpan() const {
    if (_numbers.size() < 2) {
      throw std::runtime_error(
          "shortestSpan() failed: need at least two numbers.");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minDiff = INT_MAX;
    for (std::size_t i = 0; i < sorted.size() - 1; ++i) {
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minDiff)
			minDiff = diff;
	}
    return minDiff;
  }
  int longestSpan() const {
    if (_numbers.size() < 2) {
      throw std::runtime_error(
          "longestSpan() failed: need at least two numbers.");
    }
	auto maxIt = std::max_element(_numbers.begin(), _numbers.end());
	auto minIt = std::min_element(_numbers.begin(), _numbers.end());

    return *maxIt - *minIt;
  }

  template <typename Iterator>
  void addNumbers(Iterator begin, Iterator end) {
	std::size_t rangeSize = std::distance(begin, end);
	if (_numbers.size() + rangeSize > _max_size) {
		throw std::runtime_error("addNumbers() failed: max capacity exceeded.");
	}
	_numbers.insert(_numbers.end(), begin, end);
	}
  };
