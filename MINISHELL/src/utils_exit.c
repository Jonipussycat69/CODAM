#include "../minish_param.h"

// Frees main stings, linkedlists and exits.
void	exit_clean(t_dad *d, int num, char *message)
{
	//core cleanup
	free(d->line);
	free(d->prev_line);
	rl_clear_history();
	errno = num;
	if (num != EXIT_SUCCESS)
		perror(message);
	exit(num);
}

// (EXPERIMENTAL)
// Exits the program with exit_clean() after freeing variable amount of pointers
void	exit_va_free(t_dad *d, int num, char *message, short amount, ...)
{
	va_list	ptrs_to_free;
	int		i;

	va_start(ptrs_to_free, amount);
	i = 0;
	while (i < amount)
	{
		free(va_arg(ptrs_to_free, void *));
		++i;
	}
	va_end(ptrs_to_free);
	exit_clean(d, num, message);
}
