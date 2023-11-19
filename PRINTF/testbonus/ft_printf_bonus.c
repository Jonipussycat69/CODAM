/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 13:52:11 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/19 12:19:13 by joni          ########   odam.nl         */
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

void	fl_reset(t_fl *f)
{
	f->f_pl = 0;
	f->f_hash = 0;
	f->f_sp = 0;
	f->min = 0;
	f->fill_ch = 32;
	f->width = 0;
	f->f_len = 0;
}

size_t	get_flags(const char *form, size_t i, t_va *v, t_fl *f)
{
	while (form[i] == ' ' || form[i] == '+' || form[i] == '-' ||
	form[i] == '0' || form[i] == '#')
	{
		if (form[i] == ' ')
			f->f_sp++;
		if (form[i] == '+')
			f->f_pl++;
		if (form[i] == '-')
			f->min++;
		if (form[i] == '0')
			f->fill_ch = 48;
		if (form[i] == '#')
			f->f_hash++;
		f->f_len++;
		i++;
	}
	return (i);
}

size_t	get_width(const char *form, size_t i, t_va *v, t_fl *f)
{
	size_t	num_len;
	size_t	num;

	num_len = 0;
	num = 0;
	while (form[i] >= '0' && form[i] <= '9' && num_len++ < 10)
		num = num * 10 + (form[i++] - 48);
	f->width = num;
	return (i);
}

int	ft_flags(const char *form, size_t i, t_va *v, t_fl *f)
{
	const size_t	begin = i;

	fl_reset(f);
	if (form[i] != '%')
		return (0);
	if (spf(form, i + 1))
		return (spf(form, i + 1));
	i = get_flags(form, i, v, f);
	i = get_width(form, i, v, f);
	v->spec = spf(form, i);
	if (v->spec == 0 || v->spec == 9)
		fl_reset(f);
	else
		f->f_len = i - begin;
	return (v->spec);// LEFTOFF HERE!
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
