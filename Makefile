NAME=		abstractVM

CXX=		g++ -Wall -Werror -Wextra

CC=		$(CXX)

OBJ=		core/main.o					\

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
