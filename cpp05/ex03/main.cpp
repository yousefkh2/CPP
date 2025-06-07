#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
  Intern someRandomIntern;
  Bureaucrat boss("Dandarawy", 1);

  // 1. valid creations
  AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "home");
  AForm *f2 = someRandomIntern.makeForm("robotomy request", "Bender");
  AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Alice");

  // 2. invalid name
  AForm *f4 = someRandomIntern.makeForm("unknown form", "Nothing");

  std::cout << std::endl;

  // 3. use boss to sign and execute each valid form
  if (f1) {
    boss.signForm(*f1);
    boss.executeForm(*f1);
    delete f1;
  }
  if (f2) {
    boss.signForm(*f2);
    boss.executeForm(*f2);
    delete f2;
  }
  if (f3) {
    boss.signForm(*f3);
    boss.executeForm(*f3);
    delete f3;
  }
  if (f4)
    delete f4;

  return 0;
}
