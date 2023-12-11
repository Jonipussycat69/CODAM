#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

#define BUF_SIZE 999999

void	get_digit(char c, bool *first_num, int *num_1, int *num_2)
{
	if (c == '0')
		return ;
	if (*first_num)
	{
		*num_1 = c - 48;
		*first_num = 0;
	}
	*num_2 = c - 48;
	return ;
}

size_t	get_word(char *buffer, size_t i, bool *first, int *num_1, int *num_2)
{
	const char	arr[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int			j;
	int			num;
	int			start;

	num = 1;
	start = i;
	while (arr[num])
	{
		j = 0;
		while (arr[num][j] && arr[num][j++] == buffer[i])
			i++;
		if (arr[num][j] == '\0')
			break ;
		i = start;
		num++;
	}
	// printf("num = %d\n", num);
	if (num >= 10)
	{
		// printf("num 11");
		return (i);
	}
	if (*first)
	{
		*num_1 = num;
		*first = 0;
	}
	*num_2 = num;
	return (i - 1);
}

int	get_num(char *buffer)
{
	int				num_1;
	int				num_2;
	int				begin;
	bool			first_num;
	static size_t	i = 0;

	num_1 = -1;
	num_2 = -1;
	first_num = 1;
	begin = i;
	// printf("Buffer: %c, i: %zu\n", buffer[i], i);
	while (buffer[i] && (i == begin || buffer[i - 1] != '\n'))
	{
		if (isdigit(buffer[i]))
			get_digit(buffer[i], &first_num, &num_1, &num_2);
		else if (buffer[i] == 'o' || buffer[i] == 'e' || buffer[i] == 's' || buffer[i] == 'f' || buffer[i] == 't' || buffer[i] == 'z' || buffer[i] == 'n')
			i = get_word(buffer, i, &first_num, &num_1, &num_2);
		i++;
	}
	// printf("Buffer: %c, i: %zu\n", buffer[i], i);
	if (num_1 == -1)
		return (-1);
	return (num_1 * 10 + num_2);
}

int	main(void)
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		num;
	size_t	coordinate = 0;

	fd = open("input.txt", O_RDONLY);
	if (read(fd, buffer, BUF_SIZE) < 0)
		return (1);
	num = 1;
	while (num > 0)
	{
		num = get_num(buffer);
		// printf("%d\n", num);
		if (num < 0)
			break ;
		coordinate += num;
	}
	printf("%zu\n", coordinate);
	close(fd);
	return (0);
}
