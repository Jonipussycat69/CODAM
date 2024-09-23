#include "../term_snake.h"

void	add_body(t_data *data)
{
	t_body	new_b;

	new_b.pos[0] = data->new_body_pos[0];
	new_b.pos[1] = data->new_body_pos[1];
	new_b.head = false;
	new_b.next = NULL;
	body_add_back(&data->snake, &new_b);
}

void	check_candy(t_data *data)
{
	if (data->candy_pos[0] == data->snake->pos[0] 
		&& data->candy_pos[1] == data->snake->pos[1])
	{
		data->score++;
		data->snake_len++;
		add_body(data);
		candy_pos_generate(data);
	}
}

void	input_to_move(t_data *data)
{
	pthread_mutex_lock(&data->input_lock);
	switch (data->input)
	{
		case UP:
			;
		case DOWN:
			;
		case LEFT:
			;
		case RIGHT:
			;
		case SPACE:
			pause_game(data);
			break ;
		case ESC:
			esc_sequence(data);
		default:
			break ;
	}
	pthread_mutex_unlock(&data->input_lock);
}

char	*update_game(t_data *data, char *buffer)
{
	pthread_mutex_lock(&data->data_lock);
	if (data->resized)
		buffer = resize_image(data, buffer);
	input_to_move(data);
	check_candy(data);
	image_to_buffer(data, buffer);
	pthread_mutex_unlock(&data->data_lock);
	return (buffer);
}

void	game_loop(t_data *data)
{
	char		*buffer;
	__uint16_t	len;
	__uint64_t	prev_time_us;

	data->game_started = true;
	prev_time_us = get_time_us();
	buffer = malloc_buffer(data);
	while (1)
	{
		while (data->game_paused && data->exit_code == RUNNING)
			;
		if (data->exit_code != RUNNING)
			error_exit(data, false);
		buffer = update_game(data, buffer);
		len = strlen(buffer);
		while (!data->tick || delta_time(prev_time_us) < FRAMETIME)
			prev_time_us = get_time_us();
		data->tick = true;
		write(STDOUT_FILENO, "\033[2J", 4);
		write(STDOUT_FILENO, buffer, len);
	}
}
