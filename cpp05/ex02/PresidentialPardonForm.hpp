#pragma once

#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other) = default;
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm() override = default;

	void executeAction() const override;

	private:
		const std::string _target;

		static constexpr int _signGrade = 25;
		static constexpr int _execGrade = 5;
};