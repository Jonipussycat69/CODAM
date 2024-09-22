
#include "../term_snake.h"

__uint16_t	get_terminal_rows(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_row);
}

__uint16_t	get_terminal_cols(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

__uint64_t	get_time_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (__uint64_t)1000000) + (tv.tv_usec));
}

uint_fast32_t	delta_time(__uint64_t prev_time_ms)
{
	return (get_time_us() - prev_time_ms);
}

void	clean_up(t_data *data)
{
	free_list(&data->turns);
	pthread_mutex_destroy(&data->data_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->input_lock);
	pthread_mutex_destroy(&data->candy_lock);
}

void	error_exit(t_data *data, bool clean)
{
	pthread_mutex_lock(&data->data_lock);
	data->exit_code = FAIL;
	pthread_mutex_unlock(&data->data_lock);
	if (clean)
		clean_up(data);
	exit(EXIT_FAILURE);
}

void	wait_for_start(t_data *data)
{
	while (!data->game_started)
	{
		if (data->exit_code != RUNNING)
			error_exit(data, false);
	}
}
