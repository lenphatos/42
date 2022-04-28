SRC = srcs/main.c\
			srcs/ft_loop.c\
			srcs/ft_free.c\
			srcs/ft_init_env.c\
			srcs/ft_export.c\
			srcs/ft_utils_one.c\
			srcs/ft_utils_two.c\
			srcs/ft_unset.c\
			srcs/ft_env.c\
			srcs/ft_exxecve.c\
			srcs/ft_pwd_echo.c\
			srcs/ft_cd.c\
			srcs/pipes.c\
			srcs/ft_redirection.c\
			srcs/ft_exit.c\
			srcs/ft_split.c\
			srcs/ft_replace_env.c\
			srcs/ft_sub_add.c\
			srcs/ft_strcmp_m.c\
			srcs/ft_retire_quote.c\
			srcs/ft_retire_pv.c\
			srcs/ft_cmd.c\
			srcs/ft_retire_slash.c\


NAME = minishell
HEADERS = includes
CC = gcc
CFLAGS = -I Libs/libft -I includes -Wall -Wextra -Werror #-fsanitize=address
O_FILES = $(SRC:.c=.o)


.PHONY: clean fclean re

all : $(NAME)

.SILENT: $(O_FILES)

$(NAME) : $(O_FILES)
	@make -s -C Libs/libft
	@$(CC) $(CFLAGS) $^ -o $(NAME) -L Libs/libft -lft
	@echo "\033[33;32mCompilation...\t""\033[33;31mDONE 🙃"

clean :
	@make -s clean -C Libs/libft
	@rm -f $(O_FILES)
	@echo "\033[33;36mDeleting - *.o..."

fclean : clean
	@make -s fclean -C Libs/libft
	@rm -f $(NAME)
	@echo "\033[33;36mDeleting - exec..."

re : fclean all
