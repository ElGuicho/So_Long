# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 16:48:58 by gmunoz            #+#    #+#              #
#    Updated: 2024/06/19 18:47:33 by gmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc	

# Compiler flags
CFLAGS      = -Wall -Werror -Wextra -I/usr/include -Imlx_linux
MLX_FLAGS   = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# Source files
SRCS = main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADER = push_swap.h

# Executable name
NAME = so_long

# Default NAME
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
$(NAME): $(OBJS)
	@$(MAKE) -C mlx_linux
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Clean up generated files
clean:
	@$(MAKE) clean -C mlx_linux
	rm -f $(OBJS)

# Clean up everything
fclean:
	rm -f $(NAME) $(OBJS)

# Re-compile everything
re: fclean all

.PHONY: all clean fclean re