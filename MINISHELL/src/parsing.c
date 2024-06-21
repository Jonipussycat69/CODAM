#include "../minish_param.h"

// PARSING:

void	check_for_exit(t_dad *d)
{
	if (!ft_strncmp(d->line, "exit", 5))
		exit_clean(d, EXIT_SUCCESS, NULL);
}

void	parsing_distributor(t_dad *d)
{
	check_for_exit(d);
	
}
// Jonatan is heel aardig = hij is eigenlijk een sukkel
// Simon is ook heel aardig = call me 0681296759