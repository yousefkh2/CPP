#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] default constructor called\n";
	for (int i = 0; i < 100; ++i)
		ideas[i] = "empty";
}

Brain::Brain(const Brain& other) {
	std::cout << "[Brain] copy constructor called\n";
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "[Brain] copy assignment called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "[Brain] destructor called\n";
}
std::string Brain::getIdea(int idx) const {
	if (idx < 0 || idx >= 100) return "";
	return ideas[idx];
}

void Brain::setIdea(int idx, const std::string& idea)
{
	if (idx < 0 || idx >= 100) return;
	ideas[idx] = idea;
}