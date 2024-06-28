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

// RETURN: head = success, NULL = failure (whole list is freed)
t_cmd_node	**new_node_back_cmdlist(t_cmd_node **head, char *content)
{
	t_cmd_node	*new_cmd_node;
	t_cmd_node	*tmp;

	new_cmd_node = create_cmd_node(content);
	if (!new_cmd_node)
		return (free_cmdlist(head), NULL);
	if (!head)
		return (&new_cmd_node);
	if (!(*head))
		return (*head = new_cmd_node, head);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->next = new_cmd_node, head);
}

t_cmd_node	*cmdlist_last_node(t_cmd_node **head)
{
	t_cmd_node	*tmp;

	if (!head || !(*head))
		return (NULL);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	free_cmdlist(t_cmd_node **head)
{
	t_cmd_node	*tmp;
	t_cmd_node	*tmp_tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		free_if(tmp->content);
		tmp_tmp = tmp->next;
		free(tmp);
		tmp = tmp_tmp;
	}
}
