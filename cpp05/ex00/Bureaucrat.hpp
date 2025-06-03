#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

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
  void incrementGrade(); // grade-- (higher rank)
  void decrementGrade(); // grade++ (lower rank)

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
  int _grade;

  static constexpr int _highest = 1;
  static constexpr int _lowest = 150;
};

// overload of operator<<
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
