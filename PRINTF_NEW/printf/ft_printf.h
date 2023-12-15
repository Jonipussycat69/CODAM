/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 13:38:46 by jdobos        #+#    #+#                 */
/*   Updated: 2023/12/15 19:26:41 by jdobos        ########   odam.nl         */
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
	int				spec;
	size_t			print_len;
	size_t			arr_len;
	unsigned char	*print;
	unsigned char	*temp_arr;
	unsigned char	*temp_iter;
}	t_va;

typedef int (*printfunct)(va_list args, t_va *s);

int		ft_printf(const char *format, ...);
char	*ft_itoa(t_va *s, long long value, int base, const char *rep);
int		add_arr(unsigned char *heap, unsigned char *stack, t_va *s);

#endif