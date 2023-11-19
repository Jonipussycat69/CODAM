/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 13:52:11 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/19 16:35:29 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	specifier_skip(int spec, t_fl *f)
{
	if (spec > 0 && spec < 10)
		return (2 + f->f_len);
	return (1);
}

int	ft_form(const char *form, size_t i, t_va *v, t_fl *f)
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
	if (v->spec == 0)
		fl_reset(f);
	else
		f->f_len = i - begin;
	return (v->spec);// LEFTOFF HERE!
}

int	ft_printf(const char *form, ...)// NO OUTPUT, SOME UNUSED VARIABLES! INSTALL GDB!
{
	va_list	args;
	t_va	v;
	t_fl	f;

	va_start(args, form);
	v.i = 0;
	v.print = ft_strdup("");
	while (form[v.i])
	{
		v.spec = ft_form(form, v.i, &v, &f);
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
