CXX      = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
NAME     = ex02

SRCS     = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
