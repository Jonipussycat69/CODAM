#include "../term_snake.h"

t_turn	*new_turn(const t_turn *data)
{
	t_turn	*turn;

	turn = malloc(sizeof(t_turn));
	if (turn == NULL)
		return (NULL);
	turn->pos[0] = data->pos[0];
	turn->pos[1] = data->pos[1];
	turn->len_remain = data->len_remain;
	turn->pre_direction = data->pre_direction;
	turn->post_direction = data->post_direction;
	turn->next = NULL;
	return (turn);
}

void	node_back(t_turn **turn, t_turn *node)
{
	t_turn	*temp;

	temp = *turn;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	free_list(t_turn **turn)
{
	t_turn	*temp;

	temp = *turn;
	while (temp != NULL)
	{
		*turn = temp->next;
		free(temp);
		temp = *turn;
	}
}

void	turn_copy(t_turn *turn, const t_turn *data)
{
	turn->pos[0] = data->pos[0];
	turn->pos[1] = data->pos[1];
	turn->len_remain = data->len_remain;
	turn->pre_direction = data->pre_direction;
	turn->post_direction = data->post_direction;
	turn->next = NULL;
}

bool	turn_add_back(t_turn **turn, const t_turn *data)
{
	t_turn	*new_t;

	new_t = new_turn(data);
	if (new_turn == NULL)
		return (FAIL);
	if (*turn == NULL)
		*turn = new_t;
	else
		node_back(turn, new_t);
	return (SUCC);
}

int		list_len(t_turn *turn)
{
	int	i = 0;

	while (turn != NULL)
	{
		i++;
		turn = turn->next;
	}
	return (i);
}

t_turn	*last_node(t_turn *turn)
{
	while (turn->next != NULL)
		turn = turn->next;
	return (turn);
}
