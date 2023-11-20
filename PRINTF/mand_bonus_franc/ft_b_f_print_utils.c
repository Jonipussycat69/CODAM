/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_f_print_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:34:47 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/20 16:43:40 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_b_printf.h"

char	*mal_set(size_t size, char c)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(size + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

char	*pl_sp_h_print(t_va *v, t_fl *f)
{
	if (f->f_sp >= 1 && f->f_pl == 0)
		v->print = char_str(' ', v->print, 0);
	else if (f->f_pl >= 1)
		v->print = char_str('+', v->print, 0);
	else if (f->f_hash >= 1 && v->spec == 7)
		v->print = add_print(v->print, "0x");
	else if (f->f_hash >= 1 && v->spec == 8)
		v->print = add_print(v->print, "0X");
	if (f->width > 0 && (f->f_pl >= 1 || f->f_sp >= 1 || f->f_hash >= 1))
		f->width--;
	if (f->width > 0 && f->f_hash >= 1)
		f->width--;
	return (v->print);
}

char	*neg_check(long long num, t_va *v, t_fl *f)
{
	if ((f->f_pl >= 1 || f->f_sp >= 1) && num > 0 && v->spec != 6)
		return (pl_sp_h_print(v, f));
	if (num > 0)
		return (v->print);
	if (f->fill_ch == 48)
	{
		f->width--;
		v->print = char_str('-', v->print, 0);
	}
	return (v->print);
}

char	*hash_check(long long num, t_va *v, t_fl *f, int type)
{
	if (type == 0)
	{
		if (f->f_hash >= 1 && num != 0 && f->width <= v->len)
			return (pl_sp_h_print(v, f));
		if (f->f_hash >= 1 && num != 0 && (f->min > 0 || f->fill_ch == 48))
			v->print = pl_sp_h_print(v, f);
		else if (f->f_hash >= 1 && num != 0 && f->width > 1)
			f->width -= 2;
		else if (f->f_hash >= 1 && num != 0 && f->width > 0)
			f->width -= 1;
	}
	if (type == 1)
	{
		if (f->f_hash >= 1 && num != 0 && f->fill_ch == 32)
		{
			f->width += 2;
			v->print = pl_sp_h_print(v, f);
		}
	}
	return (v->print);
}

char	*ptr_fill_check(void *ptr, t_va *v, t_fl *f, int type)
{
	if (!ptr)
		return (v->print);
	if (type == 0)
	{
		if (f->width <= v->len)
			return (add_print(v->print, "0x"));
		if (f->min > 0 || f->fill_ch == 48)
			v->print = add_print(v->print, "0x");
		if (f->width > 1)
			f->width -= 2;
		else if (f->width > 0)
			f->width -= 1;
	}
	if (type == 1)
	{
		if (f->fill_ch == 32)
			v->print = add_print(v->print, "0x");
	}
	return (v->print);
}
