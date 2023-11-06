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

int	buf_clean(char *buf, int end)
{
	int	i;

	i = 0;
	if (buf[end] == '\n')
	end++;
	while (buf[end])
		buf[i++] = buf[end++];
	buf[i] = '\0';
	return (1);
}

char	*create_line(char *line, char *src)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *) malloc(nl_len(line) + nl_len(src) + 2);//maybe too big malloc?
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
	while (i < nl_len(src) + 1)//maybe overflow?
		result[j++] = src[i++];
	result[j] = '\0';
	free_line(line);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytesread;

	bytesread = -1;
	while (nl_check(buffer) == 0)//buffer undefined??
	{
		line = create_line(line, buffer);
		if (line == NULL)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free_line(line));
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
	}
	if (bytesread == -1)
	{
		line = create_line(line, buffer);
		buf_clean(buffer, nl_len(buffer) + 1);
	}
	return (line);
}