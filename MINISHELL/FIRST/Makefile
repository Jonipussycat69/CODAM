NAME=		minishell

CC=			cc

CFLAGS=		-Wall -Wextra -Werror

# Adding platform-specific settings for macOS and Ubuntu
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)  # macOS
	INCLUDES=	-I /usr/local/opt/readline/include -I ./include
	LDFLAGS=	-L /usr/local/opt/readline/lib -lreadline
else ifeq ($(UNAME_S), Linux)  # Ubuntu
	INCLUDES=	-I /usr/include/readline -I ./include
	LDFLAGS=	-lreadline
endif

LFTDIR=		./libft
LIBFT=		$(LFTDIR)/libft.a

PRINTFDIR=	./ft_printf
PRINTF=		$(PRINTFDIR)/ft_convert.c \
			$(PRINTFDIR)/ft_get_arg.c \
			$(PRINTFDIR)/ft_printer_funct.c \
			$(PRINTFDIR)/ft_printf_utils.c \
			$(PRINTFDIR)/ft_printf.c

SRCDIR=		./src
SRCS=		$(SRCDIR)/main.c

OBJSSRC=	$(SRCS:.c=.o)
OBJSPRINT=	$(PRINTF:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LFTDIR) all

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(NAME): $(OBJSSRC) $(OBJSPRINT) $(LIBFT)
	$(CC) $(OBJSSRC) $(OBJSPRINT) $(LIBFT) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJSSRC)
	rm -f $(OBJSPRINT)
	make -C $(LFTDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(LFTDIR)/libft.a

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
