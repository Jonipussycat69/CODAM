#include "get_next_line.h"

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

size_t	str_cpy(char *dest, char *src, size_t start)
{
	size_t	i;

	i = 0;
	while (src[start])
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (nl_len(src));
}

void	*free_line(char *line)
{
	if (line)
		free(line);
	return (NULL);
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

char	*rem_line(char *line, char *src, size_t end)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (end == 0)
		return (NULL);
	result = (char *) malloc(nl_len(line) + end + 1);
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
	while (i < end)
		result[j++] = src[i++];
	result[j] = '\0';
	free_line(line);
	return (result);
}

char	*read_line(char *line, char *remain, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytesread;
	size_t	i;

	bytesread = BUFFER_SIZE;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free_line(line));
		buffer[bytesread] = '\0';
		if (bytesread == 0 && i == 0)
			return (NULL);
		line = create_line(line, buffer, bytesread);
		if (line == NULL)
			return (NULL);
		if (buffer[nl_len(buffer)] == '\n')
		{
			str_cpy(remain, buffer, nl_len(buffer) + 1);
			break ;
		}
		i++;
	}
	return (line);
}

char	*rem_clean(char *line, char *rem, size_t end)
{
	size_t	i;

	i = 0;
	while (rem[end])
		rem[i++] = rem[end++];
	rem[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	remain[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (remain[nl_len(remain)] == '\n')
	{
		// printf("\n>> GNL remain begin: %s<<\n", remain);
		line = rem_line(line, remain, nl_len(remain) + 1);
		return (rem_clean(line, remain, nl_len(remain) + 1));
	}
	line = create_line(line, remain, BUFFER_SIZE);
	line = read_line(line, remain, fd);
	return (line);
}

// MAIN-----------------------------

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	int	i;
	
	i = 0;
	if (fd < 0)
		return (1);
	while (i++ < 7)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free_line(line);
		}
	}
	close(fd);
	printf("\n");
	return (0);
}