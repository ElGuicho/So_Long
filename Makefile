# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 16:48:58 by gmunoz            #+#    #+#              #
#    Updated: 2024/08/12 18:12:09 by gmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Key Codes for Linux
ESC = KEY_ESC=65307
W = KEY_W=119
A = KEY_A=97
S = KEY_S=115
D = KEY_D=100
UP = KEY_UP=65362
DOWN = KEY_DOWN=65364
LEFT = KEY_LEFT=65361
RIGHT = KEY_RIGHT=65363
R = KEY_R=114
Q = KEY_Q=113

#Properties for Linux
LEAKS =  valgrind --leak-check=full --show-leak-kinds=all -s -q 
LMLX = -lmlx -lXext -lX11
GAME = game_linux.c
RENDER = render_linux.c
GRATE = GAME_RATE=80
CDEBUG =

# Executable name
NAME = so_long

# Libft
LIBFT = ./Libft/libft.a

# Compiler
CC = gcc

# Compiler flags
CFLAGS      = -Wall -Werror -Wextra -I/usr/include -Imlx_linux
MLX_FLAGS   = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# Source files
SRC = src/main.c gnl/get_next_line.c gnl/get_next_line_utils.c

# Object files
OBJS = $(SRC:.c=.o)

# Default NAME
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C mlx_linux
	$(MAKE) -C Libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Link object files into the executable
$(NAME): $(OBJS)

# Clean up generated files
clean:
	$(MAKE) clean -C mlx_linux
	$(MAKE) fclean -C Libft
	rm -f $(OBJS)

# Clean up everything
fclean: clean
	rm -f $(NAME)

# Re-compile everything
re: fclean
	make all

.PHONY: all clean fclean re