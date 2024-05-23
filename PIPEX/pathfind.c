/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pathfind.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 14:17:20 by jdobos        #+#    #+#                 */
/*   Updated: 2024/05/23 15:55:37 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*create_full_path(char *path, char *cmd)
{
	char		*ret;
	const int	plen = ft_strlen(path);
	const int	clen = ft_strlen(cmd);
	int			i;
	int			j;

	ret = (char *)malloc(plen + clen + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (path[i])
	{
		ret[i] = path[i];
		i++;
	}
	j = 0;
	ret[i++] = '/';
	while (cmd[j])
		ret[i++] = cmd[j++];
	ret[i] = '\0';
	return (ret);
}

char	*path_find(char *cmd, char **envp)
{
	char	*path;
	char	**split_paths;
	int		i;

	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (*envp == NULL)
		return (perror("NO PATH"), NULL);
	split_paths = ft_split((*envp) + 5, ':');
	if (!split_paths)
		return (perror("Malloc fail"), NULL);
	i = 0;
	while (split_paths[i])
	{
		path = create_full_path(split_paths[i], cmd);
		if (!path)
			return (free_double_arr(split_paths), perror("Malloc fail"), NULL);
		if (access(path, X_OK) == 0)
			return (free_double_arr(split_paths), path);
		free(path);
		i++;
	}
	return (free_double_arr(split_paths), perror("NO PATH"), NULL);
}
