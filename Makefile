# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 20:13:25 by stena-he          #+#    #+#              #
#    Updated: 2022/12/12 17:37:42 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME = 	pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Libraries
LIBFT = libraries/ft_printf/libft/libft.a
PRINTF = libraries/ft_printf/libftprintf.a

# Paths
SRC_PATH = src/
OBJ_PATH = obj/
LIBFT_PATH = libraries/ft_printf/libft
PRINTF_PATH = libraries/ft_printf

# Source and object files
SRC =	main.c \
		pipes_setup.c \
		do_cmd.c \
		errors.c \
		utils.c

# Add prefixes
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C $(LIBFT_PATH)
	$(MAKE) -C $(PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	
clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(PRINTF_PATH)

fclean: clean
	rm -f $(OBJ)
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(MAKE) fclean -C $(PRINTF_PATH)
	
re: fclean all

.PHONY: all clean fclean re