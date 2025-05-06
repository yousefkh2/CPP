#pragma once
#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		void setFirstName(const std::string& fn);
		void setLastName(const std::string& ln);
		void setNickname(const std::string& nn);
		void setPhoneNumber(const std::string& pn);
		void setDarkestSecret(const std::string& ds);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};



