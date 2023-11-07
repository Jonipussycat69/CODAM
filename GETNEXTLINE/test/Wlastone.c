/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Wlastone.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 16:52:50 by jdobos        #+#    #+#                 */
/*   Updated: 2023/11/07 19:20:25 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_line(char *line, int type)
{
	if (type == 1)
	{
		if (line && line[0] == '\0')
		{
			free(line);
			return (NULL);
		}
		return (line);
	}
	if (line != NULL && type == 0)
		free(line);
	return (NULL);
}

size_t	nl_count(char *str, int type)
{
	size_t	nl;

	if (!str)
		return (0);
	nl = 0;
	if (type == 1)
	{
		while (str[nl] && (nl == 0 || str[nl - 1] != '\n'))
			nl++;
		return (nl);
	}
	while (*str)
	{
		if (*str == '\n')
			nl++;
		str++;
	}
	return (nl);
}

char	*get_buf(char *buf, char *line, size_t i, size_t j)
{
	const size_t	l_len = nl_count(line, 1);
	const size_t	b_len = nl_count(buf, 1);
	char			*new_line;
	char			*temp_line;

	temp_line = line;
	new_line = (char *)malloc(l_len + b_len + 1);
	if (!new_line)
		return (free_line(line, 0));
	while (i < l_len)
		new_line[i++] = *(temp_line++);
	while (j < b_len)
		new_line[i++] = buf[j++];
	new_line[i] = '\0';
	free_line(line, 0);
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
	if (nl_count(line, 0) != 0 || line == NULL)
		return (line);
	bytesread = 1;
	while (nl_count(line, 0) == 0 && line != NULL && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free_line(line, 0));
		buffer[bytesread] = '\0';
		line = get_buf(buffer, line, 0, 0);
	}
	line = free_line(line, 1);
	return (line);
}

//WORKING!!! NOW TEST!!!

// int	main(void)
// {
// 	char	*line;
// 	int	fd = open("test.txt", O_RDONLY);
// 	int	i;
	
// 	i = 0;
// 	if (fd < 0)
// 		return (1);
// 	while (i++ < 8)
// 	{
// 		// printf("MAIN >> getting line\n");
// 		line = get_next_line(fd);
// 		if (line)
// 		{
// 			printf("%s", line);
// 			free_line(line);
// 		}
// 	}
// 	close(fd);
// 	printf("\n");
// 	return (0);
// }
