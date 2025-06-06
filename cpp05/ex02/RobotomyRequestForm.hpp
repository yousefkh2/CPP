#pragma once

#include "AForm.hpp"
#include <string>


class RobotomyRequestForm : public AForm
{
	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other) = default;
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm() override = default;

	void executeAction() const override;

	private:
		const std::string _target;

		static constexpr int _signGrade = 72;
		static constexpr int _execGrade = 45;
};