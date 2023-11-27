/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 12:16:48 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/16 12:04:18 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_line(char *line)
{
	if (line != NULL)
		free(line);
	return (NULL);
}

size_t	nl_len(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] && (i == 0 || str[i - 1] != '\n'))
			i++;
		return (i);
	}
	return (0);
}

size_t	nl_check(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
