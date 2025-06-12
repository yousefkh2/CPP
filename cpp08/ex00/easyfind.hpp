
#include <algorithm>
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
auto easyfind(T& container, int value) { // instead of T::iterator easyfind .. (much more concise)
	auto it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}


template <typename T>
void test_easyfind(const T& container, int value) {
	try {
		auto it = easyfind(container, value);
		std::cout << "Found value: " << *it << " in container of type: " << typeid(T).name() << "\n"; // i think i will remove it since it mangles typename
	} catch (std::exception& e) {

		std::cout << e.what() << "\n";
	}
}
