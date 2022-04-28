# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 16:51:20 by simoulin          #+#    #+#              #
#    Updated: 2020/03/04 11:28:05 by simoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = gcc

WALL = -Wall -Wextra -Werror

INCLUDE = cub3d.h

SRC = main.c ft_utils_one.c get_next_line.c get_next_line_utils.c ft_parsing.c ft_cub3d.c ft_moove_player.c ft_parsing_map.c ft_calcul_distance.c ft_parsing_texture.c ft_count_fct.c ft_parsing_texture_two.c ft_parsing_floor_sky.c ft_parsing_resolution.c ft_print.c ft_calcul_sprite.c ft_key_press.c ft_bmp.c ft_bmp_t.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) -I $(INCLUDE) $(WALL) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) -I /usr/x11/include $(OBJ) -lmlx -framework OpenGL -framework AppKit

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
