#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

#define BUF_SIZE 100000



#define RED 12
#define GREEN 13
#define BLUE 14

int	get_boxes(char *buf)
{
	static int i = 0;
	int			temp_num = 0;
	int			col = 0;
	size_t	red = 0;
	size_t	green = 0;
	size_t	blue = 0;
	int		begin;

	begin = i;
	while (buf[i] && (i == begin || buf[i - 1] != '\n'))
	{
		while (!isalpha(buf[i]))
		{
			if (isdigit(buf[i]))
				temp_num = buf[i] - '0';
			i++;
		}
		if (buf[i] == 'r')
		{
			red += temp_num;
			i += 2;
		}
		else if (buf[i] == 'g')
		{
			green += temp_num;
			i += 4;
		}
		else if (buf[i] == 'b')
		{
			blue += temp_num;
			i += 3;
		}
		if (red > RED || green > GREEN || blue > BLUE)
			return (1);
		i++;
		if (buf[i] == ';')
		{
			red = 0;
			green = 0;
			blue = 0;
		}
	}
	if (red == 0 && green == 0 && blue == 0 && buf[i] == '\0')
		return (0);
	if (red <= RED && green <= GREEN && blue <= BLUE)
		return (2);
	return (1);
}

int	main(void)
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		game = 1;
	int		check = 0;
	size_t	sum = 0;

	fd = open("input.txt", O_RDONLY);
	if (read(fd, buffer, BUF_SIZE) < 0)
		return (1);
	// printf("%s\n", buffer);
	while (game >= 0)
	{
		check = get_boxes(buffer);
		printf("check: %d\n", check);
		if (check == 0)
			break ;
		if (check == 2)
			sum += game;
		game++;
	}
	printf("%zu\n", sum);
	close(fd);
	return (0);
}
