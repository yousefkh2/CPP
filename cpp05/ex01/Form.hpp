#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

// forward‐declare Bureaucrat so we can use it in beSigned()
class Bureaucrat;

class Form {
public:
  // Orthodox C. F.
  Form(); // default ctor
  Form(const std::string &name, int gradeToSign, int gradeToExec);
  Form(const Form &other) = default;
  Form &operator=(const Form &other);
  ~Form() = default;

  // getters
  const std::string &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExec() const;

  // beSigned: attempt to sign this form with Bureaucrat b
  void beSigned(const Bureaucrat &b);

  // exception classes
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;

  static constexpr int _highest = 1;
  static constexpr int _lowest = 150;
};

std::ostream &operator<<(std::ostream &os, const Form &f);
