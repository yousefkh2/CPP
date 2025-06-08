#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

// helper creators
static AForm *createShrub(const std::string &t) {
  return new ShrubberyCreationForm(t);
}
static AForm *createRobo(const std::string &t) {
  return new RobotomyRequestForm(t);
}
static AForm *createPres(const std::string &t) {
  return new PresidentialPardonForm(t);
}

struct FormType {
  std::string name;
  AForm *(*maker)(const std::string &);
};

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  static const FormType table[] = {{"shrubbery creation", createShrub},
                                   {"robotomy request", createRobo},
                                   {"presidential pardon", createPres}};

  for (const auto &entry : table) {
    if (formName == entry.name) {
      AForm *form = entry.maker(target);
      std::cout << "Intern creates " << formName << std::endl;
      return form;
    }
  }

  std::cout << "Intern could not create " << formName << std::endl;
  return nullptr;
}
