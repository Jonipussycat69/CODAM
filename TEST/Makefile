NAME=test.a

FLAGS=-Wall -Werror -Wextra

RM=rm -f

SRC=test1.c test2.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

a: all
	$(RM) $(OBJ)

o: $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re a o