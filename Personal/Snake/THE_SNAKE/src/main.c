#include "../term_snake.h"

void	init_data(t_data *data)
{
	uint_fast32_t	rand = random();

	data->rows = get_terminal_rows();
	data->cols = get_terminal_cols();
	data->snake_len = STARTING_LEN;
	data->head_pos[0] = data->cols / 2;
	data->head_pos[1] = data->rows / 2;
	data->level = 0;
	data->score = 0;
	data->lives = STARTING_LIVES;
	data->dead = false;
	data->game_started = false;
	data->game_paused = false;
	data->exit_code = RUNNING;
	data->turns = NULL;
	data->tick = false;
	data->thread_ret[0] = RUNNING;
	data->thread_ret[1] = RUNNING;
	data->thread_ret[2] = RUNNING;
	pthread_mutex_init(&data->data_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->input_lock, NULL);
	pthread_mutex_init(&data->candy_lock, NULL);
	candy_pos_generate(data);
}

bool	create_threads(
	t_data *data, pthread_t *game_thread, pthread_t *input_thread, pthread_t *print_thread)
{
	if (pthread_create(game_thread, NULL, game, data))
		return (perror("pthread_create(game_thread)"), FAIL);
	if (pthread_create(input_thread, NULL, input_loop, data))
		return (perror("pthread_create(input_thread)"), FAIL);
	if (pthread_create(print_thread, NULL, print_loop, data))
		return (perror("pthread_create(print_thread)"), FAIL);
	pthread_detach(*game_thread);
	pthread_detach(*input_thread);
	pthread_detach(*print_thread);
	return (SUCC);
}

int	main(void)
{
	pthread_t	game_thread;
	pthread_t	input_thread;
	pthread_t	print_thread;
	t_data		data;

	srandom((unsigned int)get_time_us());
	init_data(&data);
	candy_pos_generate(&data);
	if (create_threads(&data, &game_thread, &input_thread, &print_thread))
		error_exit(&data, true);
	monitor(&data);
	clean_up(&data);
	return (data.exit_code);
}
