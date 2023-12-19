/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_b_printf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 13:07:56 by jdobos        #+#    #+#                 */
/*   Updated: 2023/12/19 14:24:10 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_B_PRINTF_H
# define FT_B_PRINTF_H
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
	size_t	len;
}	t_va;

typedef struct s_flags
{
	size_t	f_pl;
	size_t	f_hash;
	size_t	f_sp;
	size_t	min;
	size_t	width;
	size_t	f_len;
	size_t	prec;
	int		ignore_prec;
	int		fill_ch;
}	t_fl;

int		ft_printf(const char *form, ...);
size_t	writer_b(char *print, const char *form);

char	*char_str_b(int ch, char *heap, int type);
char	*add_pr_b(char *heap, char *stack);
char	*add_p_f(char *heap, char *also_h);

char	*mod_itoa_b(long long value, int base, int hex_type, t_fl *f);
void	*free_str_b(char *str);
void	*free_both_str(char *str1, char *str2);
char	*ptr_str_b(void *arg, t_fl *f);
char	*ft_strdup_b(const char *s);
size_t	ft_strlen_b(const char *str);

char	*get_arg_void_b(void *arg, t_va *v, t_fl *f);
char	*get_arg_u_b(unsigned int arg, t_va *v, t_fl *f);
char	*get_arg_int_b(int arg, t_va *v, t_fl *f);
char	*arg_num_b(long long arg, t_va *v, t_fl *f);
char	*arg_ptr_b(void *arg, t_va *v, t_fl *f);

void	fl_reset(t_fl *f);
size_t	get_flags(const char *form, size_t i, t_fl *f);
size_t	get_width(const char *form, size_t i, t_fl *f);
size_t	get_prec(const char *form, size_t i, t_fl *f);
int		spf_b(const char *form, int i);

char	*flag_check_str(t_va *v, t_fl *f, char *arg);
char	*flag_check_ptr(t_va *v, t_fl *f, void *arg);
char	*flag_check_ch(t_va *v, t_fl *f, int arg);
char	*flag_check_num(t_va *v, t_fl *f, long long arg);
char	*flag_check_hex(t_va *v, t_fl *f, long long arg);

char	*mal_set(size_t size, char c);
char	*pl_sp_h_print(t_va *v, t_fl *f);
char	*neg_check(long long num, t_va *v, t_fl *f);
char	*hash_check(long long num, t_va *v, t_fl *f, int type);
char	*ptr_fill_check(void *ptr, t_va *v, t_fl *f, int type);

char	*ft_n_prec(char *str, size_t s_len, long long value, t_fl *f);
char	*ft_s_prec(char *str, size_t s_len, t_fl *f);

#endif