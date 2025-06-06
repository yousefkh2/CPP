#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int main()
{
    std::cout << "=== Bureaucrat-only tests ===\n\n";

    // 1. testing valid creation
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Failed to create Alice: " << e.what() << std::endl;
    }

    // 2. too high grade (0)
    {
        try {
            Bureaucrat tooHigh("HighBuro", 0);
            std::cout << tooHigh << std::endl; // won't reach
        }
        catch (const std::exception &e) {
            std::cerr << "Exception on creating HighBuro: " << e.what() << std::endl;
        }
    }

    // 3. too low grade (151)
    {
        try {
            Bureaucrat tooLow("LowBuro", 151);
            std::cout << tooLow << std::endl; // won't reach
        }
        catch (const std::exception &e) {
            std::cerr << "Exception on creating LowBuro: " << e.what() << std::endl;
        }
    }

    // 4. incrementing / decrementing around boundaries
    {
        try {
            Bureaucrat bob("Bob", 2);
            std::cout << bob << std::endl;
            bob.incrementGrade();
            std::cout << "After increment: " << bob << std::endl;

            bob.incrementGrade();
            std::cout << "This line will never print" << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << "Exception during Bob's grade change: " 
                      << e.what() << std::endl;
        }
    }

    // 5. decrement at lower boundary
    {
        try {
            Bureaucrat karim("Karim", 149);
            std::cout << karim << std::endl;

            // 149 -> 150
            karim.decrementGrade();
            std::cout << "After decrement: " << karim << std::endl;

			// 150 -> 151 (invalid)
            karim.decrementGrade();
        }
        catch (const std::exception &e) {
            std::cerr << "Exception during Karim's grade change: " 
                      << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Form-signing tests ===\n\n";

    // 6. create a few forms with various grade requirements
    {
        try {
            Form       f1("LeaveForm", 50, 20);
            Form       f2("TopSecretForm", 10, 5);
            Bureaucrat d("Dandarawy", 42);
            Bureaucrat m("Medhat", 2);
            Bureaucrat b("Bahgat", 100);

            std::cout << f1 << std::endl;
            std::cout << f2 << std::endl << std::endl;

            // 7. Dandarawy (grade 42) tries to sign LeaveForm (gradeToSign=50) → success
            d.signForm(f1);
            std::cout << "f1 after Dandarawy signs: " << f1 << std::endl << std::endl;

            // 8. Bahgat (grade 100) tries to sign TopSecretForm (gradeToSign=10) → fail
            b.signForm(f2);
            std::cout << "f2 after Bahgat's attempt: " << f2 << std::endl << std::endl;

            // 9. Medhat (grade 2) tries to sign TopSecretForm → success
            m.signForm(f2);
            std::cout << "f2 after Medhat signs: " << f2 << std::endl << std::endl;

            // 10. Attempt to create a Form with invalid grades (gradeToSign=0)
            Form invalidHigh("InvalidHigh", 0, 20);
            std::cout << invalidHigh << std::endl; // never reached
        }
        catch (const std::exception &e) {
            std::cerr << "Exception during Form construction or signing: " 
                      << e.what() << std::endl;
        }
    }

    // 11. Attempt to create a Form with too-low grade requirement (>150)
    {
        try {
            Form invalidLow("InvalidLow", 150, 151);
            std::cout << invalidLow << std::endl; // never reached
        }
        catch (const std::exception &e) {
            std::cerr << "Exception during Form construction: " 
                      << e.what() << std::endl;
        }
    }

    return 0;
}
