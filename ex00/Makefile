
NAME = fixed

SRCS = Fixed.cpp main.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
    $(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -rf $(NAME)

fclean: clean
    rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re