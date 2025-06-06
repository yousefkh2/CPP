#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(_lowest) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < _highest)
    throw GradeTooHighException();
  if (grade > _lowest)
    throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->_grade = other._grade;
    // _name is const and initialized once, not assignable
  }
  return *this;
}

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
  if (_grade - 1 < _highest)
    throw GradeTooHighException();
  --_grade;
}

void Bureaucrat::decrementGrade() {
  if (_grade + 1 > _lowest)
    throw GradeTooLowException();
  ++_grade;
}

void Bureaucrat::signForm(Form& f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn’t sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
	: std::runtime_error("GradeTooHighException: grade cannot be higher than 1") {}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("GradeTooLowException: grade cannot be lower than 150") {}

// prints name and grade
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}
