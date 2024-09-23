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
	while (candy_in_snake(data))
	{
		data->candy_pos[0] = get_random(data->candy_pos[0], data->cols);
		data->candy_pos[1] = get_random(data->candy_pos[1], data->rows);
	}
}

char	get_pos_char(t_data *data, __uint16_t x, __uint16_t y)
{
	t_body	*temp;

	temp = data->snake;
	while (temp != NULL)
	{
		if (temp->pos[0] == x && temp->pos[1] == y)
		{
			switch (temp->head)
			{
				case true: return ('o');
				case false: return ('@');
			}
		}
		temp = temp->next;
	}
	if (x == data->candy_pos[0] && y == data->candy_pos[1])
		return ('+');
	return (' ');
}

void	image_to_buffer(t_data *data, char *buffer)
{
	uint_fast16_t	x;
	uint_fast16_t	y;
	uint_fast16_t	i;

	y = 0;
	i = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			buffer[i++] = get_pos_char(data, x, y);
			++x;
		}
		if (y < data->rows - 1)
			buffer[i++] = '\n';
		++y;
	}
	buffer[i] = '\0';
}

char	*malloc_buffer(t_data *data)
{
	char	*buffer;

	buffer = (char *)malloc(data->rows * (data->cols + 1));
	if (buffer == NULL)
		exit_clean(data, true, "malloc_buffer");
	return (buffer);
}
