#include "push_swap.h"

short	swap(t_list **head, char stack)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return (1);
	tmp = *head;
	tmptmp = tmp->next;
	tmp->next = tmptmp->next;
	tmptmp->next = tmp;
	write(1, "s", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	return (0);
}

short	push(t_list **head_a, t_list **head_b, char stack)
{
	t_list	*tmp;

	if (!*head_a || !*head_b)
		return (1);
	if (stack == 'a')
	{
		tmp = *head_a;
		*head_a = *head_b;
		*head_b = tmp;
	}
	return (0);
}