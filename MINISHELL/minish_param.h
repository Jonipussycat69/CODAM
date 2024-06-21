#ifndef MINISH_PARAM_H
# define MINISH_PARAM_H
# include "libft/libft.h"
# include "minish_def.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <termios.h>

// Function parameters

// parsing.c

void	parsing_distributor(t_dad *d);

// utils_string.c

char	*strdup_index(char *str, size_t	start, size_t end);

// utils_exit.c

void	exit_clean(t_dad *d, int num, char *message);

// utils_freeing.c

void	ifnotnull_free_setnull(void **ptr);

#endif
