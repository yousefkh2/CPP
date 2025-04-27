#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
    : count(0), nextIndex(0) {}

void PhoneBook::addContact(const Contact& contact) {
    contacts[nextIndex] = contact;
    nextIndex = (nextIndex + 1) % 8;
    if (count < 8)
        count++;
}

int PhoneBook::getCount() const {
    return count;
}

static std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(10) << i + 1 << "|"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 1 || index > count) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    const Contact& c = contacts[index - 1];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}