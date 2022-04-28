# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 14:34:54 by simoulin          #+#    #+#              #
#    Updated: 2019/11/10 19:29:04 by simoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = includes

CC = gcc

WALL = -Wall -Wextra -Werror

SRC = ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_atoi.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_calloc.c ft_itoa.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJB = $(BONUS:.c=.o)

all	: $(NAME)

%.o: %.c
	$(CC) -I $(HEADERS) -c $(WALL) $< -o $@

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus : $(OBJ) $(OBJB)
	ar -rc $(NAME) $(OBJ) $(OBJB)

clean :
	rm -f $(OBJ) $(OBJB)

fclean : clean
	rm -f $(NAME)

re : fclean all
