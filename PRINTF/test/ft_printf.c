/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:35:13 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/14 19:22:40 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spf(const char *form, int i)
{
	if (form[i] != '%')
		return (0);
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
	char	*print;
	t_va	va;

	va_start(args, form);
	va.i = 0;
	print = ft_strdup("");
	while (form[va.i])
	{
		va.spec = spf(form, va.i);
		if (va.spec > 1 && va.spec < 4)
			print = get_arg_void(va_arg(args, void *), va.spec, print);
		else if (va.spec == 6)
			print = get_arg_u(va_arg(args, unsigned int), va.spec, print);
		else if (va.spec > 0 && va.spec < 9)
			print = get_arg_int(va_arg(args, int), va.spec, print);
		else
			print = char_str(form[va.i], print, va.spec);
		if (print == NULL)
			return (-1);
		va.i += specifier_skip(va.spec);
	}
	va_end(args);
	return (writer(print));
}
