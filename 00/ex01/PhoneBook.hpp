
#pragma once


#include <iostream>
#include "Contact.hpp"


class PhoneBook {
	private: 
	Contact contacts[8];
	int currentIndex;

	public:
	PhoneBook() {
		// contacts[8] = {0};
		currentIndex = 0;
	}
	~PhoneBook();

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
	
	void displayContacts() const;
/*	shouldn't searching a contact be ennough? why would we need this. let's see. */
	void exit() const
	{
		/*how are you going to exit? */
	}

};



#endif

