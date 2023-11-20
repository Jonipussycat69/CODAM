/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_flag_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:53:17 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/20 16:31:02 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_b_printf.h"

char	*flag_check_str(t_va *v, t_fl *f, char *arg)
{
	const size_t	arg_len = ft_strlen(arg);

	if (f->width <= arg_len)
		return (add_print(v->print, arg));
	if (f->min == 0)
	{
		v->print = add_p_f(v->print, mal_set(f->width - arg_len, ' '));
		if (!(v->print))
			return (NULL);
		return (add_print(v->print, arg));
	}
	if (f->min > 0)
	{
		v->print = add_print(v->print, arg);
		if (!(v->print))
			return (NULL);
		return (add_p_f(v->print, mal_set(f->width - arg_len, ' ')));
	}
	return (NULL);
}

char	*flag_check_ptr(t_va *v, t_fl *f, void *arg)
{
	char	*arg_str;
	size_t	arg_len;

	arg_str = arg_ptr(arg, v, f);
	arg_len = ft_strlen(arg_str);
	v->print = ptr_fill_check(arg, v, f, arg_len, 0);
	if (f->width <= arg_len)
		return (add_p_f(v->print, arg_str));
	if (f->min == 0 && arg != NULL)
	{
		v->print = add_p_f(v->print, mal_set(f->width - arg_len, f->fill_ch));
		if (!(v->print))
			return (free_str(arg_str));
		v->print = ptr_fill_check(arg, v, f, arg_len, 1);
		return (add_p_f(v->print, arg_str));
	}
	if (f->min > 0 && arg != NULL)
	{
		v->print = add_p_f(v->print, arg_str);
		if (!(v->print))
			return (NULL);
		return (add_p_f(v->print, mal_set(f->width - arg_len, ' ')));
	}
	return (NULL);
}

char	*flag_check_ch(t_va *v, t_fl *f, int arg)
{
	if (f->width <= 1)
		return (char_str(arg, v->print, 0));
	if (f->min == 0)
	{
		v->print = add_p_f(v->print, mal_set(f->width - 1, ' '));
		if (!(v->print))
			return (NULL);
		return (char_str(arg, v->print, 0));
	}
	if (f->min > 0)
	{
		v->print = char_str(arg, v->print, 0);
		if (!(v->print))
			return (NULL);
		return (add_p_f(v->print, mal_set(f->width - 1, ' ')));
	}
	return (NULL);
}

char	*flag_check_num(t_va *v, t_fl *f, long long arg)
{
	char	*arg_str;
	size_t	arg_len;

	v->print = neg_check(arg, v, f);
	if (arg < 0 && f->fill_ch == 48)
		arg *= -1;
	arg_str = arg_num(arg, v, f);
	arg_len = ft_strlen(arg_str);
	if (f->width <= arg_len)
		return (add_p_f(v->print, arg_str));
	if (f->min == 0)
	{
		v->print = add_p_f(v->print, mal_set(f->width - arg_len, f->fill_ch));
		if (!(v->print))
			return (free_str(arg_str));
		return (add_p_f(v->print, arg_str));
	}
	if (f->min > 0)
	{
		v->print = add_p_f(v->print, arg_str);
		if (!(v->print))
			return (NULL);
		return (add_p_f(v->print, mal_set(f->width - arg_len, ' ')));
	}
	return (NULL);
}

char	*flag_check_hex(t_va *v, t_fl *f, long long arg)
{
	char	*arg_str;
	size_t	arg_len;

	arg_str = arg_num(arg, v, f);
	arg_len = ft_strlen(arg_str);
	v->print = hash_check(arg, v, f, arg_len, 0);
	if (f->width <= arg_len)
		return (add_p_f(v->print, arg_str));
	if (f->min == 0)
	{
		v->print = add_p_f(v->print, mal_set(f->width - arg_len, f->fill_ch));
		if (!(v->print))
			return (free_str(arg_str));
		v->print = hash_check(arg, v, f, arg_len, 1);
		return (add_p_f(v->print, arg_str));
	}
	if (f->min > 0)
	{
		v->print = add_p_f(v->print, arg_str);
		if (!(v->print))
			return (NULL);
		return (add_p_f(v->print, mal_set(f->width - arg_len, ' ')));
	}
	return (NULL);
}
