/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_action.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:27:01 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/07 15:25:45 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swap, first and second elemnt swapped.
void	swap(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return ;
	tmp = *head;
	tmptmp = tmp->next;
	tmp->next = tmptmp->next;
	tmptmp->next = tmp;
	*head = tmptmp;
	return ;
}

// Push, first element of other stack pushed to chosen stack.
void	push(t_list **head_a, t_list **head_b, short stack)
{
	t_list	*tmp;

	if ((!*head_a && stack == pb) || (!*head_b && stack == pa))
		return ;
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
	return ;
}

// Rotate, firts becomes last.
void	rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return ;
	if (list_len(head) == 2)
		return (swap(head));
	tmp = *head;
	*head = tmp->next;
	tmp->next = NULL;
	tmptmp = last_node(head);
	tmptmp->next = tmp;
	return ;
}

// Reverse rotate, last becomes first.
void	r_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head || list_len(head) < 2)
		return ;
	if (list_len(head) == 2)
		return (swap(head));
	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmptmp = tmp->next;
	tmptmp->next = *head;
	tmp->next = NULL;
	*head = tmptmp;
	return ;
}
