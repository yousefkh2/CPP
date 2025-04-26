#pragma once

#include <iostream>
#include <iomanip>
#include "Contact.hpp"


class PhoneBook {
	private: 
	Contact contacts[8];
	int currentIndex;

	public:
	PhoneBook() {
		currentIndex = 0;
	}

	void addContact(const std::string &name, const std::string &phoneNumber,const std::string &email) {
		contacts[currentIndex].setName(name);
		contacts[currentIndex].setPhoneNumber(phoneNumber);
		contacts[currentIndex].setEmail(email);
		currentIndex = (currentIndex + 1) % 8;
		std::cout << "Contact added successfully." << std::endl;
	}
	void searchContact(const std::string &name) const {
		bool found = false;
		for (int i = 0; i < 8; i++)
		{
			if (!contacts[i].isEmpty() && contacts[i].getName() == name) {
				std::cout << "Contact found at position " << i << ":" << std::endl;
				std::cout << "Name: " << contacts[i].getName() << std::endl;
				std::cout << "Phone: " << contacts[i].getPhoneNumber() << std::endl;
				std::cout << "Email: " << contacts[i].getEmail() << std::endl;
				found = true;
				break;
			}
		}
		if (!found)
		{
			std::cout << "Contact not found." << std::endl;
		}
	}
	
	void displayContacts() const {
		std::cout << "+-----------+-----------+-----------+-----------+" << std::endl;
		std::cout << "| Index     | Name      | Phone     | Email     |" << std::endl;
		std::cout << "+-----------+-----------+-----------+-----------+" << std::endl;
		bool hasContacts = false;

		for (int i = 0;  i < 8; i++) {
			if (!contacts[i].isEmpty()) {
				hasContacts = true;
				std::cout << "| " << std::setw(10) << i << "|";
				std::cout << " " << std::setw(10) << contacts[i].getName() << "|";
				std::cout << " " << std::setw(10) << contacts[i].getPhoneNumber() << "|";
				std::cout << " " << std::setw(10) << contacts[i].getEmail() << "|" << std::endl;
			}
		}
		std::cout << "+-----------+-----------+-----------+-----------+" << std::endl;
		if (!hasContacts)
		{
			std::cout << "No contacts found." << std::endl;
		}
	}
};