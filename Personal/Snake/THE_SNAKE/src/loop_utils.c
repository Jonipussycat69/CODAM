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
	uint_fast32_t	rand;

	while (candy_in_snake(data))
	{
		rand = random();
		data->candy_pos[0] = rand % data->cols;
		rand = random();
		data->candy_pos[1] = rand % data->rows;
	}
}

void	pause_game(t_data *data)
{
	pthread_mutex_lock(&data->data_lock);
	data->game_paused = true;
	pthread_mutex_unlock(&data->data_lock);
	while (data->input != SPACE)
		;
	data->game_paused = false;
}

void	esc_sequence(t_data *data)
{
	pthread_mutex_lock(&data->data_lock);
	data->exit_code = SUCC;
	pthread_mutex_unlock(&data->data_lock);
	exit(EXIT_SUCCESS);
}

char	get_pos_char(t_data *data, __uint16_t x, __uint16_t y)
{
	t_body	*temp;

	temp = data->snake;
	while (temp != NULL)
	{
		if (temp->pos[0] == x && temp->pos[1] == y)
			return ('@');
		temp = temp->next;
	}
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
	{
		perror("malloc_buffer");
		data->exit_code = FAIL;
		data->game_over = true;
		error_exit(data, false);
	}
	return (buffer);
}

char	*resize_image(t_data *data, char *buffer)
{
	free(buffer);
	buffer = malloc_buffer(data);
	data->resized = false;
	return (buffer);
}
