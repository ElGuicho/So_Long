# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 15:11:47 by gmunoz            #+#    #+#              #
#    Updated: 2024/04/17 14:24:45 by gmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc	

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = ft_printf_utils.c ft_printf.c hexa_conversion.c printchar.c printdec.c \
	printhexa.c printptr.c printstr.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADER = printf.h

# Executable name
NAME = libftprintf.a

# Default NAME
all: $(NAME)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

# Clean up generated files
clean:
	rm -f $(OBJS)

#
fclean:
	rm -f $(NAME) $(OBJS)

# Re-compile everything
re: fclean all

.PHONY: all clean fclean re