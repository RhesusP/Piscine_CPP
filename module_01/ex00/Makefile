# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 12:14:10 by cbernot           #+#    #+#              #
#    Updated: 2023/07/05 12:24:31 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Zombie
SRCS=Zombie.cpp randomChump.cpp newZombie.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=Zombie.hpp
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