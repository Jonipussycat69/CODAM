/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:16:48 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/13 18:05:42 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_line(char *line)
{
	if (line != NULL)
		free(line);
	return (NULL);
}

size_t	nl_count(char *str, int type)
{
	size_t	i;

	i = 0;
	if (str && type == 1)
	{
		while (str[i] && (i == 0 || str[i - 1] != '\n'))
			i++;
		return (i);
	}
	while (str && *str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
