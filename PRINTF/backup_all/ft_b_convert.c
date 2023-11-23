/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:58:59 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/23 16:21:17 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_b_printf.h"

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
	return (ft_strdup_b(ptr));
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
	return (ft_strdup_b(ptr));
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
	return (ft_strdup_b(ptr));
}

char	*mod_itoa_b(long long value, int base, int hex_type, t_fl *f)
{
	const char	rep[] = "0123456789abcdef";
	const char	rep_up[] = "0123456789ABCDEF";
	char		*rtrn_str;

	if (hex_type == 3)
		return (itoa_hex_neg_l(value, rep));
	if (base != 10 && value < 0)
	{
		if (hex_type == 1)
			rtrn_str = itoa_hex_neg_i(value, rep_up);
		else
			rtrn_str = itoa_hex_neg_i(value, rep);
		rtrn_str = ft_n_prec(rtrn_str, ft_strlen_b(rtrn_str), 1, f);
		return (rtrn_str);
	}
	if (hex_type == 1)
		rtrn_str = itoa_base(value, base, rep_up);
	else
		rtrn_str = itoa_base(value, base, rep);
	rtrn_str = ft_n_prec(rtrn_str, ft_strlen_b(rtrn_str), value, f);
	return (rtrn_str);
}

char	*ptr_str_b(void *arg, t_fl *f)
{
	long long	value;

	if (!arg)
		return (ft_strdup_b("(nil)"));
	value = (long long)arg;
	f->prec = 0;
	if (value < 0)
		return (mod_itoa_b(value, 16, 3, f));
	else
		return (mod_itoa_b(value, 16, 0, f));
}
