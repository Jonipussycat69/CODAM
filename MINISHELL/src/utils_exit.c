#include "../minish_param.h"

// Frees main stings, linkedlists and exits.
void	exit_clean(t_dad *d, int num, char *message)
{
	//cleanup
	free(d->line);
	free(d->prev_line);
	rl_clear_history();
	errno = num;
	if (num != EXIT_SUCCESS)
		perror(message);
	exit(num);
}
