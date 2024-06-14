NAME=pipex

CC=cc

ASAN=-g -fsanitize=address #TEST

CFLAGS= -g -Wall -Wextra -Werror 

HEADERS=-I ./include

PRINTFDIR=./ft_printf
PRINTF=	$(PRINTFDIR)/ft_convert.c \
		$(PRINTFDIR)/ft_get_arg.c \
		$(PRINTFDIR)/ft_printer_funct.c \
		$(PRINTFDIR)/ft_printf_utils.c \
		$(PRINTFDIR)/ft_printf.c

SRCDIR=./src
SRCS=	$(SRCDIR)/pipex_main.c \
		$(SRCDIR)/pipex_utils.c \
		$(SRCDIR)/libft_utils.c \
		$(SRCDIR)/libft_split.c \
		$(SRCDIR)/pipex_pathfind.c

OBJSSRC=$(SRCS:.c=.o)
OBJSPRINT=$(PRINTF:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJSSRC) $(OBJSPRINT)
	$(CC) $(ASAN) $(OBJSSRC) $(OBJSPRINT) -o $(NAME) $(HEADERS)

clean:
	rm -f $(OBJSSRC)
	rm -f $(OBJSPRINT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
