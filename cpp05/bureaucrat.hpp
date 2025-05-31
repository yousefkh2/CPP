#pragma once
#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
private:
  const std::string name;
  unsigned int grade;

public:
  explicit Bureaucrat(const std::string &name, unsigned int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  // getters
  const std::string &getName() const;
  unsigned int getGrade() const;

  // modifiers
  void incrementGrade(); // --grade
  void decrementGrade(); // ++grade    
};

// exceptions

class GradeTooHighException : public std::exception {
public:
  const char *what() const noexcept override;
};
class GradeTooLowException : public std::exception {
public:
  const char *what() const noexcept override;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);