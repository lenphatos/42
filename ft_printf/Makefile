# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 16:51:20 by simoulin          #+#    #+#              #
#    Updated: 2019/11/27 16:02:15 by simoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = libftprintf.h

CC = gcc

WALL = -Wall -Wextra -Werror

SRC =	ft_printf.c ft_fct_print_one.c ft_fct_print_two.c ft_fct_putchar.c ft_fct.c ft_hexa.c ft_itoa.c

OBJ = $(SRC:.c=.o)

OBJB = $(BONUS:.c=.o)

all	: $(NAME)

%.o: %.c
	$(CC) -I $(HEADER) -c $(WALL) $< -o $@

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ) $(OBJB)

fclean : clean
	rm -f $(NAME)

re : fclean all
