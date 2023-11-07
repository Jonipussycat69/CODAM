#include "get_next_line.h"

void	*free_line(char *line)
{
	if (line != NULL)
		free(line);
	return (NULL);
}

ssize_t	nl_len(char *str, int *nl)
{
	ssize_t	i;
	
	if (!str)
	{
		*nl = 0;
		return (0);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*nl = 1;
		return (i + 1);
	}
	else
	{
		*nl = 0;
		return (i);
	}
}

char	*clean(char *str, ssize_t end, int type)
{
	size_t	i;

	i = 0;
	if (type == 1)
	{
		while (str[end])
			str[i++] = str[end++];
		while (i < BUFFER_SIZE)
			str[i++] = '\0';
	}
	else if (type == -1)
	{
		while (str[end])
			str[end++] = '\0';
	}
	else
	{
		while (i < end)
			str[i++] = '\0';
	}
	return (NULL);
}

char	*buf_line(char *line, char *t_line, char *buf, int *nl)
{
	char	*result;
	const size_t	l_len = nl_len(line, nl);
	const size_t	b_len = nl_len(buf, nl);
	size_t	i;

	result = (char *)malloc(l_len + b_len + 1);
	if (!(result))
		return (free_line(line));
	i = 0;
	while (i < l_len)
		result[i++] = *(t_line++);
	while (i - l_len < b_len)
		result[i++] = *(buf++);
	result[i] = '\0';
	free_line(line);
	return (result);
}

char	*buf_read(char *line, char *buffer, int fd, int *nl)
{
	ssize_t	bytesread;

	while (*nl == 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (NULL);
		buffer[bytesread] = '\0';
		line = buf_line(line, line, buffer, nl);
		if (line == NULL)
			return (NULL);
		nl_len(buffer, nl);
	}
	clean(buffer, nl_len(buffer, nl), -1);
	return (line);
}

char	*get_next_line(int fd)
{
	size_t	bsize;
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		nl;

	nl = 0;
	line = NULL;
	while (nl == 0)
	{
		nl_len(buffer, &nl);
		if (nl == 1)
		{
			line = buf_line(line, line, buffer, &nl);
			if (line == NULL)
				return (NULL);
			clean(buffer , nl_len(buffer, &nl), 1);
		}
		else
			line = buf_read(line, buffer, fd, &nl);
		if (!line)
			return (NULL);
		nl_len(line, &nl);
	}
	return (line);
}
// UNDEFINED BEHAVIOUR!
// MAIN--------------------

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
		// printf("MAIN >> getting line\n");
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
