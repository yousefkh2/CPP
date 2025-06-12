#include "easyfind.hpp"
#include <exception>
#include <list>
#include <vector>

int main(void) {

  std::vector<int> Victor = {1, 2, 3, 4, 5, 6};
  try {
	auto it = easyfind(Victor, 3);
	std::cout << "Found in vector: " << *it << "\n";
  } catch (std::exception &e) {
    std::cout << e.what() << "\n";
  }

  std::list<int> a_list = {10, 20, 30, 40};
  try {
    auto it = easyfind(a_list, 30);
	std::cout << "Found in list: " << *it << "\n";
  } catch (std::exception& e) {
	std::cout << e.what() << "\n";
  }


  const std::list<int> c_list = {10, 20, 30, 40};
  try {
    auto it = easyfind(c_list, 30);
	std::cout << "Found in list: " << *it << "\n";
  } catch (std::exception& e) {
	std::cout << e.what() << "\n";
  }
}
