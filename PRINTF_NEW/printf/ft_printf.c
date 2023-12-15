/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 13:38:19 by jdobos        #+#    #+#                 */
/*   Updated: 2023/12/16 00:12:47 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_spec(va_list arg, t_va *s, char frm)
{
	const char	rep[] = "0123456789abcdef";
	const char	rep_up[] = "0123456789ABCDEF";

	if (frm == 'c')
		return (ft_char(s, va_arg(arg, int)));
	if (frm == 's')
		return (ft_str(s, va_arg(arg, char *)));
	if (frm == 'p')
		return (ft_ptr(s, va_arg(arg, void *), rep));
	if (frm == 'd' || frm == 'i')
		return (ft_itoa(s, va_arg(arg, int), 10, rep));
	if (frm == 'u')
		return (ft_itoa(s, va_arg(arg, unsigned int), 10, rep));
	if (frm == 'x')
		return (ft_itoa(s, va_arg(arg, unsigned int), 16, rep));
	if (frm == 'X')
		return (ft_itoa(s, va_arg(arg, unsigned int), 16, rep_up));
	if (frm == '%')
		return (1);
	return (0);
}

int	add_arr(unsigned char *heap, unsigned char *stack, t_va *s)
{
	unsigned char	*new_arr;
	size_t			i;

	if (!stack || s->arr_len <= 0)
		return (0);
	new_arr = (unsigned char *)malloc(s->arr_len + s->print_len);
	if (!new_arr)
		return (free(s->print), -1);
	i = 0;
	while (i < s->print_len)
		new_arr[i++] = *(heap++);
	while (i < s->print_len + s->arr_len)
		new_arr[i++] = *(stack++);
	free(s->print);
	s->print = new_arr;
	s->print_len += s->arr_len;
	s->arr_len = 0;
	return (0);
}

static int	ft_write(t_va *s, const char *form)
{
	int	words_written;

	if (!form)
		return (-1);
	words_written = write(1, s->print, s->print_len);
	free(s->print);
	return (words_written);
}

static int	get_form(va_list args, t_va *s, const char *frm)
{
	int	ret;

	ret = 0;
	s->arr_len = 0;
	if (frm[s->i + 1] == 'i' || frm[s->i + 1] == 'd' || frm[s->i + 1] == 'c' \
	|| frm[s->i + 1] == 's' || frm[s->i + 1] == 'p' || frm[s->i + 1] == 'x' \
	|| frm[s->i + 1] == 'X' || frm[s->i + 1] == 'u' || frm[s->i + 1] == '%')
	{
		s->arr_len += s->i - s->begin;
		if (add_arr(s->print, (unsigned char *)frm + s->begin, s) == -1)
			return (-1);
		s->begin = ++s->i + 1;
		ret = ft_spec(args, s, frm[s->i]);
	}
	if (ret == 1)
	{
		s->arr_len = 1;
		if (add_arr(s->print, (unsigned char *)"%", s) == -1)
			return (-1);
		return (ret);
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_va	s;

	s.print = NULL;
	s.i = 0;
	s.begin = 0;
	s.print_len = 0;
	va_start(args, format);
	while (format && format[s.i])
	{
		if (format[s.i] == '%')
			if (get_form(args, &s, format) < 0)
				return (-1);
		s.i++;
	}
	if (s.begin < s.i)
	{
		s.arr_len = s.i - s.begin;
		if (add_arr(s.print, (unsigned char *)format + s.begin, &s) == -1)
			return (-1);
	}
	va_end(args);
	return (ft_write(&s, format));
}
