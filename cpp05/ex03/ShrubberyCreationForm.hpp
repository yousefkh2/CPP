#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
public:
  // Orthodox C. F.
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other) = default;
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm() override = default;

  void executeAction() const override;

private:
  const std::string _target;

  static constexpr int _signGrade = 145;
  static constexpr int _execGrade = 137;
};
