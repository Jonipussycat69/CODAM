/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_pathfind.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 14:17:20 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/10 12:57:17 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

static char	*create_path(char *piece, char *cmd, char *path)
{
	int	i;
	int	j;

	i = 0;
	while (piece[i])
	{
		path[i] = piece[i];
		i++;
	}
	j = 0;
	path[i++] = '/';
	while (cmd[j])
		path[i++] = cmd[j++];
	path[i] = '\0';
	return (path);
}

char	*path_find(char *cmd, char *path, char **envp)
{
	char	**split_paths;
	int		i;

	if (!envp)
		error_exit(127, NULL);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (*envp == NULL)
		error_exit(127, NULL);
	split_paths = ft_split((*envp) + 5, ':');
	if (!split_paths)
		error_exit(errno, "malloc");
	i = 0;
	while (split_paths[i])
	{
		path = create_path(split_paths[i], cmd, path);
		if (access(path, X_OK) == 0)
			return (free_double_arr(split_paths), path);
		i++;
	}
	free_double_arr(split_paths);
	return (NULL);
}

char	**split_command(char *cmd)
{
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
		error_exit(EXIT_FAILURE, "malloc");
	return (split_cmd);
}
