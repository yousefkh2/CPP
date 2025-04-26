#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	//i assume i will take input from the user right away, so why not just use cin?
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (command == "ADD")
		{
			// get contact details
			// call phonebook.addContact()
		}
		else if (command == "SEARCH")
		{
			// display contacts
			// get index
			// display specific contact
		}
		else if (command == "EXIT")
		{
			break;
		}
		else {
			std::cout << "Invalid command. Try again." << std::endl;
		}
	}
	return 0;
}