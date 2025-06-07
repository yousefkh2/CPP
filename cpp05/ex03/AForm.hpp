#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

// forward‐declare Bureaucrat so we can use it in beSigned()
class Bureaucrat;

class AForm {
public:
  // Orthodox C. F.
  AForm();
  AForm(const std::string &name, int gradeToSign, int gradeToExec);
  AForm(const AForm &other) = default;
  AForm &operator=(const AForm &other);
  virtual ~AForm() = default;

  // getters
  const std::string &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExec() const;

  // beSigned: attempt to sign this AForm with Bureaucrat b
  void beSigned(const Bureaucrat &b);

  // will check signed + executor's grade, then calls exectute Action()
  void execute(const Bureaucrat &executor) const;

  virtual void executeAction() const = 0;

  // exception classes
  class GradeTooHighException : public std::runtime_error {
  public:
    GradeTooHighException();
  };

  class GradeTooLowException : public std::runtime_error {
  public:
    GradeTooLowException();
  };

  class FormNotSignedException : public std::runtime_error {
  public:
    FormNotSignedException();
  };

private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;

  static constexpr int _highest = 1;
  static constexpr int _lowest = 150;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
