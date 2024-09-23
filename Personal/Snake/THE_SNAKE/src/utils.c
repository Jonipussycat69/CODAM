
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
	free_list(&data->snake);
	pthread_mutex_destroy(&data->data_lock);
	pthread_mutex_destroy(&data->input_lock);
}

void	error_exit(t_data *data, bool parent)
{
	pthread_mutex_lock(&data->data_lock);
	data->exit_code = FAIL;
	data->game_over = true;
	pthread_mutex_unlock(&data->data_lock);
	if (parent)
	{
		pthread_join(data->input_thread, NULL);
		clean_up(data);
	}
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

void	game_over_message(t_data *data)
{
	write(STDOUT_FILENO, "\033[2J", 4);
	write(STDOUT_FILENO, C_BOLD, strlen(C_BOLD));
	write(STDOUT_FILENO, C_RED, strlen(C_RED));
	write(STDOUT_FILENO, END_MESSAGE, strlen(END_MESSAGE));
	write(STDOUT_FILENO, C_RESET, strlen(C_RESET));
	printf("\n\nscore: %d\n\n", data->score);
}
