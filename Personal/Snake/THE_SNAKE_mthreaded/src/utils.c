
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

uint_fast64_t	delta_time(__uint64_t prev_time_ms)
{
	return (get_time_us() - prev_time_ms);
}

void	clean_up(t_data *data)
{
	free_list(&data->snake);
	free(data->print_buffer);
	pthread_mutex_destroy(&data->input_lock);
	disableRawMode();
}

void	exit_clean(t_data *data, bool error, char *message)
{
	data->game_over = true;
	if (error)
	{
		usleep(10000);
		clean_up(data);
		perror(message);
		exit(EXIT_FAILURE);
	}
	else
	{
		usleep(10000);
		clean_up(data);
		game_over_message(data);
		exit(EXIT_SUCCESS);
	}
}

void	wait_for_unpause(t_data *data)
{
	char	input;

	pause_screen(data);
	pthread_mutex_lock(&data->input_lock);
	while (1)
	{
		read(STDIN_FILENO, &input, 1);
		if (input == 'q')
			exit_clean(data, false, NULL);
		if (input == 'p')
			break ;
	}
	pthread_mutex_unlock(&data->input_lock);
	usleep(100);
	pthread_mutex_lock(&data->input_lock);
	data->input = NON;
	pthread_mutex_unlock(&data->input_lock);
}

uint_fast64_t	get_random(uint_fast64_t seed, uint_fast64_t max)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((seed * tv.tv_usec + tv.tv_sec) % (max + 1));
}
