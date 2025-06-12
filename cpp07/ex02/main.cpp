// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }


#include <iostream>
#include "Array.hpp"

namespace Color {
    constexpr const char* RESET  = "\033[0m";
    constexpr const char* RED    = "\033[31m";
    constexpr const char* GREEN  = "\033[32m";
    constexpr const char* CYAN   = "\033[36m";
}

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << Color::GREEN << "=== Testing Array Class Template ===" << Color::RESET << std::endl;

    // Test 1: Default constructor
    std::cout << Color::CYAN << "\n1. Testing default constructor:" << Color::RESET << std::endl;
    Array<int> empty_array;
    std::cout << "Empty array size: " << empty_array.size() << std::endl;

    // Test 2: Parameterized constructor
    std::cout << Color::CYAN << "\n2. Testing parameterized constructor:" << Color::RESET << std::endl;
    Array<int> numbers(5);
    std::cout << "Numbers array size: " << numbers.size() << std::endl;

    // Test 3: Default initialization check
    std::cout << Color::CYAN << "\n3. Testing default initialization:" << Color::RESET << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // Test 4: Element assignment
    std::cout << Color::CYAN << "\n4. Testing element assignment:" << Color::RESET << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // Test 5: Copy constructor
    std::cout << Color::CYAN << "\n5. Testing copy constructor:" << Color::RESET << std::endl;
    Array<int> copy_array(numbers);
    std::cout << "Copy array size: " << copy_array.size() << std::endl;

    // Verify deep copy
    std::cout << "Original array values:" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    std::cout << "Copy array values:" << std::endl;
    for (unsigned int i = 0; i < copy_array.size(); i++) {
        std::cout << "copy_array[" << i << "] = " << copy_array[i] << std::endl;
    }

    // Test 6: Assignment operator
    std::cout << Color::CYAN << "\n6. Testing assignment operator:" << Color::RESET << std::endl;
    Array<int> assigned_array;
    assigned_array = numbers;
    std::cout << "Assigned array size: " << assigned_array.size() << std::endl;

    // Test 7: Independence after copying
    std::cout << Color::CYAN << "\n7. Testing independence after copying:" << Color::RESET << std::endl;
    numbers[0] = 999;
    copy_array[1] = 888;
    assigned_array[2] = 777;

    std::cout << "After modification:" << std::endl;
    std::cout << Color::RED   << "numbers[0] = " << Color::RESET << numbers[0] << " (should be 999)" << std::endl;
    std::cout << Color::RED   << "copy_array[0] = " << Color::RESET << copy_array[0] << " (should be 0)" << std::endl;
    std::cout << Color::RED   << "assigned_array[0] = " << Color::RESET << assigned_array[0] << " (should be 0)" << std::endl;

    std::cout << Color::GREEN << "numbers[1] = " << Color::RESET << numbers[1] << " (should be 10)" << std::endl;
    std::cout << Color::GREEN << "copy_array[1] = " << Color::RESET << copy_array[1] << " (should be 888)" << std::endl;
    std::cout << Color::GREEN << "assigned_array[1] = " << Color::RESET << assigned_array[1] << " (should be 10)" << std::endl;

    // Test 8: Different types
    std::cout << Color::CYAN << "\n8. Testing with different types:" << Color::RESET << std::endl;
    Array<double> doubles(3);
    for (unsigned int i = 0; i < doubles.size(); i++) {
        doubles[i] = i * 3.14;
        std::cout << "doubles[" << i << "] = " << doubles[i] << std::endl;
    }
    Array<std::string> strings(2);
    strings[0] = "Hello";
    strings[1] = "World";
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
    }

    // Test 9: Exception handling
    std::cout << Color::CYAN << "\n9. Testing exception handling:" << Color::RESET << std::endl;
    try {
        std::cout << "Attempting to access empty_array[0]..." << std::endl;
        std::cout << empty_array[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << Color::RED << "Exception caught: " << Color::RESET << e.what() << std::endl;
    }
    try {
        std::cout << "Attempting to access numbers[10] (out of bounds)..." << std::endl;
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << Color::RED << "Exception caught: " << Color::RESET << e.what() << std::endl;
    }

    // Test 10: Const array access
    std::cout << Color::CYAN << "\n10. Testing const array access:" << Color::RESET << std::endl;
    const Array<int> const_array(numbers);
    std::cout << "Const array size: " << const_array.size() << std::endl;
    std::cout << "const_array[0] = " << const_array[0] << std::endl;

    // Test 12: Larger array test (similar to subject example)
    std::cout << Color::CYAN << "\n12. Testing larger array:" << Color::RESET << std::endl;
    Array<int> big_array(MAX_VAL);
    for (int i = 0; i < MAX_VAL; i++) {
        big_array[i] = i;
    }
    std::cout << "Big array created with " << big_array.size() << " elements" << std::endl;
    std::cout << "big_array[0] = " << big_array[0] << std::endl;
    std::cout << "big_array[MAX_VAL-1] = " << big_array[MAX_VAL-1] << std::endl;

    std::cout << Color::GREEN << "\n=== All tests completed ===" << Color::RESET << std::endl;
    return 0;
}

