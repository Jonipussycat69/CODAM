/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:32:05 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/06 17:36:33 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_node_rotate_a(t_list **a)
{
	int		i;
	int		i_small;
	int		small;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	small = INT_MAX;
	while (tmp != NULL)
	{
		if (tmp->n_i < small)
		{
			small = tmp->n_i;
			i_small = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (i_small);
}

int	biggest_node_rotate_a(t_list **a)
{
	int		i;
	int		i_big;
	int		big;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	big = INT_MIN;
	while (tmp != NULL)
	{
		if (tmp->n_i > big)
		{
			big = tmp->n_i;
			i_big = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (i_big + 1);
}

int	rotate_amount_a(t_list **a, int val)
{
	t_list			*tmp;
	const t_list	*last_a = last_node(a);
	int				i;

	if (*a == NULL)
		return (0);
	if (smallest(a, val))
		return (smallest_node_rotate_a(a));
	i = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		if (i == 0 && tmp->num > val && last_a->num < val)
			return (0);
		if (tmp == last_a && tmp->num < val && (*a)->num > val)
			return (i);
		if (tmp != last_a && tmp->num < val && tmp->next->num > val)
			return (i + 1);
		tmp = tmp->next;
		i++;
	}
	return (biggest_node_rotate_a(a));
}

// Returns 'ok' if stack is sorted ascending, 'err' if not
short	check_sort_asc(t_list **head)
{
	t_list	*tmp;
	int		prev_index;

	if (!*head)
		return (err);
	tmp = *head;
	while (tmp->next != NULL)
	{
		prev_index = tmp->num;
		tmp = tmp->next;
		if (tmp->num < prev_index)
			return (err);
	}
	return (ok);
}

char	*ps_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) malloc ((ps_strlen((char *)s) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
