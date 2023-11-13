/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:35:13 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/13 14:42:20 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spf(const char *form, int i)
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
		if (spf(form, i) > 1 && spf(form, i) < 4)
			print = get_arg_void(va_arg(args, void *), spf(form, i), print);
		else if (spf(form, i) == 6)
			print = get_arg_u(va_arg(args, unsigned int), spf(form, i), print);
		else if (spf(form, i) > 0 && spf(form, i) < 9)
			print = get_arg_int(va_arg(args, int), spf(form, i), print);
		else
			print = char_str(form[i], print, spf(form, i));
		if (print == NULL)
			return (-1);
		i += specifier_skip(spf(form, i));
	}
	i = writer(print);
	va_end(args);
	return (i);
}
