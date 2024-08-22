#include "../vdensity.h"

bool	parse_input(t_data *data, char *str)
{
	int			i = 0;

	data->pos_arr_len = get_pos_arr_len(str);
	if (data->pos_arr_len < 1)
		return (false);
	data->pos_arr = init_pos_array(str, data->pos_arr_len);
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
	if (data->iterations < 2)
		data->iterations = 2;
}
