NAME		=	push_swap
CFLAGS		=	-Wall -Werror -Wextra

SRCDIR		=	./src
SRC			=	$(SRCDIR)/action.c\
				$(SRCDIR)/inp_handling.c\
				$(SRCDIR)/list_action_double.c\
				$(SRCDIR)/list_action.c\
				$(SRCDIR)/list_manipulate.c\
				$(SRCDIR)/main.c\
				$(SRCDIR)/path_act.c\
				$(SRCDIR)/sorting.c\
				$(SRCDIR)/utils_extend.c\
				$(SRCDIR)/utils_sort.c\
				$(SRCDIR)/utils.c\

OBJS		=	${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re