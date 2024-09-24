#include "../term_snake.h"

void	clear_screen(void)
{
	write(STDOUT_FILENO, "\033[2J", 4);
	write(STDOUT_FILENO, "\033[H", 3);
}

void	print_buffered_image(t_data *data, char *buffer)
{
	uint_fast16_t	x;
	uint_fast16_t	y;
	uint_fast16_t	i;

	y = 0;
	i = 0;
	while (y < data->rows)
	{
		x = 0;
		i = 0;
		while (x < data->cols)
		{
			buffer[i++] = get_pos_char(data, x, y);
			++x;
		}
		write(STDOUT_FILENO, buffer, data->cols);
		++y;
	}
}

void	print_to_terminal(t_data *data, char *buffer)
{
	uint_fast16_t	i;

	clear_screen();
	if (data->cols > 40)
	printf("\033[1;35m TERM~SNAKE %sw[%lu] h[%lu]  speed: %.2lfx length: %d  score: %u  \"P\" to pause\n", \
			C_RESET, data->cols, data->rows, (double)(TICK_TIME_US) / (double)(data->tick_time_us), data->snake_len, data->score);
	fflush(stdout);
	i = 0;
	while (i < data->cols)
		buffer[i++] = '_';
	write(STDOUT_FILENO, buffer, data->cols);
	print_buffered_image(data, buffer);
}

void	write_mid(t_data *data, char *message)
{
	uint_fast16_t	i;

	i = data->cols / 2 - strlen(message) / 2;
	while (i--)
		write(STDOUT_FILENO, " ", 1);
	printf("%s", message);
	fflush(stdout);
}

void	write_newline(uint_fast16_t amount)
{
	while (amount--)
		write(STDOUT_FILENO, "\n", 1);
}

void	game_over_message(t_data *data)
{
	clear_screen();
	write_newline(3);
	printf("\033[1;35m");
	fflush(stdout);
	if (data->cols < 20)
	{
		write_mid(data, "TERM~SNAKE");
		write_newline(2);
		printf("\033[1;31m");
		fflush(stdout);
		write_mid(data, "GAME OVER");
		printf("\033[0m");
		fflush(stdout);
		write_newline(data->rows - 5);
		return ;
	}
	write_mid(data, "TERM~SNAKE");
	write_newline(2);
	printf("\033[1;31m");
	fflush(stdout);
	write_mid(data, "~ GAME OVER ~");
	printf("\033[0m");
	fflush(stdout);
	write_newline(2);
	write_mid(data, "score: ");
	printf("%d", data->score);
	fflush(stdout);
	write_newline(1);
	write_mid(data, "length: ");
	printf("%d", data->snake_len);
	fflush(stdout);
	write_newline(data->rows - 6);
}

void	pause_screen(t_data *data)
{
	clear_screen();
	if (data->cols < 20)
		return (write_newline(3), write_mid(data, "TERM~SNAKE"), \
				write_newline(data->rows - 3));
	write_newline(3);
	printf("\033[1;31m");
	fflush(stdout);
	write_mid(data, "TERM~SNAKE");
	printf("\033[0m");
	fflush(stdout);
	write_newline(3);
	write_mid(data, "PRESS \"P\" TO CONTINUE");
	write_newline(2);
	write_mid(data, "PRESS \"Q\" TO EXIT");
	write_newline(2);
	write_mid(data, "score: ");
	printf("%d", data->score);
	fflush(stdout);
	// write_newline(1);
	// write_mid(data, "lives: ");
	// printf("%d", data->lives);
	// fflush(stdout);
	write_newline(1);
	write_mid(data, "length: ");
	printf("%d", data->snake_len);
	fflush(stdout);
	write_newline(data->rows - 10);
}
