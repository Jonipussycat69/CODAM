#ifndef SNAKE_H
# define SNAKE_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <ctype.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include <sys/ioctl.h>
# include <fcntl.h>

# define STARTING_LEN 3
# define MAX_LEN 20
# define OFFSET 4

# define BLUE_F "\033[1;34m"
# define WHITE_F "\033[1;37m"
# define DIMMED_F "\033[2;37m"
# define DIMMED_BOLD_F "\033[1;2;37m"
# define RESET_F "\033[0m"
# define BLUE_DIM_F "\033[2;34m"
# define BLUE_BOLD_DIM_F "\033[1;2;34m"
# define BLUE_BOLD_F "\033[1;34m"
# define RED_DIM_F "\033[2;31m"
# define GREEN_F "\033[32m"
# define GREEN_DIM_F "\033[2;32m"
# define CYAN_DIM_F "\033[2;36m"

enum	returns{error, next, quit, re};

typedef struct s_basic
{
	unsigned long long	iter;
	int					last_inp;
}	main_variables;

typedef struct s_screen
{
	int	candy[2];
	int	pix_new[2][MAX_LEN];
	int	pix_old[2][MAX_LEN];
	int	snake_len;
	int	direction[3][MAX_LEN];
	int	terminal_height;
	int	terminal_width;
}	screen_prop;

int	snake_main(void);

#endif