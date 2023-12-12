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

// int	get_boxes(char *buf)
// {
// 	static int i = 0;
// 	int			temp_num = 0;
// 	int			col = 0;
// 	size_t	red = 0;
// 	size_t	green = 0;
// 	size_t	blue = 0;
// 	int		begin;

// 	while (buf[i] != ':')
// 		i++;
// 	i += 2;
// 	if (i >= strlen(buf))
// 			return (0);
// 	begin = i;
// 	printf("begin: %i\n", begin);
// 	// printf("begin index: %.10s\n", buf + begin);
// 	while (buf[i] && (i == begin || buf[i] != '\n'))
// 	{
// 		temp_num = 0;
// 		while (!isalpha(buf[i]))
// 		{
// 			while (isdigit(buf[i]))
// 				temp_num = temp_num * 10 + buf[i++] - '0';
// 			i++;
// 		}
// 		if (buf[i] == 'r')
// 		{
// 			red = temp_num;
// 			i += 3;
// 		}
// 		else if (buf[i] == 'g')
// 		{
// 			green = temp_num;
// 			i += 5;
// 		}
// 		else if (buf[i] == 'b')
// 		{
// 			blue = temp_num;
// 			i += 4;
// 		}
// 		if (red > 0)
// 			printf("red: %zu\n", red);
// 		if (green > 0)
// 			printf("green: %zu\n", green);
// 		if (blue > 0)
// 			printf("blue: %zu\n", blue);
// 		// printf("red: %zu, green: %zu, blue: %zu\n", red, green, blue);
// 		if (red > RED || green > GREEN || blue > BLUE)
// 			return (1);
// 		red = 0;
// 		green = 0;
// 		blue = 0;
// 		if (buf[i] == '\n')
// 			break ;
// 		if (buf[i] == ';')
// 			i += 1;
// 		if (buf[i] == ',')
// 			i += 2;
// 		else
// 			i++;
// 	}
// 	if (red == 0 && green == 0 && blue == 0 && buf[i] == '\0')
// 		return (0);
// 	return (2);
// }

int	get_boxes(char *buf)
{
	static int	i = 0;
	int			temp_num = 0;
	int			col = 0;
	int			begin;

	if (buf[i] == '\0')
		return (0);
	while (buf[i] && buf[i] != ':')
		i++;
	i += 2;
	if (i >= strlen(buf))
			return (0);
	begin = i;
	// printf("begin: %i\n", begin);
	// printf("begin index: %.10s\n", buf + begin);
	while (buf[i] && (i == begin || buf[i] != '\n'))
	{
		if (isdigit(buf[i]))
		{
			while (isdigit(buf[i]))
				temp_num = temp_num * 10 + (buf[i++] - '0');
		}
		if (buf[i] == 'r')
		{
			// printf(" red	%d\n", temp_num);
			if (temp_num > RED)
				return (1);
			temp_num = 0;
			i += 2;
		}
		if (buf[i] == 'g')
		{
			// printf(" green	%d\n", temp_num);
			if (temp_num > GREEN)
				return (1);
			temp_num = 0;
			i += 4;
		}
		if (buf[i] == 'b')
		{
			// printf(" blue	%d\n", temp_num);
			if (temp_num > BLUE)
				return (1);
			temp_num = 0;
			i += 3;
		}
		i++;
	}
	return (2);
}

int	main(void)
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		game = 1;
	int		check = 0;
	size_t	sum = 0;

	fd = open("input2.txt", O_RDONLY);
	if (read(fd, buffer, BUF_SIZE) < 0)
		return (1);
	// printf("%s\n", buffer);
	while (game >= 0)
	{
		check = get_boxes(buffer);
		printf("check: %d, game: %d\n\n", check, game);
		if (check == 0)
			break ;
		if (check == 2)
			sum += game;
		game++;
	}
	printf("SUM: %zu\n", sum);
	close(fd);
	return (0);
}
