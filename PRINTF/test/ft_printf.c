/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:35:13 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/09 17:48:58 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_str(char ch, char *print)
{
	char	ch_str[2];

	ch_str[0] = ch;
	ch_str[1] = '\0';
	return (add_print(print, ch_str));
}

int	form_check(const char *form, int i, char *print)
{
	if (form[i] == '%' && form[i + 1] == 'c')
		return (1);
	if (form[i] == '%' && form[i + 1] == 's')
		return (2);
	if (form[i] == '%' && form[i + 1] == 'p')
		return (3);
	if (form[i] == '%' && form[i + 1] == 'd')
		return (4);
	if (form[i] == '%' && form[i + 1] == 'i')
		return (5);
	if (form[i] == '%' && form[i + 1] == 'u')
		return (6);
	if (form[i] == '%' && form[i + 1] == 'x')
		return (7);
	if (form[i] == '%' && form[i + 1] == 'X')
		return (8);
	if (form[i] == '%' && form[i + 1] == '%')
		return (9);
	return (0);
}

char	*get_arg(void *arg, int specifier, char *print)
{
	if (specifier == 1 && arg)
		print = char_str(*(char *)arg, print);
	else if (specifier == 2 && arg)
		print = add_print(print, (char *)arg);
	else if (specifier == 3 && arg)
		print = mod_itoa((long long)arg, 16, print, 1);
	else if (specifier == 4 && arg)
		print = mod_itoa(*(int *)arg, 10, print, 0);
	else if (specifier == 5 && arg)
		print = mod_itoa(*(int *)arg, 10, print, 0);
	else if (specifier == 6 && arg)
		print = mod_itoa(*(unsigned int *)arg, 10, print, 0);
	else if (specifier == 7 && arg)
		print = mod_itoa(*(int *)arg, 16, print, 0);
	else if (specifier == 8 && arg)
		print = mod_itoa(*(int *)arg, 16, print, 1);
	else if (specifier == 9 && arg)
		print = add_print(print, "%");
	if (!(print))
		return (NULL);
	return (print);
}

size_t	specifier_skip(int spec)
{
	if (spec > 0 && spec < 10)
		return (2);
	return (1);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	size_t	i;
	char	*print;

	va_start(args, form);
	i = 0;
	print = ft_strdup("");
	while (form[i])
	{
		if (form_check(form, i, print) > 0 && form_check(form, i, print) < 10)
			print = get_arg(va_arg(args, void *), form_check(form, i, print), print);
		else if (form_check(form, i, print) == 0)
			print = char_str(form[i], print);
		if (print == NULL)
			return (-1);
		i += specifier_skip(form_check(form, i, print));
	}
	i = ft_strlen(print);
	if (print && print[0] != '\0')
		write(1, print, i);
	va_end(args);
	if (print)
		free(print);
	return (i);
}
