#include <iostream>
#include "iter.hpp"
#include <string>
// void printInt(const int& x) {
//     std::cout << x << " ";
// }

// void increment(int& x) {
//     ++x;
// }

// int main() {
//     int arr[] = {1, 2, 3, 4};
// 	const int constArr[] = {10, 20, 30, 40};
//     size_t len = sizeof(arr)/sizeof(arr[0]);

//     std::cout << "Original: ";
//     iter(arr, len, printInt);
//     std::cout << "\n";

//     iter(arr, len, increment);

//     std::cout << "After increment: ";
//     iter(arr, len, printInt);
//     std::cout << "\n";

// 	std::cout << "Const array: ";
// iter(constArr, 4, printInt);

// // iter(constArr, 4, increment); should fail
// }

// A generic print function template
template<typename U>
void print(const U& x) {
    std::cout << x << std::endl;
}

// A mutating function
void increment(int& x) {
    ++x;
}

int main() {
    int nums[] = { 1, 2, 3, 4, 5 };
    std::size_t n = sizeof(nums) / sizeof(nums[0]);

    // Print original
    iter(nums, n, print<int>);
    // Increment each
    iter(nums, n, increment);
    // Print again
    iter(nums, n, print<int>);

    // Test on const array
    const std::string words[] = { "hello", "C++", "world" };
    std::size_t m = sizeof(words) / sizeof(words[0]);
    iter(words, m, print<std::string>);

    return 0;
}
