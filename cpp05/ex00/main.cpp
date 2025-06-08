#include "Bureaucrat.hpp"

int main() {
  // 1. test valid creation
  try {
    Bureaucrat a("Mr. Morsi", 42);
    std::cout << a << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Failed to create Mr. Morsi: " << e.what() << std::endl;
  }

  // 2. test creation with too high grade (0)
  try {
    Bureaucrat tooHigh("Eng. Sharif", 0);
    std::cout << tooHigh << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception on creating Eng. Sharif: " << e.what() << std::endl;
  }

  // 3. test creation with too low grade (151)
  try {
    Bureaucrat tooLow("Dr. Fathy", 151);
    std::cout << tooLow << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception on creating Dr. Fathy: " << e.what() << std::endl;
  }

  // 4. test increment/decrement around boundaries
  try {
    Bureaucrat omda("Omda Hassan", 2);
    std::cout << omda << std::endl;
    omda.incrementGrade(); // goes from 2 to 1
    std::cout << "After increment: " << omda << std::endl;
    omda.incrementGrade(); // 1 to 0 (invalid)
    std::cout << "This line will never print." << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception during Omda Hassan's grade change: " << e.what()
              << std::endl;
  }

  // 5. test decrement at lower boundary
  try {
    Bureaucrat safiya("Madame Safiya", 149);
    std::cout << safiya << std::endl;
    safiya.decrementGrade(); // 149 to 150
    std::cout << "After decrement: " << safiya << std::endl;
    safiya.decrementGrade(); // 150 to 151 (invalid)
  } catch (const std::exception &e) {
    std::cerr << "Exception during Madame Safiya's grade change: " << e.what()
              << std::endl;
  }

  return 0;
}
