#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequest", _signGrade, _execGrade),
		_target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequest", _signGrade, _execGrade),
	_target(target) {}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

// executeAction
void RobotomyRequestForm::executeAction() const
{
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		seeded = true;
	}

	std::cout << "Bzzzzz.. bzzzzz.. (drilling noises)" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
	 	std::cout << _target << " robotomy failed." << std::endl;
}