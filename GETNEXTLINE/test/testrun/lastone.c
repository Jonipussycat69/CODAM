#include "get_next_line.h"

void	*free_line(char *line)
{
	if (line != NULL)
		free(line);
	return (NULL);
}

size_t	nl_count(char *str)
{
	size_t	nl;

	if (!str)
		return (0);
	nl = 0;
	while (*str)
	{
		if (*str == '\n')
			nl++;
		str++;
	}
	return (nl);
}

char	*get_buf(char *buf, char *line, char *t_line, size_t i, size_t j)
{
	size_t	l_len;
	size_t	b_len;
	char	*new_line;

	b_len = 0;
	while (buf[b_len] && buf[b_len - 1] != '\n')
		b_len++;
	l_len = 0;
	while (line[l_len])
		l_len++;
	new_line = (char *)malloc(l_len + b_len + 1);
	if (!new_line)
		return (free_line(line));
	while (i < l_len)
		new_line[i++] = *(t_line++);
	while (j < b_len)
		new_line[i++] = buf[j++];
	new_line[i] = '\0';
	free_line(line);
	i = 0;
	while (buf[b_len])
		buf[i++] = buf[b_len++];
	buf[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytesread;
	char		*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = get_buf(buffer, line, line, i, j);
	if (nl_count(line) != 0 || line == NULL)
		return (line);
	while (nl_count(line) == 0 && line != NULL && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free_line(line));
		buffer[bytesread] = '\0';
		line = get_buf(buffer, line, line, i, j);
	}
	return (line);
}

//WORKING!!! NOW TEST!!!

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	int	i;
	
	i = 0;
	if (fd < 0)
		return (1);
	while (i++ < 8)
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
