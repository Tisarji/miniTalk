# Colors
COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

# Project Names
NAME_SERVER = server
NAME_CLIENT = client

RM = rm -rf

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Paths
PATH_LIBFT = libft
PATH_SRCS = srcs
PATH_INCLUDES = includes

# Source Files
SRC_SERVER = server.c

SRC_CLIENT = client.c

# Object Files
OBJ_DIR = objs
OBJ_SERVER = $(addprefix $(OBJ_DIR)/, $(SRC_SERVER:.c=.o))
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT:.c=.o))

# Rules
all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) -L$(PATH_LIBFT) -lft
	@echo "[$(COLOR_YELLOW)$(NAME_SERVER) --> OK$(COLOR_RESET)]\n ${COLOR_GREEN}Success!${COLOR_RESET}"
	@echo "$(COLOR_PINK)\tUsage: $(NAME_SERVER)$(COLOR_RESET)"

$(NAME_CLIENT): $(OBJ_CLIENT)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) -L$(PATH_LIBFT) -lft
	@echo "[$(COLOR_YELLOW)$(NAME_CLIENT) --> OK$(COLOR_RESET)]\n ${COLOR_GREEN}Success!${COLOR_RESET}"
	@echo "$(COLOR_PINK)\tUsage: $(NAME_CLIENT)$(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $<"

clean:
	@make clean -C $(PATH_LIBFT)
	@$(RM) $(OBJ_DIR)
	@echo "$(COLOR_RED)Cleaned up object files$(COLOR_RESET)"
	@$(RM) .DS_Store

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "$(COLOR_RED)Cleaned up executables$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
