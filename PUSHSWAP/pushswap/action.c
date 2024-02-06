#include "push_swap.h"

// Swap, first and second elemnt swapped.
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
	write_action('s', stack);
	return (0);
}

// Push, first element of other stack pushed to chosen stack.
short	push(t_list **head_a, t_list **head_b, char stack)
{
	t_list	*tmp;

	if (!*head_a || !*head_b)
		return (1);
	if (stack == 'a')
	{
		tmp = *head_b;
		*head_b = tmp->next;
		tmp->next = *head_a;
		*head_a = tmp;
		write_action('p', stack);
	}
	else if (stack == 'b')
	{
		tmp = *head_a;
		*head_a = tmp->next;
		tmp->next = *head_b;
		*head_b = tmp;
		write_action('p', stack);
	}
	return (0);
}

// Rotate, firts becomes last.
short	rotate(t_list **head, char stack)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return (1);
	if (list_len(head) == 2)
		return (swap(head, stack));
	tmp = *head;
	*head = tmp->next;
	tmp->next = NULL;
	tmptmp = last_node(head);
	tmptmp->next = tmp;
	write_action('r', stack);
	return (0);
}

// Reverse rotate, last becomes first.
short	r_rotate(t_list **head, char stack)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return (1);
	if (list_len(head) == 2)
		return (swap(head, stack));
	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmptmp = tmp->next;
	tmptmp->next = *head;
	tmp->next = NULL;
	*head = tmptmp;
	write_action('rr', stack);
	return (0);
}
