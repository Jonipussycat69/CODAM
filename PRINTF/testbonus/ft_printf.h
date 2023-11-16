/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:07:56 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/16 16:07:50 by jdobos           ###   ########.fr       */
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
	size_t	i;
	int		spec;
	char	*print;
}	t_va;

typedef struct s_flags
{
	size_t	f_pl;
	size_t	f_hash;
	size_t	f_sp;
	size_t	min;
	size_t	zero;
	size_t	width;
	size_t	order;
	size_t	p_len;
}	t_fl;

int		ft_printf(const char *form, ...);
size_t	writer(char *print);
char	*char_str(int ch, char *heap, int type);
char	*add_print(char *heap, char *stack);
char	*mod_itoa(long long value, int base, char *print, int hex_type);
void	*free_str(char *str);
char	*ptr_str(void *arg, char *print);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

char	*get_arg_void(void *arg, t_va *v, t_fl *f);
char	*get_arg_u(unsigned int arg, t_va *v, t_fl *f);
char	*get_arg_int(int arg, t_va *v, t_fl *f);

#endif