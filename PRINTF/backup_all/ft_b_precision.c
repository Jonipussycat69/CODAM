/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:39:43 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/23 14:20:48 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_b_printf.h"

char	*ft_n_prec(char *str, size_t s_len, long long value, t_fl *f)
{
	size_t	padding;
	char	*pad_str;

	if (f->prec <= s_len)
	{
		if (value < 0)
			return (add_p_f(ft_strdup("-"), str));
		return (str);
	}
	padding = f->prec - s_len;
	pad_str = mal_set(padding, '0');
	if (value < 0)
		pad_str = add_p_f(ft_strdup("-"), pad_str);
	if (!pad_str)
		return (free_str(str));
	return (add_p_f(pad_str, str));
}

char	*ft_s_prec(char *str, size_t s_len, t_fl *f)
{
	char	*rtrn_str;
	size_t	i;
	size_t	j;

	if (f->prec >= s_len || f->ignore_prec == 1)
		f->prec = s_len;
	rtrn_str = (char *)malloc(f->prec + 1);
	if (!rtrn_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < f->prec)
		rtrn_str[i++] = str[j++];
	rtrn_str[i] = '\0';
	return (rtrn_str);
}
