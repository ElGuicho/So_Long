# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 16:48:58 by gmunoz            #+#    #+#              #
#    Updated: 2024/09/25 17:16:19 by gmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Leak check
LEAKS =  valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all

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
SRC = src/main.c src/mlx_funct.c src/char_moveset.c src/init_code.c \
src/draw_world.c src/map_checker.c src/erase_world.c src/map_path.c \
src/map_checker2.c src/check_path.c \
gnl/get_next_line.c gnl/get_next_line_utils.c

# Object files
OBJS = $(SRC:.c=.o)

# Default NAME
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -j -C mlx_linux
	$(MAKE) -j -C Libft
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