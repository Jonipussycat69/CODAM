# MAKEFILE FOR TESTIG!!!!!

NAME=pswptest.a

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

EXE=test

SRC= *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

frun:
	@cc $(CFLAGS) $(SRC) -o $(EXE)
	@./$(EXE)

run:
	@cc $(SRC) -o $(EXE)
	@./$(EXE)
clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(EXE)

ftest: frun fclean
test: run fclean

re: fclean all

.PHONY: all clean fclean re test