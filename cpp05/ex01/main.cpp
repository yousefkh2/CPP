#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main() {
  std::cout << "\033[1;33m=== Bureaucrat-only tests ===\033[0m\n\n";

  // 1. testing valid creation
  try {
    Bureaucrat a("Mrs. Naglaa", 42);
    std::cout << a << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Failed to create Mrs. Naglaa: " << e.what() << std::endl;
  }

  // 2. too high grade (0)
  {
    try {
      Bureaucrat tooHigh("Sir Lofty", 0);
      std::cout << tooHigh << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception on creating Sir Lofty: " << e.what() << std::endl;
    }
  }

  // 3. too low grade (151)
  {
    try {
      Bureaucrat tooLow("Uncle Samir", 151);
      std::cout << tooLow << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception on creating Uncle Samir: " << e.what()
                << std::endl;
    }
  }

  // 4. incrementing / decrementing around boundaries
  {
    try {
      Bureaucrat inspector("Inspector Hamed", 2);
      std::cout << inspector << std::endl;

      inspector.incrementGrade();
      std::cout << "After increment: " << inspector << std::endl;

      inspector.incrementGrade(); // Should throw
      std::cout << "This line will never print" << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception during Inspector Hamed's grade change: "
                << e.what() << std::endl;
    }
  }

  // 5. decrement at lower boundary
  {
    try {
      Bureaucrat sleepy("Sleepy Saeed", 149);
      std::cout << sleepy << std::endl;

      sleepy.decrementGrade(); // 149 -> 150
      std::cout << "After decrement: " << sleepy << std::endl;

      sleepy.decrementGrade(); // 150 -> 151 (invalid)
    } catch (const std::exception &e) {
      std::cerr << "Exception during Sleepy Saeed's grade change: " << e.what()
                << std::endl;
    }
  }

  std::cout << "\033[1;36m\n=== Form-signing tests ===\n\n\033[0m";

  // 6. create a few forms with various grade requirements
  {
    try {
      Form f1("LeaveRequest", 50, 20);
      Form f2("TopSecretClearance", 10, 5);

      Bureaucrat d("Mr. Gamal", 42);
      Bureaucrat m("Deputy Mona", 2);
      Bureaucrat b("Tarek the Clerk", 100);

      std::cout << f1 << std::endl;
      std::cout << f2 << std::endl << std::endl;

      // 7. Mr. Gamal (42) signs LeaveRequest (50) -> success
      d.signForm(f1);
      std::cout << "f1 after Mr. Gamal signs: " << f1 << std::endl << std::endl;

      // 8. Tarek (100) tries to sign TopSecret -> fail
      b.signForm(f2);
      std::cout << "f2 after Tarek's attempt: " << f2 << std::endl << std::endl;

      // 9. Mona (2) signs TopSecret -> success
      m.signForm(f2);
      std::cout << "f2 after Deputy Mona signs: " << f2 << std::endl
                << std::endl;

      // 10. Form with invalid sign grade (0)
      Form invalidHigh("PhantomPermit", 0, 20);
      std::cout << invalidHigh << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception during Form construction or signing: " << e.what()
                << std::endl;
    }
  }

  // 11. Form with execution grade > 150
  {
    try {
      Form invalidLow("ObsoleteForm", 150, 151);
      std::cout << invalidLow << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception during Form construction: " << e.what()
                << std::endl;
    }
  }

  return 0;
}
