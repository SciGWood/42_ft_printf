# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:10:42 by gdetourn          #+#    #+#              #
#    Updated: 2023/12/11 11:27:39 by gdetourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
CC		= cc

SRC		= 	ft_printf.c \
			ft_str.c \
			ft_putnbr_base.c \

OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
		ar rc $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re