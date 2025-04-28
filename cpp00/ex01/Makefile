.PHONY: all clean fclean re

NAME = phonebook

all: $(NAME)

$(NAME): main.cpp Contact.cpp PhoneBook.cpp
	g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) main.cpp Contact.cpp PhoneBook.cpp

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all