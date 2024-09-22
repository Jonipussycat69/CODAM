#include "../term_snake.h"

void	candy_pos_generate(t_data *data)
{
	uint_fast32_t	rand;

	rand = random();
	data->candy_pos[0] = rand % data->cols;
	rand = random();
	data->candy_pos[1] = rand % data->rows;
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

void	check_candy(t_data *data)
{
	pthread_mutex_lock(&data->candy_lock);
	candy_pos_generate(data);
	pthread_mutex_unlock(&data->candy_lock);
}

void	*game(void *arg)
{
	t_data		*data;
	__uint64_t	prev_time_us;

	data = (t_data *)arg;
	wait_for_start(data);
	prev_time_us = get_time_us();
	while (1)
	{
		input_to_move(data);
		check_candy(data);
		while (delta_time(prev_time_us) < FRAMETIME)
			prev_time_us = get_time_us();
		data->tick = true;
		usleep(2);
		data->tick = false;
	}
	return (NULL);
}
