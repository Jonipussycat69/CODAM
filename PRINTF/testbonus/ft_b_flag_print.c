/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_b_flag_print.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 14:53:17 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/17 17:02:01 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (f->f_hash >= 1)
		f->width--;
	return (v->print);
}

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
}

char	*flag_check_ptr(t_va *v, t_fl *f, void *arg)
{
	char	*arg_str;
	size_t	arg_len;

	arg_str = arg_ptr(arg, v, f);
	arg_len = ft_strlen(arg_str);
	if (f->f_pl >= 1)// SHOULD POINTER HAVE + OPTION? UNDEFINED BEHAVIOUR.
		v->print = pl_sp_h_print(v, f);
	if (f->width <= arg_len)
		return (add_p_f(v->print, arg_str));
	if (f->min == 0)
	{
		v->print = add_p_f(v->print, mal_set(f->width - arg_len, ' '));
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
}

char	*flag_check_num(t_va *v, t_fl *f, long long arg)
{
	char	*arg_str;
	size_t	arg_len;

	arg_str = arg_num(arg, v, f);
	arg_len = ft_strlen(arg_str);
	if ((f->f_pl >= 1 || f->f_sp >= 1) && arg > 0)
		v->print = pl_sp_h_print(v, f);
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
}

char	*flag_check_hex(t_va *v, t_fl *f, long long arg)
{
	char	*arg_str;
	size_t	arg_len;

	arg_str = arg_num(arg, v, f);
	arg_len = ft_strlen(arg_str);
	if (f->f_hash >= 1)
		v->print = pl_sp_h_print(v, f);
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
}
