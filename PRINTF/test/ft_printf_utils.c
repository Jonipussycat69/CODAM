/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 12:35:08 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/10 12:43:41 by joni          ########   odam.nl         */
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

char	*add_print(char *heap, char *stack)
{
	char			*result;
	char			*temp_heap;
	size_t			i;
	const size_t	s_len = ft_strlen(stack);
	const size_t	h_len = ft_strlen(heap);

	if (!heap || !stack)
		return (free_str(heap));
	i = 0;
	temp_heap = heap;
	result = (char *)malloc(s_len + h_len + 1);
	if (!(result))
		return (free_str(heap));
	while (i < h_len)
		result[i++] = *(temp_heap++);
	while (i - h_len < s_len)
		result[i++] = *(stack++);
	result[i] = '\0';
	free_str(heap);
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
