#ifndef MALOM_H
# define MALOM_H

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

typedef struct s_man
{
	int	x;
	int	y;
	int	x_alpha;
	int	code;
	int	colour;
	int	state;
	int	update;
}	mann;

typedef struct s_men
{
	mann	B1;
	mann	B2;
	mann	B3;
	mann	B4;
	mann	B5;
	mann	B6;
	mann	B7;
	mann	B8;
	mann	B9;
	mann	W1;
	mann	W2;
	mann	W3;
	mann	W4;
	mann	W5;
	mann	W6;
	mann	W7;
	mann	W8;
	mann	W9;
}	menn;

typedef struct s_inp
{
	char	X_cur_alpf;
	char	X_new_alpf;
	int	X_cur;
	int	Y_cur;
	int	X_new;
	int	Y_new;
}	inpt;

int		malom(void);
void	reset_board(void);
void	print_format(int col, int type);
void	ft_bzero(void *s, size_t n);
int		terminate_c(char *str, int c);

int	rule_check(int turn, int type, inpt *inp);
int	inp_check(char *input, inpt *inp, int type, int turn);
int	coordinate_check(int type, inpt *inp);

void	stop_game(int type);

void	print_width_format(char *c, char *f);

#endif