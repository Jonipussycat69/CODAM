/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_printer_funct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:16:05 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/16 17:58:07 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_str(int ch, char *heap, int type)
{
	char			*result;
	char			*temp_heap;
	size_t			i;
	const size_t	heap_len = ft_strlen(heap);

	if (ch == 0)
		ch = -1;
	if (type == 9)
		return (add_print(heap, "%"));
	if (!heap)
		return (free_str(heap));
	result = (char *)malloc(heap_len + 2);
	if (!(result))
	i = 0;
	temp_heap = heap;
		return (free_str(heap));
	while (i < heap_len)
		result[i++] = *(temp_heap++);
	result[i++] = ch;
	result[i] = '\0';
	free_str(heap);
	return (result);
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
	result = (char *)malloc(s_len + h_len + 1);
	if (!(result))
		return (free_str(heap));
	i = 0;
	temp_heap = heap;
	while (i < h_len)
		result[i++] = *(temp_heap++);
	while (i - h_len < s_len)
		result[i++] = *(stack++);
	result[i] = '\0';
	free_str(heap);
	return (result);
}

char	*add_p_f(char *heap, char *also_h)
{
	char			*result;
	char			*temp_heap;
	size_t			i;
	const size_t	s_len = ft_strlen(also_h);
	const size_t	h_len = ft_strlen(heap);

	if (!heap || !also_h)
		return (free_str(heap));
	result = (char *)malloc(s_len + h_len + 1);
	if (!(result))
		return (free_str(heap));
	i = 0;
	temp_heap = heap;
	while (i < h_len)
		result[i++] = *(temp_heap++);
	temp_heap = also_h;
	while (i - h_len < s_len)
		result[i++] = *(temp_heap++);
	result[i] = '\0';
	free_str(heap);
	free_str(also_h);
	return (result);
}
