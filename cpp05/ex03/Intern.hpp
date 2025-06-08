#pragma once

#include <string>
#include "AForm.hpp"


class Intern
{
	public:
	Intern() = default;
	Intern(const Intern& other) = default;
	Intern& operator=(const Intern& other) = default;
	~Intern() = default;

	AForm* makeForm(const std::string& formName, const std::string& formTarget) const;

};

