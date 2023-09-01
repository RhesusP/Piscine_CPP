# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 17:32:04 by cbernot           #+#    #+#              #
#    Updated: 2023/09/01 14:23:37 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Materia
SRCS		=	src/main.cpp			src/AMateria.cpp		\
				src/Character.cpp		src/Cure.cpp			\
				src/Ice.cpp				src/MateriaSource.cpp
OBJS		=	$(SRCS:.cpp=.o)
INCLUDES	=	inc/AMateria.hpp		inc/Character.hpp		\
				inc/Cure.hpp			inc/Ice.hpp				\
				inc/ICharacter.hpp		inc/IMateriaSource.hpp	\
				inc/MateriaSource.hpp
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

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