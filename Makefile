# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 15:21:26 by jikarunw          #+#    #+#              #
#    Updated: 2023/10/21 17:12:14 by jikarunw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

PRINTF = libftprintf.a
FT_PRINTF_DIR = ft_printf
INCLUDE = -I include

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_SERVER =	ft_server.c \
				ft_utils.c

SRC_CLIENT =	ft_client.c \
				ft_utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(INCLUDE) $(FT_PRINTF_DIR)/$(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(INCLUDE) $(FT_PRINTF_DIR)/$(PRINTF) -o $(NAME_CLIENT)

clean:
	make clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	make fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(OBJ_SERVERL) $(OBJ_CLIENT)

re: fclean all

.PHONY: all clean fclean re
