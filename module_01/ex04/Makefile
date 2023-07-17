# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 18:05:43 by cbernot           #+#    #+#              #
#    Updated: 2023/07/05 18:09:35 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=replace
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=
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