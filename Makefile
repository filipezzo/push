# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 17:45:28 by fsousa            #+#    #+#              #
#    Updated: 2025/10/28 16:39:29 by fsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
EXEC = $(BIN_DIR)/$(NAME)

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES = main.c \
			list_utils.c \
			debug_utils.c \
			free_utils.c \
			parsing_utils.c \
			error_handling.c \
			robust_atoi.c \
			operations_rotate_reverse.c \
			operations_rotate.c \
			operations_swap.c \
			operations_push.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
HEADERS = $(addprefix $(INCLUDE_DIR)/, push_swap.h)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(INCLUDE_DIR) -I $(LIBFT_DIR)/include
LDFLAGS = -L $(LIBFT_DIR) -lft
RM = rm -rf

all: $(EXEC)

$(EXEC): $(OBJS) $(LIBFT)
		@mkdir -p $(BIN_DIR)
		@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(EXEC)
		@echo "[\033[0;32mOK\033[0m] $(NAME) compilado em $(BIN_DIR)/!"

$(LIBFT):
		@echo "[\033[0;33m...\033[0m] Compilando libft..."
		@$(MAKE) -C $(LIBFT_DIR) --silent 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
		@echo "[\033[0;32mOK\033[0m] Compilado: $<"

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@echo "[\033[0;31mOK\033[0m] Arquivos objeto limpos."

fclean: clean
	$(RM) $(BIN_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@echo "[\033[0;31mOK\033[0m] Limpeza completa."

re: fclean all

.PHONY: all clean fclean re