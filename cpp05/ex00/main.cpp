#include "Bureaucrat.hpp"

int main() {
  // 1. test valid creation
  try {
    Bureaucrat a("Alice", 42);
    std::cout << a << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Failed to create Alice: " << e.what() << std::endl;
  }

  // 2. test creation with too high grade (0)
  try {
    Bureaucrat tooHigh("Inshirah", 0);
    std::cout << tooHigh << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception on creating Inshirah: " << e.what() << std::endl;
  }

  // 3. test creation with too low grade (151)
  try {
    Bureaucrat tooLow("Mus3ad", 151);
    std::cout << tooLow << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception on creating Mus3ad: " << e.what() << std::endl;
  }

  // 4. test increment/decrement around boundaries
  try {
    Bureaucrat bob("Bob", 2);
    std::cout << bob << std::endl;
    bob.incrementGrade(); // goes from 2 to 1
    std::cout << "After increment: " << bob << std::endl;
    bob.incrementGrade(); // 1 to 0 (invalid)
    std::cout << "This line will never print." << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception during Bob's grade change: " << e.what()
              << std::endl;
  }

  // 5. test decrement at lower boundary
  try {
    Bureaucrat carol("Carol", 149);
    std::cout << carol << std::endl;
    carol.decrementGrade(); // 149 to 150
    std::cout << "After decrement: " << carol << std::endl;
    carol.decrementGrade(); // 150 to 151 (invalid)
  } catch (const std::exception &e) {
    std::cerr << "Exception during Carol's grade change: " << e.what()
              << std::endl;
  }

  return 0;
}
