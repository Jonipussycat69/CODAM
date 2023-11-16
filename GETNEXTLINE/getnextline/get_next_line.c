/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 19:43:24 by joni          #+#    #+#                 */
/*   Updated: 2023/11/16 12:02:46 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buf(char *buf, char *line, size_t i, size_t j)
{
	const size_t	l_len = nl_len(line);
	const size_t	b_len = nl_len(buf);
	char			*new_line;
	char			*temp_line;

	temp_line = line;
	new_line = (char *)malloc(l_len + b_len + 1);
	if (!new_line)
		return (free_line(line));
	while (i < l_len)
		new_line[i++] = *(temp_line++);
	while (j < b_len)
		new_line[i++] = buf[j++];
	new_line[i] = '\0';
	free_line(line);
	i = 0;
	while (buf[j])
		buf[i++] = buf[j++];
	buf[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytesread;
	char		*line;

	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = get_buf(buffer, line, 0, 0);
	if (nl_check(line) != 0 || line == NULL)
		return (line);
	bytesread = 1;
	while (nl_check(line) == 0 && line != NULL && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free_line(line));
		buffer[bytesread] = '\0';
		line = get_buf(buffer, line, 0, 0);
	}
	if (line && line[0] == '\0')
		line = free_line(line);
	return (line);
}
