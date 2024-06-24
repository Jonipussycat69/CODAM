#include "../minish_param.h"

char* expand_env_vars(const char* input) {
    char* result = strdup(input);
    char* dollar = strchr(result, '$');

    while (dollar != NULL) {
        // Find the end of the variable name
        char* end = dollar + 1;
        while (*end != '\0' && (isalnum(*end) || *end == '_')) {
            end++;
        }

        // Extract the variable name
        char var_name[256];
        strncpy(var_name, dollar + 1, end - dollar - 1);
        var_name[end - dollar - 1] = '\0';

        // Get the getenv_ret_value of the variable
        char* getenv_ret_value = getenv(var_name);

        if (getenv_ret_value != NULL) {
            // Replace the variable with its getenv_ret_value
            size_t new_len = strlen(result) + strlen(getenv_ret_value) - (end - dollar);
            char* new_result = malloc(new_len + 1);

            strncpy(new_result, result, dollar - result);
            new_result[dollar - result] = '\0';
            strcat(new_result, getenv_ret_value);
            strcat(new_result, end);

            free(result);
            result = new_result;
        }

        // Look for the next variable
        dollar = strchr(dollar + 1, '$');
    }

    return result;
}

// Parses for envariable, if found:
// Inputs envariable into node 0 of cmd_node
// and a strdup of getenv() output into node 1
size_t	parse_for_env_variable(t_dad *d, size_t i)
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
	cmd_head = init_cmd_head();// experimental
	if (!new_node_back_arglist(NULL, NULL, ENV_VAR, d->sig_arg_head) || \
	!new_node_back_cmdlist(cmd_head, extracted_str) || \
	!new_node_back_cmdlist(cmd_head, getenv_ret_value))
	{
		free(extracted_str);
		exit_clean(d, errno, NULL);
	}
	return (i);
}


// Assigns tokens to each argument.
// Tokens defined in: minish_def.h
void	tokenizer(t_dad *d)
{
	size_t	i;
	
	i = 0;
	while (d->line[i])
	{
		if (d->line[i] == ' ')
			++i;
		i = parse_for_env_variable(d, i);
	}
}
