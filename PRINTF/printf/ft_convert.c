/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:58:59 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/13 14:40:05 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_base(long long value, int base, const char *rep, char *print)
{
	char		buf[100];
	char		*ptr;
	long long	num;

	ptr = &buf[64];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		*--ptr = rep[value % base];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value /= base;
	}
	if (num < 0 && base == 10)
		*--ptr = '-';
	return (add_print(print, ptr));
}

char	*mod_itoa(long long value, int base, char *print, int hex_type)
{
	const char	rep[] = "0123456789abcdef";
	const char	rep_up[] = "0123456789ABCDEF";

	if (base != 10 && value < 0)
		value *= -1;
	if (hex_type == 1)
		return (itoa_base(value, base, rep_up, print));
	else
		return (itoa_base(value, base, rep, print));
}

char	*ptr_str(void *arg, char *print)
{
	if (!arg)
		return (add_print(print, "0x0"));
	print = add_print(print, "0x");
	return (mod_itoa((long long)arg, 16, print, 0));
}

char	*char_str(char ch, char *heap, int type)
{
	char			*result;
	char			*temp_heap;
	size_t			i;
	const size_t	heap_len = ft_strlen(heap);

	if (type == 9)
		return (add_print(heap, "%"));
	if (!heap)
		return (free_str(heap));
	i = 0;
	temp_heap = heap;
	result = (char *)malloc(heap_len + 2);
	if (!(result))
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
