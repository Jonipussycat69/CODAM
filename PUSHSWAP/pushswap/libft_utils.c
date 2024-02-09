#include "push_swap.h"

size_t	ps_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
