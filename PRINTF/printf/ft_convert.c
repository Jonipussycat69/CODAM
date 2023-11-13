/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:58:59 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/13 17:25:27 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_base(long long value, int base, const char *rep, char *print)
{
	char		buf[100];
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
	return (add_print(print, ptr));
}

static char	*itoa_hex_neg(long long value, const char *rep, char *print)
{
	char	buf[10];
	char	*ptr;
	int		i;

	ptr = &buf[9];
	*ptr = '\0';
	i = 0;
	while (i++ < 8)
	{
		*(--ptr) = rep[value & 0xF];
		value >>= 4;
	}
	return (add_print(print, ptr));
}

char	*mod_itoa(long long value, int base, char *print, int hex_type)
{
	const char	rep[] = "0123456789abcdef";
	const char	rep_up[] = "0123456789ABCDEF";

	if (base != 10 && value < 0)
	{
		if (hex_type == 1)
			return (itoa_hex_neg(value, rep_up, print));
		else
			return (itoa_hex_neg(value, rep, print));
	}
	if (hex_type == 1)
		return (itoa_base(value, base, rep_up, print));
	else
		return (itoa_base(value, base, rep, print));
}

char	*ptr_str(void *arg, char *print)
{
	if (!arg)
		return (add_print(print, "0x0"));
	print = add_print(print, "0x");
	return (mod_itoa((long long)arg, 16, print, 0));
}
