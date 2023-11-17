/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 13:52:11 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/17 15:00:45 by joni          ########   odam.nl         */
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

size_t	specifier_skip(int spec, t_fl *f)
{
	if (spec > 0 && spec < 10)
		return (2);
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
	f->p_len = 0;
}

int	get_flags(const char *form, int i, t_fl *f)
{
	ft_reset(f);
	if (form[i] != '%')
		return (0);
	if (spf(form, i))
		return (spf(form, i));
	f->f_pl = plus_count(form, i, f);
	f->f_hash = hash_count(form, i, f);
	f->f_sp = space_count(form, i, f);
	f->min = min_check(form, i, f);
	f->fill_ch = zero_check(form, i, f);
	f->width = get_width(form, i, f);// WRITE THESE FUNCTIONS! FIRST FIND OUT ORDER!
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
		v.spec = get_flags(form, v.i, &f);
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
