#include "../vdensity.h"

int	get_pos_arr_len(char *str)
{
	int	i = 0;
	int	len = 0;

	while (str[i])
	{
		if (isdigit(str[i]))
		{
			len++;
			while (isdigit(str[i]) || str[i] == '.')
				i++;
		}
		i++;
	}
	return (len - 3);
}

double	*init_pos_array(char *str, int arr_len)
{
	int			i = 0;
	int			j = 0;
	int			pos = 0;
	double		*pos_array = NULL;

	if (arr_len < 1)
		return (NULL);
	pos_array = (double *)malloc(sizeof(double) * arr_len);
	if (!pos_array)
		return (NULL);
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			j++;
			if (j > 2)
				pos_array[pos++] = atof(str + i);
			while (isdigit(str[i]) || str[i] == '.')
				i++;
		}
		i++;
	}
	return (pos_array);
}

double	*init_double_array(int arr_len)
{
	double		*double_array = NULL;

	if (arr_len < 1)
		return (NULL);
	double_array = (double *)malloc(sizeof(double) * arr_len);
	if (!double_array)
		return (NULL);
	return (double_array);
}
