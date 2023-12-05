/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:32:26 by jdobos            #+#    #+#             */
/*   Updated: 2023/12/05 19:06:03 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cpy_to_line(t_variables *v, char *buf)
{
	size_t	i;

	v->l_len = nl_len(v->line);
	v->b_len = nl_len(buf);
	if (v->b_len == 0)
		return (v->line);
	v->tmp_line = v->line;
	v->ret_line = (char *)malloc(v->l_len + v->b_len + 1);
	if (!v->ret_line)
		return (free_line(v->line));
	i = 0;
	while (i < v->l_len)
		v->ret_line[i++] = *(v->tmp_line++);
	while (i < v->b_len + v->l_len)
		v->ret_line[i++] = *(buf++);
	v->ret_line[i] = '\0';
	free_line(v->line);
	return (v->ret_line);
}

void	cpy_to_rem(char *rem, char *buf, size_t start)
{
	size_t	i;

	i = 0;
	while (buf[start])
		rem[i++] = buf[start++];
	rem[i] = '\0';
	return ;
}

void	buf_cat(t_variables *v, char *buf)
{
	size_t	i;
	size_t	cat_i;

	i = 0;
	cat_i = v->cat_len - BUFFER_SIZE;
	if (v->checkpoint == 0)
	{
		cat_i = v->cat_len - v->b_len;
		v->cat_line[v->cat_len] = '\0';
		v->checkpoint = 2;
		v->b_len = 0;
	}
	else
		v->rec--;
	while (i < v->cat_len)
		v->cat_line[cat_i++] = buf[i++];
	return ;
}

void	get_line(int fd, t_variables *v)
{
	char	buffer[BUFFER_SIZE + 1];

	if (v->error && v->btsr == BUFFER_SIZE)
	{
		v->btsr = read(fd, buffer, BUFFER_SIZE);
		if (v->btsr < 0)
			v->error = 0;
		if (v->btsr < 0)
			return ;
		buffer[v->btsr] = '\0';
		if (nl_check(buffer))
			v->b_len = nl_len(buffer);
		if (nl_check(buffer))
			cpy_to_rem(v->rem, buffer, v->b_len);
		else if (++v->rec)
			get_line(fd, v);
	}
	v->cat_len = (v->rec * BUFFER_SIZE) + v->b_len;
	if (v->error && v->checkpoint-- == 1)
		v->cat_line = (char *)malloc(v->cat_len + 1);
	if (v->error && v->cat_line == NULL)
		v->error = 0;
	if (v->error && v->rec >= 0)
		buf_cat(v, buffer);
	return ;
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE];
	t_variables	v;

	v.line = (char *)malloc(sizeof(char));
	if (v.line)
		v.line[0] = '\0';
	v.line = cpy_to_line(&v, remainder);	// REMAINDER NEEDS TO BE CLEANED!!! LEFTOFF!!!
	// printf("p1: %s\n",v.line);
	if (!v.line || nl_check(v.line))
		return (v.line);
	// printf("p2: %s\n",v.line);
	v.rec = 0;
	v.checkpoint = 1;
	v.error = 1;
	v.b_len = BUFFER_SIZE;
	v.btsr = BUFFER_SIZE;
	v.rem = remainder;
	get_line(fd, &v);
	if (v.error == 0)
		return (free_line(v.line));
	v.line = cpy_to_line(&v, v.cat_line);
	// printf("p3: %s\n",v.line);
	free(v.cat_line);
	if (!v.line || v.line[0] == '\0')
		return (NULL);
	return (v.line);
}

//WORKING!!! NOW TEST!!!

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	int	i;
	
	i = 0;
	// printf("MAIN >> getting line\n");
	if (fd < 0)
		return (1);
	// printf("MAIN >> getting line\n");
	while (i++ < 8)
	{
		// printf("MAIN >> getting line\n");
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free_line(line);
		}
		else
			break ;
	}
	close(fd);
	printf("\n");
	return (0);
}
