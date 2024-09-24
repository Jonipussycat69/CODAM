#include "../term_snake.h"

bool	candy_in_snake(t_data *data)
{
	t_body	*temp;

	temp = data->snake;
	while (temp != NULL)
	{
		if (temp->pos[0] == data->candy_pos[0]
			&& temp->pos[1] == data->candy_pos[1])
			return (true);
		temp = temp->next;
	}
	return (false);
}

void	candy_pos_generate(t_data *data)
{
	while (data->candy_pos[0] < 1 || data->candy_pos[1] < 1 || candy_in_snake(data))
	{
		data->candy_pos[0] = get_random(data->candy_pos[0], data->cols - 1);
		data->candy_pos[1] = get_random(data->candy_pos[1], data->rows - 1);
	}
}

char	get_pos_char(t_data *data, __uint16_t x, __uint16_t y)
{
	t_body	*temp;

	temp = data->snake;
	while (temp != NULL)
	{
		if (temp->pos[0] == x && temp->pos[1] == y)
			return (temp->head ? 'o' : '@');
		temp = temp->next;
	}
	if (x == data->candy_pos[0] && y == data->candy_pos[1])
		return ('+');
	return (' ');
}

char	*malloc_buffer(t_data *data)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (data->cols + 1));
	if (buffer == NULL)
		exit_clean(data, true, "malloc_buffer");
	return (buffer);
}
