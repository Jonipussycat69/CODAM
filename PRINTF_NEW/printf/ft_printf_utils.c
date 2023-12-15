/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 16:59:20 by jdobos        #+#    #+#                 */
/*   Updated: 2023/12/15 20:32:40 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
	s->arr_len = ft_strlen(ptr);
	return (add_arr(s->print, ptr, s));
}

int	ft_char(t_va *s, int arg)
{
	const unsigned char *c = &arg;

	s->arr_len = 1;
	return (add_arr(s->print, c, s));
}

int	ft_str(t_va *s, char *arg)
{
	int	i;

	if (!arg)
	{
		s->arr_len = 6;
		return (add_arr(s->print, "(null)", s));
	}
	i = 0;
	while (arg[i])
		i++;
	s->arr_len = i;
	return (add_arr(s->print, arg, s));
}

int	ft_ptr(t_va *s, void *arg, const char *rep)
{
	unsigned long	value;
	char		buf[65];
	char		*ptr;
	int			i;

	if (!arg)
	{
		s->arr_len = 6;
		return (add_arr(s->print, "(nill)", s));
	}
	s->arr_len = 2;
	if (add_arr(s->print, "0x", s) == -1)
		return (-1);
	value = (unsigned long)arg;
	ptr = &buf[64];
	*ptr = '\0';
	i = 0;
	while (i++ < 16)
	{
		*(--ptr) = rep[value & 0xF];
		value >>= 4;
	}
	s->arr_len = ft_strlen(ptr);
	return (add_arr(s->print, ptr, s));
}
