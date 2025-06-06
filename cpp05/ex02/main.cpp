#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

int main()
{
    std::cout << "=== Bureaucrat / AForm Integration Tests ===\n\n";

    try
    {

        Bureaucrat  d("Dandarawy", 50);
        Bureaucrat  m("Medhat", 140);
        Bureaucrat  b("Bourhan", 1);

        std::cout << d << std::endl;
        std::cout << m << std::endl;
        std::cout << b << std::endl << std::endl;

        // create concrete forms
        ShrubberyCreationForm    shrubForm("home");
        RobotomyRequestForm      roboForm("Bender");
        PresidentialPardonForm   presForm("Alice");

        std::cout << shrubForm << std::endl;
        std::cout << roboForm  << std::endl;
        std::cout << presForm  << std::endl << std::endl;

        // attempt signing:
        //    - medhat(140) tries to sign Shrubbery(145) → fail
        m.signForm(shrubForm);
        //    - d(50) tries to sign Shrubbery(145) → success
        d.signForm(shrubForm);
        std::cout << shrubForm << std::endl << std::endl;

        //    - d(50) tries to sign Robotomy(72) → fail
        d.signForm(roboForm);
        //    - b(1) tries to sign Robotomy → success
        b.signForm(roboForm);
        std::cout << roboForm << std::endl << std::endl;

        //    - d(50) tries to sign Presidential(25) → fail
        d.signForm(presForm);
        //    - b(1) tries to sign Presidential → success
        b.signForm(presForm);
        std::cout << presForm << std::endl << std::endl;

        // attempt execution:
        //    - m(140) tries to execute Shrubbery(need 137) → fail (too low)
        m.executeForm(shrubForm);
        //    - d(50) tries to execute Shrubbery (need 137) → fail (still too low)
        d.executeForm(shrubForm);
        //    - b(1) tries to execute Shrubbery → success (file “home_shrubbery” is created)
        b.executeForm(shrubForm);
        std::cout << std::endl;

        //    - b(1) executes Robotomy (need 45) → success or failure message
        b.executeForm(roboForm);
        std::cout << std::endl;

        //    - d(50) tries to execute Presidential (need 5) → fail
        d.executeForm(presForm);
        //    - b(1) executes Presidential → success
        b.executeForm(presForm);
        std::cout << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Unhandled Exception: " << ex.what() << std::endl;
    }

    return 0;
}
