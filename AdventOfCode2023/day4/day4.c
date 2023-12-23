#include "get_next_line.h"
#include <stdbool.h>

int	main(void)
{
	char	*line = NULL;
	int		i = 0;
	int		w = 0;
	bool	gotnum = 0;
	int		fd = open("input.txt", O_RDONLY);
	int		winarr[10];
	int		wincount = 0;
	int		num;
	unsigned int	out = 0;
	unsigned int	linenum = 0;
	
	printf("START\n");
	while (1)
	{
		printf("START 2\n");
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s\n", line);
		w = 0;
		i = 0;
		wincount = 0;
		gotnum  = 0;
		while (line[i] && line[i] != ':')
			i++;
		while (line[i] && line[i] != '|')
		{
			if (line[i] == ' ')
			{
				i++;
				if (gotnum && w < 9)
					w++;
				gotnum = 0;
			}
			else if (isdigit(line[i]))
			{
				gotnum = 1;
				num = 0;
				while (isdigit(line[i]))
					num = num * 10 + (line[i++] - '0');
			}
			else
				i++;
			if (gotnum)
				winarr[w] = num;
		}
		printf("START 3\n");
		linenum = 0;
		gotnum  = 0;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] == ' ')
			{
				i++;
				gotnum = 0;
			}
			else if (isdigit(line[i]))
			{
				gotnum = 1;
				num = 0;
				while (isdigit(line[i]))
					num = num * 10 + (line[i++] - '0');
			}
			else
				i++;
			if (gotnum)
			{
				w = 0;
				while (w < 9)
				{
					if (num == winarr[w])
					{
						wincount++;
						break ;
					}
					w++;
				}
			}
		}
		printf("START 4\n");
		if (wincount > 0)
		{
			linenum = 1;
			while (wincount > 1)
			{
				linenum = linenum * 2;
				wincount--;
			}
			out += linenum;
		}
		free(line);
		printf("~ %u\n", linenum);
	}
	printf("END OUT: %u\n", out); //12005 IS TOO LOW!!!!!!!!
	close(fd);
	return (0);
}