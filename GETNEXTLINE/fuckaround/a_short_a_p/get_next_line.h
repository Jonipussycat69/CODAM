/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:55:39 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/28 18:27:56 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define RETURN_NULL_IF(condition) do { if (condition) { return NULL; } } while (0)

# define F_R_N_IF(condition, str) do { if (condition) { free(str); return NULL; } } while (0)

# define END_CHECK(condition, str) do { if (condition) { free(str); return NULL; } else {return (str);} } while (0)

# define WHILE(condition, body) \
while (condition) \
{ \
	body \
}

# define NL_CHECK(inp, i, out) \
while (inp[i]) \
{ \
	if (inp[i] == '\n') {out = 1;} \
	i++; \
}

# define NL_LEN(inp, i) \
while (inp[i] && (i == 0 || inp[i - 1] != '\n')) \
{ \
	i++; \
}

# define READ_IF(condition, fd, buf, size, btsr) \
if (condition) \
{ \
	btsr = read(fd, buf, size); \
	buf[btsr] = '\0'; \
}

# define BUF_SET(inp, i, start) \
while (inp[start]) \
{ \
	inp[i++] = inp[start++]; \
}

typedef struct variables
{
	size_t	i_1;
	size_t	i_2;
	size_t	i_3;
	size_t	i_4;
	size_t	b_len;
	size_t	r_len;
	ssize_t	btsr;
	size_t	read_if;
	int		out;
	char	*ret_str;
	char	*new_str;
}	t_variables;

char	*get_next_line(int fd);

#endif