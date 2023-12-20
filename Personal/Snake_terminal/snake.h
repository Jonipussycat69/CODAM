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

# define INP_LEN 10
# define WINDOW_X 100
# define WINDOW_Y 50
# define MAX_LEN 20

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

enum	returns{error, next, end, re};

typedef struct s_basic
{
	int	iter;
	int	inp;
}	main_variables;

typedef struct s_screen
{
	int	pix_new[MAX_LEN][MAX_LEN];
	int	pix_old[MAX_LEN][MAX_LEN];
	int	change;
}	screen_changes;

int	snake_main(void);

#endif