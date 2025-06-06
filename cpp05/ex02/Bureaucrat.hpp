#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
// #include "AForm.hpp"

// forward‐declare Form so we can refer to it in signForm()
// (definition of Form comes in Form.hpp/Form.cpp)
class AForm;

class Bureaucrat {
public:
  // Orthodox C. F.
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other) = default;
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat() = default;

  // getters
  const std::string &getName() const noexcept;
  int getGrade() const noexcept;

  // grade modifiers
  void incrementGrade(); // improves rank: grade--
  void decrementGrade(); // lowers rank:  grade++


  void executeForm(const AForm& form) const;
  void signForm(AForm &f) const;

  // exception classes
  class GradeTooHighException : public std::runtime_error {
	public:
	  GradeTooHighException();
	};
  
	class GradeTooLowException : public std::runtime_error {
	public:
	  GradeTooLowException();
	};

private:
  const std::string _name;
  int _grade;

  static constexpr int _highest = 1;
  static constexpr int _lowest = 150;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
