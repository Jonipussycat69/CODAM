/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:07:56 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/13 14:42:28 by jdobos           ###   ########.fr       */
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

int		ft_printf(const char *form, ...);
size_t	writer(char *print);
char	*char_str(char ch, char *heap, int type);
char	*add_print(char *heap, char *stack);
char	*mod_itoa(long long value, int base, char *print, int hex_type);
void	*free_str(char *str);
char	*ptr_str(void *arg, char *print);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

char	*get_arg_void(void *arg, int specifier, char *print);
char	*get_arg_u(unsigned int arg, int specifier, char *print);
char	*get_arg_int(int arg, int specifier, char *print);

#endif