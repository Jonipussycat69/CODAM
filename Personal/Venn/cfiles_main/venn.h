#ifndef VENN_H
# define VENN_H

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
#include <sys/ioctl.h>

# define INP_LEN 10
# define PARAMB 7

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

enum	state{dead, alive, inactive, moved};
enum	board{empty, W, B};
enum	retvalues{error, next, end, exit_program, redo, reinp};
enum	checktype{set, move, jumpmove};
enum	colours{black, red, green, yellow, blue, purple, cyan, white, reset_colour};
enum	txtformat{standard_form, bold, cursive};


#endif