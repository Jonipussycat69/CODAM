#include "../term_snake.h"

void	init_data(t_data *data)
{
	__uint16_t	rows;
	__uint16_t	cols;

	rows = get_terminal_rows() - 1;
	cols = get_terminal_cols();
	data->rows = rows;
	data->cols = cols;
	data->last_direction = LEFT;
	data->snake_len = STARTING_LEN;
	data->input = NON;
	data->level = 0;
	data->score = 0;
	data->lives = STARTING_LIVES;
	data->snake = NULL;
	data->game_over = false;
	data->print_buffer = NULL;
	pthread_mutex_init(&data->input_lock, NULL);
	data->candy_pos[0] = cols / 4;
	data->candy_pos[1] = rows / 2;
}
