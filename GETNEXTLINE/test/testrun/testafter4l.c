#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	r = (char *) malloc(j * sizeof(char));
	if (!(r))
		return (NULL);
	j = ft_strlen(s1);
	while (i < j)
	{
		r[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
		r[j++] = s2[i++];
	r[j] = '\0';
	return (r);
}

int	nl_check(char *buffer)
{
	int	i;
	
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (i < ft_strlen(buffer) - 1)
		return (i + 1);
	return (0);
}

void	*free_line(char *line)
{
	if (line)
		free(line);
	return (NULL);
}

char	*create_line(char *line, char *buffer)
{
	
}

char	*get_next_line(int fd)
{
	char	*file_to_read[1024];//bonus
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	static char	remain[BUFFER_SIZE];
	ssize_t	bytesread;
	
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (NULL);
		buffer[bytesread] = '\0';
		line = create_line(line, buffer);
		if (line == NULL)
			return (free_line(line));
		if (nl_check)
			ft_strlcpy(remain, buffer, nl_check);//does not work
	}
}