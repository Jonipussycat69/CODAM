#include "../term_snake.h"

void	*input_loop(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	wait_for_start(data);
	while (1)
	{
		pthread_mutex_lock(&data->input_lock);
		data->input = getch();
		pthread_mutex_unlock(&data->input_lock);
		while (!data->tick)
			;
	}
	return (NULL);
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
		pthread_mutex_lock(&data->data_lock);
		data->exit_code = FAIL;
		pthread_mutex_unlock(&data->data_lock);
		error_exit(data, false);
	}
	return (buffer);
}

void	view_data(t_data *data)
{
	while (data->game_paused && data->exit_code == RUNNING)
		;
	pthread_mutex_lock(&data->data_lock);
	if (data->exit_code != RUNNING)
	{
		pthread_mutex_unlock(&data->data_lock);
		error_exit(data, false);
	}
	// LEFTOFF! should i combine thread game and thread print?
	pthread_mutex_unlock(&data->data_lock);
}

void	*print_loop(void *arg)
{
	t_data		*data;
	char		*buffer;
	__uint16_t	len;

	data = (t_data *)arg;
	wait_for_start(data);
	while (1)
	{
		view_data(data);
		pthread_mutex_lock(&data->write_lock);
		buffer = malloc_buffer(data);
		image_to_buffer(data, buffer);
		pthread_mutex_unlock(&data->write_lock);
		len = strlen(buffer);
		while (!data->tick)
			;
		write(STDOUT_FILENO, "\033[2J", 4);
		write(STDOUT_FILENO, buffer, len);
		free(buffer);
	}
	return (NULL);
}
