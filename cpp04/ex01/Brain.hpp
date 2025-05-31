
#pragma once

#include <iostream>
#include <string>

class Brain {
private:
  std::string ideas[100];

public:
  Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &);
  ~Brain();

  std::string getIdea(int idx) const;
  void setIdea(int idx, const std::string&);
};
