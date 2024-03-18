#include "push_swap.h"

short	swap_both(t_list **head_a, t_list **head_b)
{
	if (swap(head_a) != ok)
		return (err);
	if (swap(head_b) != ok)
		return (err);
	return (ok);
}

short	rotate_both(t_list **head_a, t_list **head_b)
{
	if (rotate(head_a) != ok)
		return (err);
	if (rotate(head_b) != ok)
		return (err);
	return (ok);
}

short	r_rotate_both(t_list **head_a, t_list **head_b)
{
	if (r_rotate(head_a) != ok)
		return (err);
	if (r_rotate(head_b) != ok)
		return (err);
	return (ok);
}
