/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_flag_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:53:17 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/16 15:22:17 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_check_str(t_va *v, t_fl *f, char *arg)
{

}

char	*flag_check_ptr(t_va *v, t_fl *f, void *arg)
{

}

char	*flag_check_ch(t_va *v, t_fl *f, int arg)
{

}

char	*flag_check_num(t_va *v, t_fl *f, long long arg)
{

}

char	*flag_check_hex(t_va *v, t_fl *f, long long arg)
{

}

char	*get_arg_void(void *arg, t_va *v, t_fl *f)
{
	if (specifier == 2 && arg)
		print = add_print(print, (char *)arg);
	if (specifier == 2 && !arg)
		print = add_print(print, "(null)");
	else if (specifier == 3)
		print = ptr_str(arg, print);
	if (!(print))
		return (NULL);
	return (print);
}

char	*get_arg_u(unsigned int arg, t_va *v, t_fl *f)
{
	if (specifier == 6)
		print = mod_itoa(arg, 10, print, 0);
	if (!(print))
		return (NULL);
	return (print);
}

char	*get_arg_int(int arg, t_va *v, t_fl *f)
{
	if (specifier == 1)
		print = char_str(arg, print, 0);
	else if (specifier == 4)
		print = mod_itoa(arg, 10, print, 0);
	else if (specifier == 5)
		print = mod_itoa(arg, 10, print, 0);
	else if (specifier == 7)
		print = mod_itoa(arg, 16, print, 0);
	else if (specifier == 8)
		print = mod_itoa(arg, 16, print, 1);
	if (!(print))
		return (NULL);
	return (print);
}