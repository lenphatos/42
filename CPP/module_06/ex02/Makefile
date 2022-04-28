SRC = 	main.cpp\
		A.cpp\
		B.cpp\
		C.cpp\
		Base.cpp


NAME = cast
HEADERS = includes
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
O_FILES = $(SRC:.c=.o)


.PHONY: clean fclean re

all : $(NAME)

.SILENT: $(O_FILES)

$(NAME) : $(O_FILES)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "\033[33;32mCompilation...\t""\033[33;31mDONE 🙃"

clean :
	@echo "\033[33;36mDeleting - *.o..."

fclean : clean
	@rm -f $(NAME)
	@echo "\033[33;36mDeleting - exec..."

re : fclean all
