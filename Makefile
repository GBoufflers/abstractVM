NAME=		abstractVM

CXX=		g++
CC=		$(CXX)
CXXFLAGS=	-W -Wall -Wextra -I include

OBJ=		main.o				\

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
