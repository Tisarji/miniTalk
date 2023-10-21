# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 16:04:10 by jikarunw          #+#    #+#              #
#    Updated: 2023/10/21 17:33:27 by jikarunw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CLAGES = -Wall -Wextra -Werror
RM = rm -f

SRC =	ft_printf.c \
		ft_printf_hex.c \
		ft_printf_char.c \
		ft_printf_string.c \
		ft_printf_nbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): ${OBJ}
	ar rc $(NAME) $(OBJ)

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
