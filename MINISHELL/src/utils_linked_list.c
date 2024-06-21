#include "../minish_param.h"

t_sig_arg	*create_new_node_arg
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

// Creates new sig_arg node AND appends it to back of the list
bool	new_node_back_arglist
(
	t_cmd_node	**cmd_head,
	char		**cmd_arr,
	short		token,
	t_sig_arg	**head
)
{
	const t_sig_arg	*arg_node = create_new_node_arg(cmd_head, cmd_arr, token);
	t_sig_arg		*tmp;

	if (!arg_node)
		return (false);
	if (!(*head))
		return (head = &arg_node, true);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = arg_node;
	return (true);
}
