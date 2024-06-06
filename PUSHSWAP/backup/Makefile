NAME=pushswap.a

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(EXE)

re: fclean all

.PHONY: all clean fclean re