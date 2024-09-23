#include "../term_snake.h"

t_body	*new_body(const t_body *data)
{
	t_body	*body;

	body = malloc(sizeof(t_body));
	if (body == NULL)
		return (NULL);
	body->pos[0] = data->pos[0];
	body->pos[1] = data->pos[1];
	body->head = data->head;
	body->next = data->next;
	return (body);
}

void	node_back(t_body **body, t_body *node)
{
	t_body	*temp;

	temp = *body;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	free_list(t_body **body)
{
	t_body	*temp;

	temp = *body;
	while (temp != NULL)
	{
		*body = temp->next;
		free(temp);
		temp = *body;
	}
}

bool	body_add_back(t_body **body, const t_body *data)
{
	t_body	*new_b;

	new_b = new_body(data);
	if (new_b == NULL)
		return (FAIL);
	if (*body == NULL)
		*body = new_b;
	else
		node_back(body, new_b);
	return (SUCC);
}

int		body_len(t_body *body)
{
	int	i = 0;

	while (body != NULL)
	{
		i++;
		body = body->next;
	}
	return (i);
}

t_body	*last_node(t_body *body)
{
	while (body->next != NULL)
		body = body->next;
	return (body);
}
