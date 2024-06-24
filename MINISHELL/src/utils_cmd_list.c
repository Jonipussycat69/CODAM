#include "../minish_param.h"

t_cmd_node	*create_cmd_node(char *content)
{
	t_cmd_node	*new_cmd_node;

	new_cmd_node = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (!new_cmd_node)
		return (NULL);
	new_cmd_node->content = content;
	new_cmd_node->next = NULL;
	return (new_cmd_node);
}

bool	new_node_back_cmdlist(t_cmd_node **head, char *content)
{
	t_cmd_node	*new_cmd_node;
	t_cmd_node	*tmp;

	if (!head)
		return (false);
	new_cmd_node = create_cmd_node(content);
	if (!new_cmd_node)
		return (false);
	if (!(*head))
		return (*head = new_cmd_node, true);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->next = new_cmd_node, true);
}

// (EXPERIMENTAL)
// Returns: cmd_node ** which points to a cmd_node *(NULL)
// Use before using: new_node_back_cmdlist()
t_cmd_node	**init_cmd_head(void)
{
	t_cmd_node	**new_head;
	t_cmd_node	*null_node;

	null_node = NULL;
	new_head = &null_node;
	return (new_head);
}
