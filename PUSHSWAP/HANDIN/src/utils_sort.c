/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:32:05 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/07 15:26:17 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	abs(int val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

int	rotate_amount_a(t_list **a, int val)
{
	t_list	*tmp;
	int		bindex;
	int		i;
	int		diff;
	int		small;

	tmp = *a;
	small = INT_MAX;
	i = 0;
	bindex = -1;
	while (tmp != NULL)
	{
		diff = abs(val - tmp->num);
		if (diff < small && val < tmp->num)
		{
			small = diff;
			bindex = i;
		}
		++i;
		tmp = tmp->next;
	}
	if (bindex == -1)
		return (biggest_node_rotate_a(a));
	return (bindex);
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
