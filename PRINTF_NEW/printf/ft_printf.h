/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 13:38:46 by jdobos        #+#    #+#                 */
/*   Updated: 2023/12/16 00:18:40 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_printf
{
	size_t			i;
	size_t			begin;
	size_t			print_len;
	size_t			arr_len;
	unsigned char	*print;
}	t_va;

typedef int (*printfunct)(va_list args, t_va *s);

int		ft_printf(const char *format, ...);
int		add_arr(unsigned char *heap, unsigned char *stack, t_va *s);

size_t	ft_strlen(const char *str);
int		ft_itoa(t_va *s, long long value, int base, const char *rep);

int		ft_char(t_va *s, int arg);
int		ft_str(t_va *s, char *arg);
int		ft_ptr(t_va *s, void *arg, const char *rep);

#endif