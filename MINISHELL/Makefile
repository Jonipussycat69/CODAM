NAME=		minishell

CC=			cc -g -fsanitize=address

# CFLAGS=		-Wall -Wextra -Werror

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

# SRCDIR=		./test_env_src
# SRCS=		$(SRCDIR)/main.c

SRCDIR=		./src
SRCS=		$(SRCDIR)/main.c

OBJSSRC=	$(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LFTDIR) all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJSSRC) $(LIBFT)
	$(CC) $(OBJSSRC) $(LIBFT) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJSSRC)
	make -C $(LFTDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(LFTDIR)/libft.a

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
