NAME = identify
CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

SRCS = main.cpp identify.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = Base.hpp identify.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re