#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main() {
  std::cout << "=== Bureaucrat / AForm Integration Tests ===\n\n";

  try {
    Bureaucrat d("Mr. Gamal", 50);
    Bureaucrat m("Nabil from Archives", 140);
    Bureaucrat b("Madame Aziza", 1);

    std::cout << d << std::endl;
    std::cout << m << std::endl;
    std::cout << b << std::endl << std::endl;

    // create concrete forms
    ShrubberyCreationForm shrubForm("home");
    RobotomyRequestForm roboForm("RoboCop");
    PresidentialPardonForm presForm("Alice");

    std::cout << shrubForm << std::endl;
    std::cout << roboForm << std::endl;
    std::cout << presForm << std::endl << std::endl;

    // attempt signing:
    m.signForm(shrubForm);
    d.signForm(shrubForm);
    std::cout << shrubForm << std::endl << std::endl;

    d.signForm(roboForm);
    b.signForm(roboForm);
    std::cout << roboForm << std::endl << std::endl;

    d.signForm(presForm);
    b.signForm(presForm);
    std::cout << presForm << std::endl << std::endl;

    // attempt execution:
    m.executeForm(shrubForm);
    d.executeForm(shrubForm);
    b.executeForm(shrubForm);
    std::cout << std::endl;
    b.executeForm(roboForm);
    std::cout << std::endl;

    d.executeForm(presForm);
    b.executeForm(presForm);
    std::cout << std::endl;
  } catch (const std::exception &ex) {
    std::cerr << "Unhandled Exception: " << ex.what() << std::endl;
  }

  return 0;
}
