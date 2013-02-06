NAME=		abstractVM

CXX=		g++
CC=		$(CXX)

OBJ=		main.o					\
		IOP/Int8.o				\
		IOP/Int16.o				\
		IOP/Int32.o				\
		IOP/Double.o				\
		IOP/Float.o				\

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
