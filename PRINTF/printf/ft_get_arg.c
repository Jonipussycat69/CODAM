/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:27:13 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/13 14:42:24 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_arg_void(void *arg, int specifier, char *print)
{
	if (specifier == 2 && arg)
		print = add_print(print, (char *)arg);
	else if (specifier == 3)
		print = ptr_str(arg, print);
	if (!(print))
		return (NULL);
	return (print);
}

char	*get_arg_u(unsigned int arg, int specifier, char *print)
{
	if (specifier == 6)
		print = mod_itoa(arg, 10, print, 0);
	if (!(print))
		return (NULL);
	return (print);
}

char	*get_arg_int(int arg, int specifier, char *print)
{
	if (specifier == 1)
		print = char_str((char)arg, print, 0);
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
