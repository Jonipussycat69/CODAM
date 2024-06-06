NAME=push_swap

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= *.c

# SRC=	main.c\
# 		action.c\
# 		inp_handling.c\
# 		list_action_double.c\
# 		list_action.c\
# 		list_manipulate.c\
# 		path_act.c\
# 		sorting.c\
# 		utils_extend.c\
# 		utils_sort.c\
# 		utils.c

# OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	cc $(CFLAGS) -o $(NAME) $(SRC)

# %.o: %.c
# 	cc $(CFLAGS) -c $< -o $@

# $(NAME): $(OBJ)
# 	@ar rc $(NAME) $(OBJ)
# 	ranlib $(NAME)

clean:
	@$(RM)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re