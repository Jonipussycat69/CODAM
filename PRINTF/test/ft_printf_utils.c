/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:35:08 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/09 17:45:09 by jdobos           ###   ########.fr       */
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

char	*add_print(char const *heap, char const *stack)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!heap || !stack)
		return (free_str((char *)heap));
	i = 0;
	j = ft_strlen(heap) + ft_strlen(stack) + 1;
	result = (char *)malloc(j * sizeof(char));
	if (!(result))
		return (free_str((char *)heap));
	j = ft_strlen(heap);
	while (i < j)
	{
		result[i] = heap[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(stack))
		result[j++] = stack[i++];
	result[j] = '\0';
	free_str((char *)heap);
	return (result);
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
