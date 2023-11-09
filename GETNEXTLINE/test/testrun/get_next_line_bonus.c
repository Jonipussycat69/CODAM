/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:16:39 by jdobos            #+#    #+#             */
/*   Updated: 2023/11/09 12:16:40 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_buf(char *buf, char *line, size_t i, size_t j)
{
	const size_t	l_len = nl_count(line, 1);
	const size_t	b_len = nl_count(buf, 1);
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
	static char	buffer_array[1025][BUFFER_SIZE + 1];
	ssize_t		bytesread;
	char		*line;

	if (fd > 1024 || fd < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = get_buf(buffer_array[fd], line, 0, 0);
	if (nl_count(line, 0) != 0 || line == NULL)
		return (line);
	bytesread = 1;
	while (nl_count(line, 0) == 0 && line != NULL && bytesread > 0)
	{
		bytesread = read(fd, buffer_array[fd], BUFFER_SIZE);
		if (bytesread < 0)
			return (free_line(line));
		buffer_array[fd][bytesread] = '\0';
		line = get_buf(buffer_array[fd], line, 0, 0);
	}
	if (line && line[0] == '\0')
		line = free_line(line);
	return (line);
}
// SIGSEGV when buffer is 10000000 and fd is invalid multiple fd!
