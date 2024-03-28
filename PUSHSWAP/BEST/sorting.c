#include "push_swap.h"

// algo that calculates all the steps for each node, NO connecting nodes!
// just looking at the right place it should go in b (inbetween the closest bigger and smaller number).
// node->ind = amound of r, node->ind - total list_len = rr (so it will be negative).
// It pushes to b until there are only 3 num left in a.
// at the end b should be rotated so it starts at the biggest and be sorted in descending order
void	pb_stage(t_list **a, t_list **b)
{
	
}

// Pushes evrything back to stack a, and reverse rotates the remaining 3 num on top at the right time.
// when this stage is done b should be empty.
// when this stage is done a should be sorted in ascending order.
void	pa_stage(t_list **a, t_list **b)
{
	
}

// this is the middle stage that sorts the remaining 3 num in stack a before commencing to pa_stage.
void	hardsort(t_list **a, t_list **b)
{
	
}
