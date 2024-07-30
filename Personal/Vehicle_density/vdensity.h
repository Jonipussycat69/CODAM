#ifndef VDENSITY_H
# define VDENSITY_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <termios.h>
# include <math.h>
# include <time.h>

# define INPUT_LIMIT 256

// STRUCTS

typedef struct s_data
{
	double	target_pos;
	double	*pos_arr;
	int		iterations;
}	t_data;

// FUNCTION PARAMETERS

// parse_input.c

bool	parse_input(t_data *data, char *str);

// array_utils.c

int		get_arr_len(char *str);
double	*init_pos_array(char *str, int arr_len);

// utils.c

double	ft_atof(char *arg);

// math.c

double	calc_density(double *pos_array, double x);

#endif