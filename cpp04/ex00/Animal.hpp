#pragma once

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type;
public:
	// Orthodox C. F.
	Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const;
	std::string getType() const;

};