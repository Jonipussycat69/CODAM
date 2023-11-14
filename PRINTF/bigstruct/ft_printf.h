/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:07:56 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/14 13:43:53 by jdobos           ###   ########.fr       */
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

typedef struct	ft_printf_s
{
	char	*print;
	size_t	i;
	int		spec;
	size_t	p_len;
}	var;

int		ft_printf(const char *form, ...);
size_t	writer(char *print);
char	*char_str(int ch, var *va);
char	*add_print(var *va, char *stack);
char	*mod_itoa(long long value, int base, var *va, int hex_type);
void	*free_str(char *str);
char	*ptr_str(void *arg, var *va);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

char	*get_arg_void(void *arg, var *va);
char	*get_arg_u(unsigned int arg, var *va);
char	*get_arg_int(int arg, var *va);

#endif