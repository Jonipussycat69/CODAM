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
