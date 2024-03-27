#include "push_swap.h"

size_t	ps_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

short	ps_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ps_strjoin(char *add, char *line, size_t i, size_t j)
{
	const size_t	l_len = ps_strlen(line);
	const size_t	a_len = ps_strlen(add);
	char			*new_line;
	char			*temp_line;

	if (a_len == 0)
		return (line);
	temp_line = line;
	new_line = (char *)malloc(l_len + a_len + 1);
	if (!new_line)
		return (free(line), NULL);
	while (i < l_len)
		new_line[i++] = *(temp_line++);
	while (j < a_len)
		new_line[i++] = add[j++];
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

void	wr_a(char *action)
{
	write(STDOUT_FILENO, action, ps_strlen(action));
	write(STDOUT_FILENO, "\n", 1);
	return ;
}
