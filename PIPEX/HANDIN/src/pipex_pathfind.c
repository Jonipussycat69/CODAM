/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_pathfind.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 14:17:20 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/14 14:21:38 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_double_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}

static char	*create_path(char *piece, char *cmd, char *path)
{
	int		i;
	int		j;
	char	*new_path;

	free(path);
	new_path = (char *)malloc(ft_strlen(piece) + ft_strlen(cmd) + 2);
	if (!new_path)
		return (NULL);
	i = 0;
	while (piece[i])
	{
		new_path[i] = piece[i];
		i++;
	}
	j = 0;
	new_path[i++] = '/';
	while (cmd[j])
		new_path[i++] = cmd[j++];
	new_path[i] = '\0';
	return (new_path);
}

static char	*envp_check(char **envp)
{
	if (!envp)
		return (NULL);
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (*envp == NULL)
		return (NULL);
	return (*envp);
}

char	*path_find(char *cmd, char **envp)
{
	char	**split_paths;
	char	*envp_path;
	char	*path;
	int		i;

	envp_path = envp_check(envp);
	if (!envp_path)
		return (errno = 127, NULL);
	split_paths = ft_split(envp_path + 5, ':');
	if (!split_paths)
		return (NULL);
	i = 0;
	path = NULL;
	while (split_paths[i])
	{
		path = create_path(split_paths[i], cmd, path);
		if (!path)
			return (free_double_arr(split_paths), NULL);
		if (access(path, X_OK) == 0)
			return (free_double_arr(split_paths), path);
		i++;
	}
	free(path);
	free_double_arr(split_paths);
	return (errno = 127, NULL);
}
