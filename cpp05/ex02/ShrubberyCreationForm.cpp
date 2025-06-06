#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreation", _signGrade, _execGrade), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreation", _signGrade, _execGrade), _target(target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    // _target is const
  }
  return *this;
}

void ShrubberyCreationForm::executeAction() const {
  const std::string filename = _target + "_shrubbery";
  std::ofstream ofs(filename.c_str());
  if (!ofs)
    throw std::runtime_error("ShrubberyCreationForm: failed to open file");

  ofs << "       _-_\n";
  ofs << "    /~~   ~~\\\n";
  ofs << " /~~         ~~\\\n";
  ofs << "{               }\n";
  ofs << " \\  _-     -_  /\n";
  ofs << "   ~  \\\\ //  ~\n";
  ofs << "_- -   | | _- _\n";
  ofs << "  _ -  | |   -_\n";
  ofs << "      // \\\\\n";
  ofs.close();
}
