#include "../vdensity.h"

// ascii to float (or double)
double	ft_atof(char *arg)
{
	double	num;
	int		i;
	int		mult;
	int		c;

	num = 0;
	mult = min_check(arg[0], &i);
	while (arg[i] && ft_isdigit(arg[i]))
	{
		num = num * 10 + (arg[i] - '0');
		i++;
	}
	c = i;
	if (arg[i] != '.')
		return (num * mult);
	i++;
	while (arg[i] && ft_isdigit(arg[i]))
	{
		num += (double)(arg[i] - '0') / pow(10, (double)(i - c));
		i++;
	}
	return (num * mult);
}

void	print_results(t_data *data, int loop_count)
{
	int	i = 0;

	printf("<RESULT %i>\n", loop_count);
	printf("Input positions:\n");
	while (i < data->pos_arr_len)
	{
		printf(" [%i] %f\n", i, data->pos_arr[i]);
		i++;
	}
	i = 0;
	printf("\nDensity results:\n");
	while (i < data->iterations)
	{
		printf(" [%i] %f\n", i, data->dens_arr[i]);
		i++;
	}
	printf("\nCompiled density: %f\n\n", data->dens_result);
}

unsigned short	get_terminal_rows(void)
{
	struct	winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_row);
}

unsigned short	get_terminal_cols(void)
{
	struct	winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}
