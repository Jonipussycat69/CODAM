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

char	*str_chr(const char *str, int c)
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

void	*cal(size_t size)
{
	void	*ptr;
	void	*tempptr;

	ptr = (void *)malloc(size);
	if (ptr)
	{
		tempptr = ptr;
		while (size > 0)
		{
			*(unsigned char *)tempptr = '\0';
			tempptr++;
			size--;
		}
	}
	return (ptr);
}

char	*buf_clean(char *buf, ssize_t end, int type)
{
	size_t	i;

	i = 0;
	if (type == 1)
	{
		while (buf[end])
			buf[i++] = buf[end++];
		while (i < BUFFER_SIZE)
			buf[i++] = '\0';
	}
	else
	{
		while (end < BUFFER_SIZE)
			buf[end++] = '\0';
	}
	return (NULL);
}

char	*buf_line(char *line, char *t_line, char *buf)
{
	char	*result;
	const size_t	l_len = nl_len(line);
	const size_t	b_len = nl_len(buf);
	size_t	i;

	result = (char *)cal(l_len + b_len + 2);//maybe too big malloc?
	if (!(result))
		return (free_line(line));
	i = 0;
	while (i < l_len)
		result[i++] = *(t_line++);
	while (i - l_len < b_len + 1)//maybe overflow?
		result[i++] = *(buf++);
	free_line(line);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytesread;

	bytesread = -1;
	line = NULL;
	while (nl_check(buffer) == 0)
	{
		line = buf_line(line, line, buffer);//double frees here
		if (line == NULL)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free_line(line));
		buf_clean(buffer, bytesread, 0);
		if (bytesread == 0)
			break ;
	}
	if (bytesread == -1)
	{
		line = buf_line(line, line, buffer);
		buf_clean(buffer, nl_len(buffer) + 1, 1);
	}
	return (line);
}

// FREES POINTER THAT WAS NOT ALLOCATED WHEN ITERATING MORE TIMES OVER ONE LINE!
// MAIN-----------------------------

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	int	i;
	
	i = 0;
	if (fd < 0)
		return (1);
	while (i++ < 6)
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