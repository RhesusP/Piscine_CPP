# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 23:14:46 by cbernot           #+#    #+#              #
#    Updated: 2023/07/05 10:32:56 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=PhoneBook
SRCS=main.cpp Contact.cpp PhoneBook.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=Contact.hpp PhoneBook.hpp
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
