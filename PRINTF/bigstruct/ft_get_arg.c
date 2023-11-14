/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:27:13 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/14 13:46:53 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_arg_void(void *arg, var *va)
{
	if (va->spec == 2 && arg)
		va->print = add_print(va, (char *)arg);
	if (va->spec == 2 && !arg)
		va->print = add_print(va, "(null)");
	else if (va->spec == 3)
		va->print = ptr_str(arg, va);
	if (!(va->print))
		return (NULL);
	return (va->print);
}

char	*get_arg_u(unsigned int arg, var *va)
{
	if (va->spec == 6)
		va->print = mod_itoa(arg, 10, va, 0);
	if (!(va->print))
		return (NULL);
	return (va->print);
}

char	*get_arg_int(int arg, var *va)
{
	if (va->spec == 1)
		va->print = char_str(arg, va);
	else if (va->spec == 4)
		va->print = mod_itoa(arg, 10, va, 0);
	else if (va->spec == 5)
		va->print = mod_itoa(arg, 10, va, 0);
	else if (va->spec == 7)
		va->print = mod_itoa(arg, 16, va, 0);
	else if (va->spec == 8)
		va->print = mod_itoa(arg, 16, va, 1);
	if (!(va->print))
		return (NULL);
	return (va->print);
}
