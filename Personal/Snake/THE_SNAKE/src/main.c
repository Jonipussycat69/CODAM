#include "../term_snake.h"

void	init(t_data *data)
{
	uint_fast32_t	rand = random();

	data->terminal_rows = get_terminal_rows();
	data->terminal_cols = get_terminal_cols();
	data->snake_len = STARTING_LEN;
	data->head_pos[0] = data->terminal_cols / 2;
	data->head_pos[1] = data->terminal_rows / 2;
	data->level = 0;
	data->score = 0;
	data->lives = STARTING_LIVES;
	data->dead = false;
	data->game_started = false;
	data->game_paused = false;
	data->exit_code = RUNNING;
	data->turns = NULL;
	pthread_mutex_init(&data->lock, NULL);
}

void	clean_up(t_data *data)
{
	free_list(&data->turns);
	pthread_mutex_destroy(&data->lock);
}

int	main(void)
{
	pthread_t	game_thread;
	pthread_t	input_thread;
	pthread_t	print_thread;
	t_data		data;

	srandom((unsigned int)get_time_us());
	init(&data);
	candy_pos_generate(&data);
	if (pthread_create(&game_thread, NULL, game, &data))
		return (clean_up(&data), EXIT_FAILURE);
	if (pthread_create(&input_thread, NULL, input_loop, &data))
		return (clean_up(&data), EXIT_FAILURE);
	if (pthread_create(&print_thread, NULL, print_loop, &data))
		return (clean_up(&data), EXIT_FAILURE);
	if (pthread_join(game_thread, NULL))
		return (clean_up(&data), EXIT_FAILURE);
	if (pthread_join(input_thread, NULL))
		return (clean_up(&data), EXIT_FAILURE);
	if (pthread_join(print_thread, NULL))
		return (clean_up(&data), EXIT_FAILURE);
	clean_up(&data);
	return (EXIT_SUCCESS);
}
