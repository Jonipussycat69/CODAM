#include "../term_snake.h"

void	*input_loop(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		data->last_inp = getch();
		if (data->last_inp == QUIT_KEY)
			break ;
	}
	return (NULL);
}

uint_fast32_t	delta_time(__uint64_t prev_time_ms)
{
	return (get_time_us() - prev_time_ms);
}

void	*print_loop(void *arg)
{
	t_data		*data;
	__uint64_t	prev_time_ms;

	data = (t_data *)arg;
	while (1)
	{
		prev_time_ms = get_time_us();
		// LEFTOFF, PRINTING HERE!
		while (delta_time(prev_time_ms) < 10000)
			prev_time_ms = get_time_us();
	}
	return (EXIT_SUCCESS);
}
