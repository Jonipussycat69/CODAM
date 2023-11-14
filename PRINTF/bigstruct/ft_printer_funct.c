/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:16:05 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/14 13:53:56 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_str(int ch, var *va)
{
	char			*result;
	char			*temp_heap;
	size_t			i;
	const size_t	heap_len = va->p_len;

	va->p_len++;
	if (va->spec == 9)
		return (add_print(va, "%"));
	if (!va->print)
		return (free_str(va->print));
	i = 0;
	temp_heap = va->print;
	result = (char *)malloc(heap_len + 2);
	if (!(result))
		return (free_str(va->print));
	while (i < heap_len)
		result[i++] = *(temp_heap++);
	result[i++] = ch;
	result[i] = '\0';
	free_str(va->print);
	return (result);
}

char	*add_print(var *va, char *stack)
{
	char			*result;
	char			*temp_heap;
	size_t			i;
	const size_t	s_len = ft_strlen(stack);
	const size_t	h_len = va->p_len;

	if (!va->print || !stack)
		return (free_str(va->print));
	va->p_len += s_len;
	i = 0;
	temp_heap = va->print;
	result = (char *)malloc(s_len + h_len + 1);
	if (!(result))
		return (free_str(va->print));
	while (i < h_len)
		result[i++] = *(temp_heap++);
	while (i - h_len < s_len)
		result[i++] = *(stack++);
	result[i] = '\0';
	free_str(va->print);
	return (result);
}
