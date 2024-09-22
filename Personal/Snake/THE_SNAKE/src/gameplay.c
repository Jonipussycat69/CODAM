#include "../term_snake.h"

void	candy_pos_generate(t_data *data)
{
	uint_fast32_t	rand;

	rand = random();
	data->candy_pos[0] = rand % data->terminal_cols;
	rand = random();
	data->candy_pos[1] = rand % data->terminal_rows;
}

void	*game(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	return (NULL);
}
