
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

static std::string promptField(const std::string &fieldName)
{
	std::string input;
	while (true)
	{
		std::cout << fieldName << ": " << std::endl;
		if (!std::getline(std::cin, input))
		{
			std::cerr << "\nUnexpected EOF. Exiting.\n";
			std::exit(EXIT_FAILURE);
		}
		if (!input.empty())
			return input;
		std::cerr << fieldName << " cannot be empty. Please try again.\n";
	}
	
}

int	main(void)
{
	PhoneBook	phoneBook; // all is set up now and initialized
	Contact 		c;
	int			idx;
	std::string command;

	while (std::cout << "Enter command (ADD, SEARCH, EXIT):\n",
		std::getline(std::cin, command))
	{
		if (command == "ADD")
		{
			c.setFirstName(promptField("First Name"));
			c.setLastName(promptField("Last Name"));
			c.setNickname(promptField("Nickname"));
			c.setPhoneNumber(promptField("Phone Number"));
			c.setDarkestSecret(promptField("Darkest Secret"));
			phoneBook.addContact(c);
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.getCount() == 0) // check how the count is increased
			{
				std::cout << "PhoneBook is empty." << std::endl;
				continue ;
			}
			phoneBook.displayContacts();
			std::cout << "Enter index to display: ";
			std::string idxStr;
			std::getline(std::cin, idxStr);
			try
			{
				idx = std::stoi(idxStr);
				phoneBook.displayContact(idx);
			}
			catch (...)
			{
				std::cout << "Invalid input." << std::endl;
			}
		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}
	}
	return (0);
}
