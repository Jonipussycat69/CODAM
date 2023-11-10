/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 12:35:13 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/10 14:31:33 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_str(char const ch, char *heap)
{
	char	*result;
	char	*temp_heap;
	size_t	i;
	const size_t	heap_len = ft_strlen(heap);

	if (!heap || !ch)
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

char	*get_arg(void *arg, int specifier, char *print)
{
	if (specifier == 1 && arg)
		print = char_str(*(char *)arg, print);
	else if (specifier == 2 && arg)
		print = add_print(print, (char *)arg);
	else if (specifier == 3 && arg)
		print = ptr_str(arg, print);
	else if (specifier == 4 && arg)
		print = mod_itoa(*(int *)arg, 10, print, 0);
	else if (specifier == 5 && arg)
		print = mod_itoa(*(int *)arg, 10, print, 0);
	else if (specifier == 6 && arg)
		print = mod_itoa(*(unsigned int *)arg, 10, print, 0);
	else if (specifier == 7 && arg)
		print = mod_itoa(*(int *)arg, 16, print, 0);
	else if (specifier == 8 && arg)
		print = mod_itoa(*(int *)arg, 16, print, 1);
	else if (specifier == 9 && arg)
		print = add_print(print, "%");
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
		if (form[i + 1] && sp_check(form, i) > 0 && sp_check(form, i) < 10)
			print = get_arg(va_arg(args, void *), sp_check(form, i), print);
		else
			print = char_str(form[i], print);
		if (print == NULL)
			return (-1);
		printf("TEST>> print: %s,\ni: %zu, form[i && i + 1]: %c%c, specnum: %d<<\n\n", print, i, form[i], form[i + 1], sp_check(form, i));// TEST
		i += specifier_skip(sp_check(form, i));
	}
	i = ft_strlen(print);
	if (print && print[0] != '\0')
		write(1, print, i);
	va_end(args);
	free_str(print);
	return (i);
}
