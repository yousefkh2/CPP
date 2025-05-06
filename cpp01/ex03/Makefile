
CXX       := c++
CXXFLAGS  := -std=c++17 -Wall -Wextra -Werror
TARGET    := ex03
SRCS      := Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
OBJS      := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
