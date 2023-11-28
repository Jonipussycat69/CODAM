/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:31:24 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/28 18:32:19 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
