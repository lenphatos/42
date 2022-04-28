SRC = 	srcs/main.c\
		srcs/action.c\
		srcs/display.c\
		srcs/exit.c\
		srcs/init.c\
		srcs/monitor.c\
		srcs/philosopher.c\
		srcs/utils.c

NAME = philo_three
HEADERS = includes
CC = gcc
CFLAGS = -I includes -Wall -Wextra -Werror #-fsanitize=address
O_FILES = $(SRC:.c=.o)


.PHONY: clean fclean re

all : $(NAME)

.SILENT: $(O_FILES)

$(NAME) : $(O_FILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) -lpthread
	@echo "\033[33;32mCompilation...\t""\033[33;31mDONE 🙃"

clean :
	@rm -f $(O_FILES)
	@echo "\033[33;36mDeleting - *.o..."

fclean : clean
	@rm -f $(NAME)
	@echo "\033[33;36mDeleting - exec..."

re : fclean all
