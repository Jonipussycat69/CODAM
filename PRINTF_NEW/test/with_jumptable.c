/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   with_jumptable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 16:39:03 by jdobos        #+#    #+#                 */
/*   Updated: 2023/12/15 16:39:17 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

printfunct table[256] = {
	['i'] = ft_int,
	['d'] = ft_digit,
	['s'] = ft_str,
	['c'] = ft_char,
	['x'] = ft_hexl,
	['X'] = ft_hexu,
	['p'] = ft_ptr
};

unsigned char	*add_arr(unsigned char *dest, unsigned char *src, t_va *s)
{
	
}

int	ft_write(t_va *s)
{
	int	words_written;

	words_written = 0;
	words_written = write(1, s->print, s->print_len);
	return (words_written);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_va	s;

	if (!format)
		return (-1);
	s.i = 0;
	s.begin = 0;
	s.print_len = 0;
	va_start(args, format);
	while (format[s.i])
	{
		if (format[s.i] == '%')
		{
			s.print_len += s.i - s.begin;
			s.begin = s.i;
		}
		s.i++;
	}
	return (ft_write(&s));
}
