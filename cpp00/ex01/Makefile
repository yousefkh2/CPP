.PHONY: all clean fclean re
NAME     := phonebook
CXX      := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 -pedantic

SRC     := main.cpp Contact.cpp PhoneBook.cpp
OBJ     := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)