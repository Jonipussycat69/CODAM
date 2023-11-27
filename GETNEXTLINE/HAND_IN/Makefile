NAME=get_next_line.a

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= get_next_line.c get_next_line_utils.c

BONUS_SRC= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ=$(SRC:.c=.o)
BONUS_OBJ=$(BONUS_SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(BONUS_OBJ)
	@ar rc $(NAME) $(OBJ) $(BONUS_OBJ)
	ranlib $(NAME)

bonus: $(BONUS_OBJ)
	@ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re