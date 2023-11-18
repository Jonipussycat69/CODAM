/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 13:52:11 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/18 15:41:51 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spf(const char *form, int i)
{
	if (form[i] != '%')
		return (0);
	if (form[i] == 'c')
		return (1);
	if (form[i] == 's')
		return (2);
	if (form[i] == 'p')
		return (3);
	if (form[i] == 'd')
		return (4);
	if (form[i] == 'i')
		return (5);
	if (form[i] == 'u')
		return (6);
	if (form[i] == 'x')
		return (7);
	if (form[i] == 'X')
		return (8);
	if (form[i] == '%')
		return (9);
	return (0);
}

size_t	specifier_skip(int spec, t_fl *f)
{
	if (spec > 0 && spec < 10)
		return (2 + f->f_len);
	return (1);
}

void	ft_reset(t_fl *f)
{
	f->f_pl = 0;
	f->f_hash = 0;
	f->f_sp = 0;
	f->min = 0;
	f->fill_ch = 32;
	f->width = 0;
	f->order = 0;
	f->f_len = 0;
}

int	ft_flags(const char *form, int i, t_va *v, t_fl *f)
{
	ft_reset(f);
	if (form[i] != '%')
		return (0);
	if (spf(form, i + 1))
		return (spf(form, i + 1));
	get_flags(form, i, v, f);// WRITE THESE FUNCTIONS! FIRST FIND OUT ORDER!
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	t_va	v;
	t_fl	f;

	va_start(args, form);
	v.i = 0;
	v.print = ft_strdup("");
	while (form[v.i])
	{
		v.spec = ft_flags(form, v.i, &v, &f);
		if (v.spec == 2 || v.spec == 3)
			v.print = get_arg_void(va_arg(args, void *), &v, &f);
		else if (v.spec == 6)
			v.print = get_arg_u(va_arg(args, unsigned int), &v, &f);
		else if (v.spec > 0 && v.spec < 9)
			v.print = get_arg_int(va_arg(args, int), &v, &f);
		else
			v.print = char_str(form[v.i], v.print, v.spec);
		if (v.print == NULL)
			return (-1);
		v.i += specifier_skip(v.spec, &f);
	}
	va_end(args);
	return (writer(v.print));
}
