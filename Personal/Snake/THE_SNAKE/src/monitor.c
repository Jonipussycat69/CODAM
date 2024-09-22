#include "../term_snake.h"

void	game_over_message(t_data *data)
{
	write(STDOUT_FILENO, "\033[2J", 4);
	write(STDOUT_FILENO, C_BOLD, strlen(C_BOLD));
	write(STDOUT_FILENO, C_RED, strlen(C_RED));
	write(STDOUT_FILENO, END_MESSAGE, strlen(END_MESSAGE));
	write(STDOUT_FILENO, C_RESET, strlen(C_RESET));
}

void	monitor(t_data *data)
{
	return (SUCC);
}
