NAME=libftprintf.a

CFLAGS=-Wall -Werror -Wextra

RM=rm -f

SRC=ft_printf.c ft_convert.c ft_printf_utils.c ft_get_arg.c ft_printer_funct.c

BONUS_SRC=ft_printf_bonus.c ft_printf_utils_bonus.c ft_b_printer_funct.c \
ft_b_get_flags.c ft_b_get_arg.c ft_b_flag_print.c ft_b_f_print_utils.c \
ft_b_convert.c ft_b_precision.c

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