NAME = pipex.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTFDIR = /ft_printf
PRINTF =	$(PRINTFDIR)/ft_convert.c \
PRINTF =	$(PRINTFDIR)/ft_get_arg.c \
PRINTF =	$(PRINTFDIR)/ft_printer_funct.c \
PRINTF =	$(PRINTFDIR)/ft_printf_utils.c \
PRINTF =	$(PRINTFDIR)/ft_printf.c

SRCDIR = /src
SRCS =	$(SRCDIR)/main.c \
SRCS =	$(SRCDIR)/utils.c \
SRCS =	$(SRCDIR)/split.c \
SRCS =	$(SRCDIR)/pathfind.c \

OBJSSRC = $(SRCS:.c=.o)
OBJSPRINT = $(PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJSSRC) $(OBJSPRINT) -o $(NAME)

clean:
	rm -f $(OBJSSRC)
	rm -f $(OBJSPRINT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re