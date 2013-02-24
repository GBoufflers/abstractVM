NAME=		abstractVM

CXX=		g++ -g -Wall -Wextra -W -Werror

CC=		$(CXX)

OBJ=		core/main.o \
		src/Memory.o \
		src/Io.o \
		src/Bios.o \
		src/Chipset.o \
		src/Cpu.o \
		src/MotherBoard.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
