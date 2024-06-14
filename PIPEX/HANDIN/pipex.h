/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 18:47:14 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/14 13:52:55 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

// LIBFT UTILS

char	**ft_split(const char *s, const char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// PIPEX UTILS

void	free_double_arr(char **arr);
char	*path_find(char *cmd, char **envp);

void	error_exit(int errornum, char *message);
void	set_input(int input_fd);
void	set_output(int output_fd);
int		open_inputfile(const char *inputfile);
int		open_outputfile(const char *outputfile);

#endif
