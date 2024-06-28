#include "../minish_param.h"

t_sig_arg	*create_arg_node
(
	t_cmd_node	**cmd_head,
	char		**cmd_arr,
	short		token
)
{
	t_sig_arg	*new_arg_node;

	new_arg_node = (t_sig_arg *)malloc(sizeof(t_sig_arg));
	if (!new_arg_node)
		return (NULL);
	new_arg_node->cmd_array = cmd_arr;
	new_arg_node->cmd_head = cmd_head;
	new_arg_node->token = token;
	new_arg_node->next = NULL;
	return (new_arg_node);
}

// RETURN: head = success, NULL = failure (whole list is freed)
t_sig_arg	**new_node_back_arglist
(
	t_cmd_node	**cmd_head,
	char		**cmd_arr,
	short		token,
	t_sig_arg	**head
)
{
	t_sig_arg	*new_arg_node;
	t_sig_arg	*tmp;

	new_arg_node = create_arg_node(cmd_head, cmd_arr, token);
	if (!new_arg_node)
		return (free_arglist(head), NULL);
	if (!head)
		return (&new_arg_node);
	if (!(*head))
		return (head = &new_arg_node, head);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->next = new_arg_node, head);
}

t_sig_arg	*arglist_last_node(t_sig_arg **head)
{
	t_sig_arg	*tmp;

	if (!head || !(*head))
		return (NULL);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	free_arglist(t_sig_arg **head)
{
	t_sig_arg	*tmp;
	t_sig_arg	*tmp_tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		free_cmdlist(tmp->cmd_head);
		free_double_arr(tmp->cmd_array);
		tmp_tmp = tmp->next;
		free(tmp);
		tmp = tmp_tmp;
	}
}
