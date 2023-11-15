/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 12:35:13 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/15 14:37:22 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	spf(const char *form, int i)
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

static size_t	specifier_skip(int spec)
{
	if (spec > 0 && spec < 10)
		return (2);
	return (1);
}

static char	*form_print(size_t *i, const char *form, char *print)// DOES NOT WORK WHY?
{
	size_t	begin;
	size_t	j;
	char	*str;

	begin = *i;
	while (form[*i] && spf(form, *i) == 0)
		(*i)++;
	if (*i - begin <= 0)
		return (print);
	str = (char *)malloc(*i - begin + 1);
	if (!str || print == NULL)
		return (free_str(print));
	j = 0;
	while (begin < *i)
		str[j++] = form[begin++];
	str[j] = '\0';
	print = add_print(print, str);
	free_str(str);
	return (print);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	t_va	v;

	va_start(args, form);
	v.i = 0;
	v.print = ft_strdup("");
	while (form[v.i])
	{
		v.print = form_print(&v.i, form, v.print);
		v.spec = spf(form, v.i);
		if (v.print && v.spec > 1 && v.spec < 4)
			v.print = get_arg_void(va_arg(args, void *), v.spec, v.print);
		else if (v.print && v.spec == 6)
			v.print = get_arg_u(va_arg(args, unsigned int), v.spec, v.print);
		else if (v.print && v.spec > 0 && v.spec < 9)
			v.print = get_arg_int(va_arg(args, int), v.spec, v.print);
		else if (v.print && v.spec == 9)
			v.print = char_str(form[v.i], v.print, v.spec);
		if (v.print == NULL)
			return (-1);
		v.i += specifier_skip(v.spec);
	}
	va_end(args);
	return (writer(v.print));
}
