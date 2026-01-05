# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 21:25:56 by skomatsu          #+#    #+#              #
#    Updated: 2026/01/05 22:17:36 by skomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SRCS = Fixed.cpp main.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re