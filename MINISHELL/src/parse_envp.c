#include "../minish_param.h"

// NOT CORRECT!

// Parses for envariable, if found:
// Inputs envariable into node 0 of cmd_node
// and a strdup of getenv() output into node 1
// RETURN: incremented index
size_t	parse_env_variable(t_dad *d, size_t i)
{
	size_t		start;
	t_cmd_node	**cmd_head;
	char		*extracted_str;
	char		*getenv_ret_value;

	if (d->line[i] != '$')
		return (i);
	start = i;
	while (d->line[i] && (d->line[i] == '_' || ft_isalnum(d->line[i])))
		++i;
	extracted_str = strdup_index(d->line, start, i);
	if (!extracted_str)
		exit_clean(d, errno, NULL);
	getenv_ret_value = getenv(extracted_str);
	// not good!
	if (!new_node_back_arglist(NULL, NULL, ENV_VAR, d->sig_arg_head) || \
	!new_node_back_cmdlist(cmd_head, extracted_str) || \
	!new_node_back_cmdlist(cmd_head, getenv_ret_value))
	{
		free(extracted_str);
		exit_clean(d, errno, NULL);
	}
	return (i);
}
