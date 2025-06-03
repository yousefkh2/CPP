#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main()
{
    std::cout << "=== Bureaucrat‐only tests ===\n\n";

    // 1. testing valid creation
    try {
        Bureaucrat a("Dandarawy", 42);
        std::cout << a << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Failed to create Dandarawy: " << e.what() << std::endl;
    }

    // 2. too high grade
    try {
        Bureaucrat tooHigh("Shawkat", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception on creating Shawkat: " << e.what() << std::endl;
    }

    // 3. too low grade
    try {
        Bureaucrat tooLow("Bahgat", 151);
        std::cout << tooLow << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception on creating Bahgat: " << e.what() << std::endl;
    }

    // 4. incrementing / decrementing around boundaries
    try {
        Bureaucrat medhat("Medhat", 2);
        std::cout << medhat << std::endl;
        medhat.incrementGrade(); // 2 → 1
        std::cout << "After increment: " << medhat << std::endl;
        medhat.incrementGrade(); // 1 → 0 (invalid)
        std::cout << "This line will never print" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception during Medhat's grade change: " << e.what() << std::endl;
    }

    // 5. decrement at lower boundary
    try {
        Bureaucrat karim("Karim", 149);
        std::cout << karim << std::endl;
        karim.decrementGrade(); // 149 → 150
        std::cout << "After decrement: " << karim << std::endl;
        karim.decrementGrade(); // 150 → 151 (invalid)
    }
    catch (const std::exception& e) {
        std::cerr << "Exception during Karim's grade change: " << e.what() << std::endl;
    }

    std::cout << "\n=== Form‐signing tests ===\n\n";

    // 6. Create a few forms with various grade requirements
    try {
        Form        f1("LeaveForm", 50, 20);
        Form        f2("TopSecretForm", 10, 5);
        Bureaucrat  d("Dandarawy", 42);
        Bureaucrat  m("Medhat", 2);
        Bureaucrat  b("Bahgat", 100);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl << std::endl;

        // 7. Dandarawy (grade 42) tries to sign LeaveForm (gradeToSign=50) → success
        d.signForm(f1);
        std::cout << "f1 after signing attempt: " << f1 << std::endl << std::endl;

        // 8. Bahgat (grade 100) tries to sign TopSecretForm (gradeToSign=10) → fail
        b.signForm(f2);
        std::cout << "f2 after signing attempt: " << f2 << std::endl << std::endl;

        // 9. Medhat (grade 2) tries to sign TopSecretForm → success
        m.signForm(f2);
        std::cout << "f2 after medhat’s signing: " << f2 << std::endl << std::endl;

        // 10. Attempt to create a Form with invalid grades
        Form invalidHigh("InvalidHigh", 0, 20);
        std::cout << invalidHigh << std::endl; // never reached
    }
    catch (const std::exception& e) {
        std::cerr << "Exception during Form construction or signing: " << e.what() << std::endl;
    }

    // 11. Attempt to create a Form with too‐low grade requirement (>150)
    try {
        Form invalidLow("InvalidLow", 150, 151);
        std::cout << invalidLow << std::endl; // never reached
    }
    catch (const std::exception& e) {
        std::cerr << "Exception during Form construction: " << e.what() << std::endl;
    }

    return 0;
}
