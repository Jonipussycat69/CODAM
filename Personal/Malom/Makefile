NAME=MalomExe

MAIN_DIR=cfiles_main

PARSE_DIR=cfiles_parse

CFLAGS=-Wall -Werror -Wextra

RM=rm -f

SRC=$(wildcard $(MAIN_DIR)/*.c)

OBJ=$(SRC:.c=.o)

all: $(NAME)

#%.o: %.c
#	cc $(CFLAGS) -c $< -o $@

%.o: %.c
	@cc -c $< -o $@

$(NAME): fclean $(OBJ)
	@cc -o $(NAME) $(OBJ)
	@$(RM) $(OBJ)
	@./$(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re