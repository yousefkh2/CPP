#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardon", _signGrade, _execGrade), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardon", _signGrade, _execGrade), _target(target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

// executeAction
void PresidentialPardonForm::executeAction() const {
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}