#include "get_next_line.h"

void	*free_line(char *line)
{
	if (line != NULL)
		free(line);
	return (NULL);
}

size_t	nl_len(char *str)
{
	size_t	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

int	nl_check(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*create_line(char *line, char *src, ssize_t bytesread)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	slen;

	slen = nl_len(src);
	if (nl_len(src) < bytesread)
		slen = nl_len(src) + 1;
	result = (char *) malloc(nl_len(line) + slen + 1);
	if (!(result))
		return (free_line(line));
	j = nl_len(line);
	i = 0;
	while (i < j)
	{
		result[i] = line[i];
		i++;
	}
	i = 0;
	while (i < slen)
		result[j++] = src[i++];
	result[j] = '\0';
	free_line(line);
	return (result);
}

char	*read_line(int fd, ssize_t bytesread, char *line, char *buffer)
{
	bytesread = BUFFER_SIZE;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free_line(line));
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		line = create_line(line, buffer, bytesread);
		if (line == NULL)
			return (NULL);
		if (buffer[nl_len(buffer)] == '\n')
			break ;
	}
	return (line);
}

int	buf_clean(char *buf, size_t end)
{
	size_t	i;

	i = 0;
	if (buf[end] == '\n')
		end++;
	while (buf[end])
		buf[i++] = buf[end++];
	buf[i] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	ssize_t	bytesread;

	line = NULL;
	bytesread = 1;
	line = create_line(line, buffer, bytesread);
	buf_clean(buffer, nl_len(buffer));
	if (nl_check(line) == 0)
	{
		line = read_line(fd, bytesread, line, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}