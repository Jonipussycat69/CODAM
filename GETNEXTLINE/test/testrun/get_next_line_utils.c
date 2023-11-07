/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 19:43:20 by joni          #+#    #+#                 */
/*   Updated: 2023/11/07 23:29:37 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_line(char *line)
{
	if (line != NULL)
		free(line);
	return (NULL);
}

size_t	nl_count(char *str, int type)
{
	size_t	nl;

	if (!str)
		return (0);
	nl = 0;
	if (type == 1)
	{
		while (str[nl] && (nl == 0 || str[nl - 1] != '\n'))
			nl++;
		return (nl);
	}
	while (*str)
	{
		if (*str == '\n')
			nl++;
		str++;
	}
	return (nl);
}
