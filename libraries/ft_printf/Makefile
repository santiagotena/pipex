# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 19:15:00 by stena-he          #+#    #+#              #
#    Updated: 2022/07/03 21:19:50 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC =	ft_printf.c\
		ft_put_char.c\
		ft_put_str.c\
		ft_put_ptr.c\
		ft_put_nbr.c\
		ft_put_unsign.c\
		ft_put_hexadec.c\
			
OUT_SRC = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OUT_SRC)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs	$(NAME)	$(OUT_SRC)

clean:
	$(RM) $(OUT_SRC) $(OUT_BONUS)
	$(RM) */*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) libft/libft.a

re: fclean all

.PHONY: all clean fclean re