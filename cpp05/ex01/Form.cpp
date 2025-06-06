#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("Default"), _isSigned(false), _gradeToSign(_lowest),
      _gradeToExec(_lowest) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
  if (gradeToSign < _highest || gradeToExec < _highest)
    throw GradeTooHighException();
  if (gradeToSign > _lowest || gradeToExec > _lowest)
    throw GradeTooLowException();
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    _isSigned = other._isSigned;
    // other attributes are const --> no assignment
  }
  return *this;
}

// getters
const std::string &Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _isSigned; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExec() const { return _gradeToExec; }

// beSigned
void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= _gradeToSign) {
    _isSigned = true;
  } else {
    throw GradeTooLowException();
  }
}

// exception message
Form::GradeTooHighException::GradeTooHighException()
    : std::runtime_error(
          "Form::GradeTooHighException: grade requirement cannot be < 1") {};

Form::GradeTooLowException::GradeTooLowException()
    : std::runtime_error(
          "Form::GradeTooLowException: grade requirement cannot be > 150 or "
          "bureaucrat's grade too low") {};

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << f.getName() << ", signed: " << (f.getIsSigned() ? "true" : "false")
     << ", grade required to sign: " << f.getGradeToSign()
     << ", grade required to execute: " << f.getGradeToExec();
  return os;
}
