#include "../term_snake.h"

void	init_data(t_data *data)
{
	data->rows = get_terminal_rows();
	data->cols = get_terminal_cols();
	data->snake_len = STARTING_LEN;
	data->level = 0;
	data->score = 0;
	data->lives = STARTING_LIVES;
	data->dead = false;
	data->game_started = false;
	data->game_paused = false;
	data->game_over = false;
	data->resized = false;
	data->exit_code = RUNNING;
	data->snake = NULL;
	data->tick = false;
	pthread_mutex_init(&data->input_lock, NULL);
	pthread_mutex_init(&data->data_lock, NULL);
	candy_pos_generate(data);
}

void	create_snake(t_data *data)
{
	short	i;
	t_body	node;

	i = 0;
	node.pos[0] = data->cols / 2;
	node.pos[1] = data->rows / 2;
	node.head = true;
	node.next = NULL;
	data->snake = new_body(&node);
	if (data->snake == NULL)
		error_exit(data, true);
	node.head = false;
	while (i < STARTING_LEN)
	{
		node.pos[0] = (data->cols / 2 + 1) + i;
		if (body_add_back(&data->snake, &node))
			error_exit(data, true);
		i++;
	}
}

int	main(void)
{
	t_data	data;

	srandom((unsigned int)get_time_us());
	init_data(&data);
	if (pthread_create(&data.input_thread, NULL, input_loop, &data))
		return (perror("pthread_create(input_thread)"), FAIL);
	create_snake(&data);
	candy_pos_generate(&data);
	game_loop(&data);
	clean_up(&data);
	return (data.exit_code);
}
