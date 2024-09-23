#include "../term_snake.h"

void	create_snake(t_data *data)
{
	short	i;
	t_body	node;

	i = 0;
	node.pos[0] = data->cols / 2;
	node.pos[1] = data->rows / 2;
	node.head = true;
	node.next = NULL;
	data->snake = new_body(&node);
	if (data->snake == NULL)
		exit_clean(data, true, "create_snake");
	node.head = false;
	while (i < STARTING_LEN)
	{
		node.pos[0] = (data->cols / 2 + 1) + i;
		if (body_add_back(&data->snake, &node))
			exit_clean(data, true, "create_snake");
		i++;
	}
}

void	snake_pos_reset(t_data *data)
{
	t_body			*temp;
	uint_fast16_t	i;

	temp = data->snake;
	i = 0;
	while (temp != NULL)
	{
		temp->pos[0] = (data->cols / 2 + i) % data->cols;
		temp->pos[1] = data->rows / 2;
		temp = temp->next;
		++i;
	}
}
