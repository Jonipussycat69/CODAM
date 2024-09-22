NAME		=	terminal_snake

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra

FSANITIZE	=	-g -fsanitize=address

SRCDIR		=	./src
SRC			=	$(SRCDIR)/action.c \
				$(SRCDIR)/main.c \
				$(SRCDIR)/utils.c

OBJS		=	${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FSANITIZE) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re