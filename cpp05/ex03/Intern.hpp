#pragma once



class Intern
{
	public:
	Intern();
	Intern(const Intern& other) = default;
	Intern& operator=(const Intern& other) = default;
	~Intern() = default;

	void makeForm() const;

};