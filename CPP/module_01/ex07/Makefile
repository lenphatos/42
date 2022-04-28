SRC = srcs/main.cpp
NAME = replace
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
O_FILES = $(SRC:.cpp=.o)


.PHONY: clean fclean re

all : $(NAME)

.SILENT: $(O_FILES)

$(NAME) : $(O_FILES)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "\033[33;32mCompilation...\t""\033[33;31mDONE 🙃"

clean :
	@rm -f $(O_FILES)
	@echo "\033[33;36mDeleting - *.o..."

fclean : clean
	@rm -f $(NAME)
	@echo "\033[33;36mDeleting - exec..."

re : fclean all

test :
	@echo "---------FILE_1----------"
	./$(NAME) files/file1 les LES
	cat files/file1.replace
	@echo "\n---------FILE_2----------"
	./$(NAME) files/file2 pos POSITION
	cat files/file2.replace
	@echo "\n---------FILE_3----------"
	./$(NAME) files/file3 ok ko
	cat files/file3.replace
	@echo "\n--------ERROR_1---------"
	./$(NAME) file1 les
	@echo "\n--------ERROR_2---------"
	./$(NAME) file1 les les les
	@echo "\n--------ERROR_3---------"
	./$(NAME) this bonjour ok
