#include "../minish_param.h"

t_env_node	*create_env_node(char *key, char *value)
{
	t_env_node	*new_env_node;

	new_env_node = (t_env_node *)malloc(sizeof(t_env_node));
	if (!new_env_node)
		return (NULL);
	new_env_node->key = key;
	new_env_node->value = value;
	new_env_node->next = NULL;
	return (new_env_node);
}

// RETURN: head = success, NULL = failure (whole list is freed)
t_env_node	**new_node_back_envlist(t_env_node **head, char *key, char *value)
{
	t_env_node	*new_env_node;
	t_env_node	*tmp;

	new_env_node = create_env_node(key, value);
	if (!new_env_node)
		return (free_envlist(head), NULL);
	if (!head)
		return (&new_env_node);
	if (!(*head))
		return (*head = new_env_node, head);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->next = new_env_node, head);
}

t_env_node	*envlist_last_node(t_env_node **head)
{
	t_env_node	*tmp;

	if (!head || !(*head))
		return (NULL);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	free_envlist(t_env_node **head)
{
	t_env_node	*tmp;
	t_env_node	*tmp_tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		free_va(2, tmp->key, tmp->value);
		tmp_tmp = tmp->next;
		free(tmp);
		tmp = tmp_tmp;
	}
}
