
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
	pthread_join(data->input_thread, NULL);
	clean_up(data);
	if (error)
	{
		perror(message);
		exit(EXIT_FAILURE);
	}
	else
	{
		game_over_message(data);
		exit(EXIT_SUCCESS);
	}
}

void	wait_for_unpause(t_data *data)
{
	clear_screen();
	printf("PRESS SPACE TO CONTINUE\n");
	while (data->input != PAUSE)
	{
		if (data->input == QUIT)
			exit_clean(data, false, NULL);
	}
}

void	game_over_message(t_data *data)
{
	clear_screen();
	write(STDOUT_FILENO, C_BOLD, strlen(C_BOLD));
	write(STDOUT_FILENO, C_RED, strlen(C_RED));
	write(STDOUT_FILENO, END_MESSAGE, strlen(END_MESSAGE));
	write(STDOUT_FILENO, C_RESET, strlen(C_RESET));
	printf("\n\nscore: %d\n\n", data->score);
}

void	clear_screen(void)
{
	write(STDOUT_FILENO, "\033[2J", 4);
	write(STDOUT_FILENO, "\033[H", 3);
}

uint_fast64_t	get_random(uint_fast64_t seed, uint_fast64_t max)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((seed * tv.tv_usec + tv.tv_sec) % (max + 1));
}
