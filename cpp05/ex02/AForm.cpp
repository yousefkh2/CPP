#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Default"), _isSigned(false), _gradeToSign(_lowest),
      _gradeToExec(_lowest) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
  if (gradeToSign < _highest || gradeToExec < _highest)
    throw GradeTooHighException();
  if (gradeToSign > _lowest || gradeToExec > _lowest)
    throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    _isSigned = other._isSigned;
    // other attributes are const --> no assignment
  }
  return *this;
}

// getters
const std::string &AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExec() const { return _gradeToExec; }

// beSigned
void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= _gradeToSign) {
    _isSigned = true;
  } else {
    throw GradeTooLowException();
  }
}

void AForm::execute(const Bureaucrat &executor) const {
  if (!_isSigned)
    throw FormNotSignedException();
  if (executor.getGrade() > _gradeToExec)
    throw GradeTooLowException();
  executeAction();
}

// exception message
const char *AForm::GradeTooHighException::what() const noexcept {
  return "AForm::GradeTooHighException: grade requirement cannot be < 1";
}

const char *AForm::GradeTooLowException::what() const noexcept {
  return "AForm::GradeTooLowException: grade requirement cannot be > 150 or "
         "bureaucrat's grade too low";
}

const char *AForm::FormNotSignedException::what() const noexcept {
  return "AForm::FormNotSignedException: form is not signed yet";
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << f.getName() << ", signed: " << (f.getIsSigned() ? "true" : "false")
     << ", grade required to sign: " << f.getGradeToSign()
     << ", grade required to execute: " << f.getGradeToExec();
  return os;
}
