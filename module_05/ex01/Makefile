# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 17:32:04 by cbernot           #+#    #+#              #
#    Updated: 2023/10/06 10:20:10 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Bureaucrat
SRCS=main.cpp Bureaucrat.cpp Form.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=Bureaucrat.hpp Form.hpp
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re