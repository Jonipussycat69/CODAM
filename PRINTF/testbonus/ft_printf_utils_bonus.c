/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:49:10 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/16 14:49:17 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*free_str(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	writer(char *print)
{
	size_t	i;
	size_t	begin;

	i = 0;
	while (print && print[i] != '\0')
	{
		begin = i;
		while (print[i] && print[i] != -1)
			i++;
		write(1, print + begin, i - begin);
		if (print[i] == -1)
		{
			print[i] = 0;
			write(1, &print[i], 1);
			i++;
		}
	}
	free_str(print);
	return (i);
}
