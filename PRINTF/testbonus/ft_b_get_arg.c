/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_get_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:16 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/16 16:01:06 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_arg_void(void *arg, t_va *v, t_fl *f)
{
	if (v->spec == 2 && arg && f->p_len > 0)
		v->print = flag_check_str(v, f, arg);
	if (v->spec == 2 && !arg && f->p_len > 0)
		v->print = flag_check_str(v, f, "(null)");
	else if (v->spec == 3 && f->p_len > 0)
		v->print = flag_check_ptr(v, f, arg);
	else if (v->spec == 2 && arg)
		v->print = add_print(v->print, (char *)arg);
	else if (v->spec == 2 && !arg)
		v->print = add_print(v->print, "(null)");
	else if (v->spec == 3)
		v->print = ptr_str(arg, v->print);
	if (!(v->print))
		return (NULL);
	return (v->print);
}

char	*get_arg_u(unsigned int arg, t_va *v, t_fl *f)
{
	if (v->spec == 6 && f->p_len > 0)
		v->print = flag_check_num(v, f, arg);
	else if (v->spec == 6)
		v->print = mod_itoa(arg, 10, v->print, 0);
	if (!(v->print))
		return (NULL);
	return (v->print);
}

char	*get_arg_int(int arg, t_va *v, t_fl *f)
{
	if (v->spec == 1 && f->p_len > 0)
		v->print = flag_check_ch(v, f, arg);
	else if (v->spec == 4 && f->p_len > 0)
		v->print = flag_check_num(v, f, arg);
	else if (v->spec == 5 && f->p_len > 0)
		v->print = flag_check_num(v, f, arg);
	else if (v->spec == 7 && f->p_len > 0)
		v->print = flag_check_hex(v, f, arg);
	else if (v->spec == 8 && f->p_len > 0)
		v->print = flag_check_hex(v, f, arg);
	else if (v->spec == 1)
		v->print = char_str(arg, v->print, 0);
	else if (v->spec == 4)
		v->print = mod_itoa(arg, 10, v->print, 0);
	else if (v->spec == 5)
		v->print = mod_itoa(arg, 10, v->print, 0);
	else if (v->spec == 7)
		v->print = mod_itoa(arg, 16, v->print, 0);
	else if (v->spec == 8)
		v->print = mod_itoa(arg, 16, v->print, 1);
	if (!(v->print))
		return (NULL);
	return (v->print);
}
