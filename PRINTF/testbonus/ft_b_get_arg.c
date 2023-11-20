/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_get_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:16 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/20 16:53:34 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_b_printf.h"

char	*get_arg_void(void *arg, t_va *v, t_fl *f)
{
	if (f->f_len == 0 && v->spec == 2)
		v->print = add_print(v->print, arg_ptr(arg, v));
	else if (v->spec == 2 && arg && f->f_len > 0)
		v->print = flag_check_str(v, f, (char *)arg);
	else if (v->spec == 2 && !arg && f->f_len > 0)
		v->print = flag_check_str(v, f, "(null)");
	else if (v->spec == 3)
		v->print = flag_check_ptr(v, f, arg);
	if (!(v->print))
		return (NULL);
	return (v->print);
}

char	*get_arg_u(unsigned int arg, t_va *v, t_fl *f)
{
	if (v->spec == 6 && f->f_len == 0)
		v->print = add_p_f(v->print, arg_num(arg, v));
	else if (v->spec == 6 && f->f_len > 0)
		v->print = flag_check_num(v, f, arg);
	if (!(v->print))
		return (NULL);
	return (v->print);
}

char	*get_arg_int(int arg, t_va *v, t_fl *f)
{
	if (f->f_len == 0 && v->spec == 1)
		v->print = char_str(arg, v->print, 0);
	else if (f->f_len == 0)
		v->print = add_p_f(v->print, arg_num(arg, v));
	else if (v->spec == 1 && f->f_len > 0)
		v->print = flag_check_ch(v, f, arg);
	else if (v->spec == 4 && f->f_len > 0)
		v->print = flag_check_num(v, f, arg);
	else if (v->spec == 5 && f->f_len > 0)
		v->print = flag_check_num(v, f, arg);
	else if (v->spec == 7 && f->f_len > 0)
		v->print = flag_check_hex(v, f, arg);
	else if (v->spec == 8 && f->f_len > 0)
		v->print = flag_check_hex(v, f, arg);
	if (!(v->print))
		return (NULL);
	return (v->print);
}

char	*arg_num(long long arg, t_va *v)
{
	char	*arg_str;

	arg_str = NULL;
	if (v->spec == 6)
		arg_str = mod_itoa(arg, 10, 0);
	else if (v->spec == 4)
		arg_str = mod_itoa(arg, 10, 0);
	else if (v->spec == 5)
		arg_str = mod_itoa(arg, 10, 0);
	else if (v->spec == 7)
		arg_str = mod_itoa(arg, 16, 0);
	else if (v->spec == 8)
		arg_str = mod_itoa(arg, 16, 1);
	return (arg_str);
}

char	*arg_ptr(void *arg, t_va *v)
{
	char	*arg_str;

	arg_str = NULL;
	if (v->spec == 2 && arg)
		arg_str = add_print(ft_strdup(""), (char *)arg);
	else if (v->spec == 2 && !arg)
		arg_str = add_print(ft_strdup(""), "(null)");
	else if (v->spec == 3)
		arg_str = ptr_str(arg);
	return (arg_str);
}
