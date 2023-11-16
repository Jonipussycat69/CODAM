/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:58:59 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/16 18:00:33 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_base(long long value, int base, const char *rep)
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
	return (ft_strdup(ptr));
}

static char	*itoa_hex_neg_l(long long value, const char *rep)
{
	char	buf[65];
	char	*ptr;
	int		i;

	ptr = &buf[64];
	*ptr = '\0';
	i = 0;
	while (i++ < 16)
	{
		*(--ptr) = rep[value & 0xF];
		value >>= 4;
	}
	return (ft_strdup(ptr));
}

static char	*itoa_hex_neg_i(long long value, const char *rep)
{
	char	buf[65];
	char	*ptr;
	int		i;

	ptr = &buf[64];
	*ptr = '\0';
	i = 0;
	while (i++ < 8)
	{
		*(--ptr) = rep[value & 0xF];
		value >>= 4;
	}
	return (ft_strdup(ptr));
}

char	*mod_itoa(long long value, int base, int hex_type)
{
	const char	rep[] = "0123456789abcdef";
	const char	rep_up[] = "0123456789ABCDEF";

	if (hex_type == 3)
		return (itoa_hex_neg_l(value, rep));
	if (base != 10 && value < 0)
	{
		if (hex_type == 1)
			return (itoa_hex_neg_i(value, rep_up));
		else
			return (itoa_hex_neg_i(value, rep));
	}
	if (hex_type == 1)
		return (itoa_base(value, base, rep_up));
	else
		return (itoa_base(value, base, rep));
}

char	*ptr_str(void *arg)
{
	long long	value;

	if (!arg)
		return (ft_strdup("(nil)"));
	value = (long long)arg;
	if (value < 0)
		return (add_p_f(ft_strdup("0x"), mod_itoa(value, 16, 3)));
	else
		return (add_p_f(ft_strdup("0x"), mod_itoa(value, 16, 0)));
}
