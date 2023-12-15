/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 16:59:20 by jdobos        #+#    #+#                 */
/*   Updated: 2023/12/15 19:27:23 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(t_va *s, long long value, int base, const char *rep)
{
	char		buf[65];
	char		*ptr;
	long long	num;

	ptr = &buf[64];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		*(--ptr) = rep[value % base];
	while (value != 0)
	{
		*(--ptr) = rep[value % base];
		value /= base;
	}
	if (num < 0 && base == 10)
		*(--ptr) = '-';
	return (add_arr(ptr, s));
}

int	ft_char()
{
	return (add_arr(s->print, ptr, s));
}

int	ft_str()
{
	return (add_arr(s->print, ptr, s));
}

int	ft_ptr()
{
	return (add_arr(s->print, ptr, s));
}
