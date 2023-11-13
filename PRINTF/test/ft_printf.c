/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:35:13 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/13 13:59:46 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_str(char ch, char *heap, int type)
{
	char	*result;
	char	*temp_heap;
	size_t	i;
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

int	sp_check(const char *form, int i)
{
	if (form[i] == '%' && form[i + 1] == 'c')
		return (1);
	if (form[i] == '%' && form[i + 1] == 's')
		return (2);
	if (form[i] == '%' && form[i + 1] == 'p')
		return (3);
	if (form[i] == '%' && form[i + 1] == 'd')
		return (4);
	if (form[i] == '%' && form[i + 1] == 'i')
		return (5);
	if (form[i] == '%' && form[i + 1] == 'u')
		return (6);
	if (form[i] == '%' && form[i + 1] == 'x')
		return (7);
	if (form[i] == '%' && form[i + 1] == 'X')
		return (8);
	if (form[i] == '%' && form[i + 1] == '%')
		return (9);
	return (0);
}

char	*get_arg_void(void *arg, int specifier, char *print)
{
	if (specifier == 2 && arg)
		print = add_print(print, (char *)arg);
	else if (specifier == 3)
		print = ptr_str(arg, print);
	if (!(print))
		return (NULL);
	return (print);
}

char	*get_arg_uns(unsigned int arg, int specifier, char *print)
{
	if (specifier == 6)
		print = mod_itoa(arg, 10, print, 0);
	if (!(print))
		return (NULL);
	return (print);
}

char	*get_arg_int(int arg, int specifier, char *print)
{
	if (specifier == 1)
		print = char_str((char)arg, print, 0);
	else if (specifier == 4)
		print = mod_itoa(arg, 10, print, 0);
	else if (specifier == 5)
		print = mod_itoa(arg, 10, print, 0);
	else if (specifier == 7)
		print = mod_itoa(arg, 16, print, 0);
	else if (specifier == 8)
		print = mod_itoa(arg, 16, print, 1);
	if (!(print))
		return (NULL);
	return (print);
}

size_t	specifier_skip(int spec)
{
	if (spec > 0 && spec < 10)
		return (2);
	return (1);
}

size_t	writer(char *print)
{
	size_t	i;

	i = ft_strlen(print);
	if (print && print[0] != '\0')
		write(1, print, i);
	free_str(print);
	return (i);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	size_t	i;
	char	*print;

	va_start(args, form);
	i = 0;
	print = ft_strdup("");
	while (form[i])
	{
		// printf("TEST>> print: %s,\ni: %zu, form[i && i + 1]: %c%c, specnum: %d<<\n\n", print, i, form[i], form[i + 1], sp_check(form, i));// TEST
		if (sp_check(form, i) > 1 && sp_check(form, i) < 4)
			print = get_arg_void(va_arg(args, void *), sp_check(form, i), print);
		else if (sp_check(form, i) == 6)
			print = get_arg_uns(va_arg(args, unsigned int), sp_check(form, i), print);
		else if (sp_check(form, i) > 0 && sp_check(form, i) < 9)
			print = get_arg_int(va_arg(args, int), sp_check(form, i), print);
		else
			print = char_str(form[i], print, sp_check(form, i));
		if (print == NULL)
			return (-1);
		i += specifier_skip(sp_check(form, i));
	}
	i = writer(print);
	va_end(args);
	return (i);
}
