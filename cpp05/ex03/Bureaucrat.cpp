#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

const std::string &Bureaucrat::getName() const noexcept { return _name; }

int Bureaucrat::getGrade() const noexcept { return _grade; }

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

//tries to execute form and prints success or failure accordingly
void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
				<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn’t sign " << form.getName()
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
