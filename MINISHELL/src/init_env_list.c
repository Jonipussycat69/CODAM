#include "../minish_param.h"

static char	*create_key_str(char *line)
{
	size_t	i;
	char	*ret_str;
	char	*key;

	i = 0;
	while (line[i] && (line[i] == '_' || ft_isalnum(line[i])))
		++i;
	key = strdup_index(line, 0, i);
	if (!key)
		return (NULL);
	ret_str = (char *)malloc(i + 2);
	if (!ret_str)
		return (free(key), NULL);
	ret_str[0] = '$';
	ft_strlcpy(ret_str + 1, key, i - 1);
	free(key);
	ret_str[i] = '\0';
	return (ret_str);
}

static char	*create_value_str(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && (line[i] == '_' || ft_isalnum(line[i])))
		++i;
	return (strdup_index(line, ++i, ft_strlen(line)));
}

// Creates linked list of env:
// ->key = "$PATH"
// ->value = "/home/lib:/etc"
t_env_node	**create_env_list(char **envp)
{
	t_env_node	**head;
	size_t		line;
	size_t		i;
	char		*key;
	char		*value;

	i = 0;
	head = NULL;
	while (envp[line] != NULL)
	{
		key = create_key_str(envp[line]);
		if (!key)
			return (free_envlist(head), NULL);
		value = create_value_str(envp[line]);
		if (!value)
			return (free(key), free_envlist(head), NULL);
		head = new_node_back_envlist(head, key, value);
		if (!head)
			return (free(key), free(value), NULL);
		++line;
	}
	return (head);
}
