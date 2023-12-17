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
#include <sys/ioctl.h>

# define INP_LEN 10
# define PARAMB 7

# define BLUE_F "\033[1;34m"
# define WHITE_F "\033[1;37m"
# define DIMMED_F "\033[2;37m"
# define RESET_F "\033[0m"
# define BLUE_DIM_F "\033[2;34m"

enum	state{dead, alive};
enum	board{empty, W, B};
enum	retvalues{error, next, end, exit_program, redo, reinp};
enum	checktype{set, move, jumpmove};
enum	colours{black, red, green, yellow, blue, purple, cyan, white, reset_colour};
enum	txtformat{standard_form, bold, cursive};

typedef struct s_man
{
	int	x;
	int	y;
	bool	colour;
	bool	state;
}	man;

typedef struct s_men
{
	man	B1;
	man	B2;
	man	B3;
	man	B4;
	man	B5;
	man	B6;
	man	B7;
	man	B8;
	man	B9;
	man	W1;
	man	W2;
	man	W3;
	man	W4;
	man	W5;
	man	W6;
	man	W7;
	man	W8;
	man	W9;
}	men;

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

int	rule_check(int type, inpt *inp);
int	inp_check(char *input, inpt *inp, int type);
int	coordinate_check(int type, inpt *inp);

void	stop_game(int type);

void	print_width_format(char *c, char *f);

#endif