/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_extend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:36:05 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/06 13:38:11 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_arr_reset(t_sort *s)
{
	short	i;

	i = 0;
	while (i < 8)
	{
		s->act_arr[i] = 0;
		i++;
	}
	return ;
}

int	bn(int one, int two)
{
	if (one > two)
		return (one);
	return (two);
}

int	sn(int one, int two)
{
	if (one < two)
		return (one);
	return (two);
}

short	smallest(t_list **a, int val)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->n_i < val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

short	ps_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
