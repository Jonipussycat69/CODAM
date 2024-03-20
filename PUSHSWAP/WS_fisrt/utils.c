#include "push_swap.h"

void	wr_a(char *action)
{
	write(STDOUT_FILENO, action, ps_strlen(action));
	write(STDOUT_FILENO, "\n", 1);
	return ;
}

t_list	*find_annom(t_list **head)
{
	t_list	*tmp;
	int		prev_index;
	
	if (!*head)
		return (NULL);
	tmp = *head;
	while (tmp != NULL)
	{
		prev_index = tmp->i_value;
		tmp = tmp->next;
		if (tmp->i_value < prev_index)
			return (tmp);
	}
	return (NULL);
}

int	list_len(t_list **head)
{
	t_list	*tmp;
	int		i;
	
	if (!*head)
		return (0);
	i = 0;
	tmp = *head;
	while (tmp != NULL && ++i)
		tmp = tmp->next;
	return (i);
}
