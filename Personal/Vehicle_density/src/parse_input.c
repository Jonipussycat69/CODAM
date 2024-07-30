#include "../vdensity.h"

bool	parse_input(t_data *data, char *str)
{
	const int	arr_len = get_arr_len(str);
	int			i = 0;

	if (arr_len < 1)
		return (false);
	data->pos_arr = init_pos_array(str, arr_len);
	if (!data->pos_arr)
		return (false);
	while (str[i] && !isdigit(str[i]))
		i++;
	if (str[i])
		data->target_pos = atof(str + i);
	while (isdigit(str[i]) || str[i] == '.')
		i++;
	while (str[i] && !isdigit(str[i]))
		i++;
	if (str[i])
		data->iterations = atoi(str + i);
}
