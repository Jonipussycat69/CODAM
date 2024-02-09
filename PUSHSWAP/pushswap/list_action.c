#include "push_swap.h"

// Swap, first and second elemnt swapped.
short	swap(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return (err);
	tmp = *head;
	tmptmp = tmp->next;
	tmp->next = tmptmp->next;
	tmptmp->next = tmp;
	return (ok);
}

// Push, first element of other stack pushed to chosen stack.
short	push(t_list **head_a, t_list **head_b, short stack)
{
	t_list	*tmp;

	if (!*head_a || !*head_b)
		return (err);
	if (stack == pa)
	{
		tmp = *head_b;
		*head_b = tmp->next;
		tmp->next = *head_a;
		*head_a = tmp;
	}
	else if (stack == pb)
	{
		tmp = *head_a;
		*head_a = tmp->next;
		tmp->next = *head_b;
		*head_b = tmp;
	}
	return (ok);
}

// Rotate, firts becomes last.
short	rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return (err);
	if (list_len(head) == 2)
		return (swap(head));
	tmp = *head;
	*head = tmp->next;
	tmp->next = NULL;
	tmptmp = last_node(head);
	tmptmp->next = tmp;
	return (ok);
}

// Reverse rotate, last becomes first.
short	r_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return (err);
	if (list_len(head) == 2)
		return (swap(head));
	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmptmp = tmp->next;
	tmptmp->next = *head;
	tmp->next = NULL;
	*head = tmptmp;
	return (ok);
}
