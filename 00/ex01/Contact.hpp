#pragma once
#include <string>

class Contact {
	private:
		std::string name;
		std::string phoneNumber;
		std::string email;
	
	public:
		Contact() : name(""), phoneNumber(""), email("") {
		}
		//GETTERS
		std::string getName() const {
			return name;
		}
		std::string getPhoneNumber() const {
			return phoneNumber;
		}
		std::string getEmail() const {
			return email;
		}
		//SETTERS
		void setName(const std::string &name) {
			this->name = name;
		}
		void setPhoneNumber(const std::string &phoneNumber) {
			this->phoneNumber = phoneNumber;
		}
		void setEmail(const std::string &email) {
			this->email = email;
		}
		//METHODS
		bool isEmpty() const {
			return name.empty() && phoneNumber.empty() && email.empty();
		}
};
