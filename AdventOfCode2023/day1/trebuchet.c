#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

#define BUF_SIZE 999999

int	get_num(char *buffer)
{
	int				num_1;
	int				num_2;
	bool			first_num;
	static size_t	i = 0;

	num_1 = 0;
	num_2 = 0;
	first_num = 1;
	while (buffer[i])
	{
		if (isdigit(buffer[i]))
		{
			if (first_num)
				num_1 = buffer[i] - 48;
			else
				num_2 = buffer[i] - 48;
			first_num = 0;
		}
	}
}

int	main(void)
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		num;
	size_t	coordinate;

	fd = open("input.txt", O_RDONLY);
	if (read(fd, buffer, BUF_SIZE) < 0)
		return (1);
	while (buffer)
	{
		num = get_num(buffer);
		if (num < 0)
			break ;
		coordinate += num;
	}
	printf("%zu\n", coordinate);
	close(fd);
	return (0);
}
