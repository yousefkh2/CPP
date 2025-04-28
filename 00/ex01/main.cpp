
#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string promptField(const std::string& fieldName) {
    std::string input;
    // prompt once before entering the loop
	std::cout << fieldName << ": " << std::endl;
	std::getline(std::cin, input);
	return input;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT):\n";
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD") {
            Contact c;
            c.setFirstName(promptField("First Name"));
            c.setLastName(promptField("Last Name"));
            c.setNickname(promptField("Nickname"));
            c.setPhoneNumber(promptField("Phone Number"));
            c.setDarkestSecret(promptField("Darkest Secret"));
            phoneBook.addContact(c);
        } else if (command == "SEARCH") {
            if (phoneBook.getCount() == 0) {
                std::cout << "PhoneBook is empty." << std::endl;
                continue;
            }
            phoneBook.displayContacts();
            std::cout << "Enter index to display: ";
            std::string idxStr;
            std::getline(std::cin, idxStr);
            try {
                int idx = std::stoi(idxStr);
                phoneBook.displayContact(idx);
            } catch (...) {
                std::cout << "Invalid input." << std::endl;
            }
        } else if (command == "EXIT") {
            break;
        }
		else {
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}

    }

    return 0;
}
