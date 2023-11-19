/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 13:07:56 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/19 16:20:13 by joni          ########   odam.nl         */
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
	size_t	width;
	size_t	f_len;
	int		fill_ch;
}	t_fl;

int		ft_printf(const char *form, ...);
size_t	writer(char *print);
size_t	specifier_skip(int spec, t_fl *f);

char	*char_str(int ch, char *heap, int type);
char	*add_print(char *heap, char *stack);
char	*add_p_f(char *heap, char *also_h);

char	*mod_itoa(long long value, int base, int hex_type);
void	*free_str(char *str);
char	*ptr_str(void *arg);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

char	*get_arg_void(void *arg, t_va *v, t_fl *f);
char	*get_arg_u(unsigned int arg, t_va *v, t_fl *f);
char	*get_arg_int(int arg, t_va *v, t_fl *f);
char	*arg_num(long long arg, t_va *v, t_fl *f);
char	*arg_ptr(void *arg, t_va *v, t_fl *f);

void	fl_reset(t_fl *f);
size_t	get_flags(const char *form, size_t i, t_va *v, t_fl *f);
size_t	get_width(const char *form, size_t i, t_va *v, t_fl *f);
int		spf(const char *form, int i);

char	*flag_check_str(t_va *v, t_fl *f, char *arg);
char	*flag_check_ptr(t_va *v, t_fl *f, void *arg);
char	*flag_check_ch(t_va *v, t_fl *f, int arg);
char	*flag_check_num(t_va *v, t_fl *f, long long arg);
char	*flag_check_hex(t_va *v, t_fl *f, long long arg);

char	*mal_set(size_t size, char c);
char	*pl_sp_h_print(t_va *v, t_fl *f);

#endif