#pragma once
#include "Contact.hpp"


class PhoneBook {
private: 
	Contact contacts[8];
	int count;
	int nextIndex;

public:
	PhoneBook();
	void addContact(const Contact& contact);
	void displayContacts() const;
	void displayContact(int index) const;
	int getCount() const;
};
