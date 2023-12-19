NAME=libftprintf.a

CFLAGS=-Wall -Werror -Wextra

RM=rm -f

SRC_DIR=ft_printf_mandatory
BONUS_DIR=ft_printf_bonus

SRC=$(wildcard $(SRC_DIR)/*.c)

BONUS_SRC=$(wildcard $(BONUS_DIR)/*.c)

OBJ=$(SRC:.c=.o)

BONUS_OBJ=$(BONUS_SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ) $(OBJ)
	@ar rc $(NAME) $(BONUS_OBJ) $(OBJ)
	ranlib $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus