/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_action_double.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:26:42 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/07 15:25:41 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_both(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
	return ;
}

void	rotate_both(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
	return ;
}

void	r_rotate_both(t_list **head_a, t_list **head_b)
{
	r_rotate(head_a);
	r_rotate(head_b);
	return ;
}
