#include "push_swap.h"

void	write_action(char type, char stack)
{
	char	stack_van_drie_die_moet_van_simon_en_remy[3];

	stack_van_drie_die_moet_van_simon_en_remy[0] = type;
	stack_van_drie_die_moet_van_simon_en_remy[1] = stack;
	stack_van_drie_die_moet_van_simon_en_remy[2] = '\n';
	write(STDOUT_FILENO, &stack_van_drie_die_moet_van_simon_en_remy, 3);
	return ;
}