#include "push_swap.h"

int	get_i_value(t_list *node)
{
	if (!node)
		return (err);
	return (node->i_value);
}

int	get_li(t_list *node)
{
	if (!node)
		return (err);
	return (node->list_index);
}

int	get_value(t_list *node)
{
	if (!node)
		return (err);
	return (node->value);
}

int	get_si(t_list *node)
{
	if (!node)
		return (err);
	return (node->stack_iv);
}

int	get_mark(t_list *node)
{
	if (!node)
		return (err);
	return (node->mark);
}

int	get_side(t_list *node)
{
	if (!node)
		return (err);
	return (node->side);
}
