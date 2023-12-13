#include "get_next_line.h"

#define BUF_SIZE 141

void	my_strcpy(char *src, char *dest)
{
	int	i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	main(void)
{
	int		fd = open("input3.txt", 'r');
	char	line_1[BUF_SIZE + 1];
	char	line_2[BUF_SIZE + 1];
	char	line_3[BUF_SIZE + 1];
	char	buffer[BUF_SIZE + 1];
	ssize_t	bytesread = 1;
	int	index_num = 0;
	int	index_sym = 0;
	
	bytesread = read(fd, line_1, BUF_SIZE);
	if (bytesread < 0)
		return (1);
	line_1[bytesread] = '\0';
	bytesread = read(fd, line_2, BUF_SIZE);
	if (bytesread < 0)
		return (1);
	line_2[bytesread] = '\0';
	bytesread = read(fd, line_3, BUF_SIZE);
	if (bytesread < 0)
		return (1);
	line_3[bytesread] = '\0';
	printf("%s\n%s\n%s\n", line_1, line_2, line_3);
	while ()
	{
		while ()
	}
	close(fd);
	return (0);
}
