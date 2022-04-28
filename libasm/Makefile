SRC= ft_strlen.s\
	 ft_strcpy.s\
	 ft_strcmp.s\
	 ft_write.s\
	 ft_read.s\
	 ft_strdup.s

OBJ = $(SRC:%.s=%.o)
LIB = libasm.a
AR = ar rc
RANLIB = ranlib
CC = nasm -f elf64
RM = rm -f

all: $(LIB)

$(LIB): $(OBJ)
	@echo "Creating Library..."
	@$(AR) $(LIB) $(OBJ)
	@echo "Done."
	@echo "Indexing Library..."
	@$(RANLIB) $(LIB)
	@echo "Done."

%.o: %.s libasm.h
	@echo "Compiling $<"
	@$(CC) $<

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Done."

fclean: clean
	@$(RM) $(LIB)
	@echo "Done."

re: fclean all
