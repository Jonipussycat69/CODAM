NAME		=	terminal_snake

CC			=	cc

# CFLAGS		=	-Wall -Werror -Wextra

LIBS		=	-lncurses

FSANITIZE	=	-g -fsanitize=address

SRCDIR		=	./src
SRC			=	$(SRCDIR)/main.c \
				$(SRCDIR)/list.c \
				$(SRCDIR)/utils.c \
				$(SRCDIR)/input_loop.c \
				$(SRCDIR)/game_loop.c \
				$(SRCDIR)/loop_utils.c \
				$(SRCDIR)/game_utils.c \
				$(SRCDIR)/init.c \
				$(SRCDIR)/termios.c \
				$(SRCDIR)/game_print.c

OBJS		=	${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FSANITIZE) $(OBJS) -o $(NAME) $(LIBS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re