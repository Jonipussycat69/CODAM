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

int	ft_get_num(char *line, int begin, int end)
{
	int	num = 0;

	while (begin < end)
		num = num * 10 + (line[begin++] - '0');
	return (num);
}

int	ft_sym(char *l1, char *l2, char *l3, int begin, int end)
{
	int	i = begin - 1;

	while (l1 && l1[i] && i <= end)
	{
		if (!(isdigit(l1[i]) || l1[i] == '.' || l1[i] != '\n'))
			return (ft_get_num(l2, begin, end));
		i++;
	}
	i = begin - 1;
	while (l3 && l3[i] && i <= end)
	{
		if (!(isdigit(l3[i]) || l3[i] == '.' || l3[i] != '\n'))
			return (ft_get_num(l2, begin, end));
		i++;
	}
	return (0);
}

int	main(void)
{
	int		fd = open("input3.txt", 'r');
	char	line_1[BUF_SIZE + 1];
	char	line_2[BUF_SIZE + 1];
	char	line_3[BUF_SIZE + 1];
	ssize_t	bytesread = 0;
	int		i_b = 0;
	int		i_num = 0;
	int		i_sym = 0;
	int		sum = 0;
	
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
	printf("~ here\n");
	while (line_1[i_num])
	{
		if (isdigit(line_1[i_num]))
		{
			i_b = i_num;
			while (line_1[i_num] && isdigit(line_1[i_num]))
				i_num++;
			sum += ft_sym(NULL, line_1, line_2, i_b, i_num);
		}
		else
			i_num++;
	}
	printf("~ here\n");
	while (bytesread != 0)
	{
		i_num = 0;
		while (line_2[i_num])
		{
			if (isdigit(line_2[i_num]))
			{
				i_b = i_num;
				while (isdigit(line_2[i_num]))
					i_num++;
				sum += ft_sym(line_1, line_2, line_3, i_b, i_num);
			}
			i_num++;
		}
		my_strcpy(line_2, line_1);
		my_strcpy(line_3, line_2);
		bytesread = read(fd, line_3, BUF_SIZE);
		if (bytesread < 0)
			return (1);
		line_3[bytesread] = '\0';
	}
	i_num = 0;
	while (line_2[i_num])
	{
		if (isdigit(line_2[i_num]))
		{
			i_b = i_num;
			while (isdigit(line_2[i_num]))
				i_num++;
			sum += ft_sym(line_1, line_2, NULL, i_b, i_num);
		}
		i_num++;
	}
	printf(" line 1: %s\n line 2: %s\n line 3: %s\n", line_1, line_2, line_3);
	printf("SUM: %d\n", sum);
	close(fd);
	return (0);
} // ANSWER TOO LOW!!!!!!!!!!!!!!
