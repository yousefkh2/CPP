NAME      = ex03
CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++17

SRCS =  \
    Bureaucrat.cpp               \
    AForm.cpp                    \
    ShrubberyCreationForm.cpp    \
    RobotomyRequestForm.cpp      \
    PresidentialPardonForm.cpp   \
    Intern.cpp                   \
    main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME) home_shrubbery

re: fclean all

.PHONY: all clean fclean re
