#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free_line(line);
	}
	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free_line(line);
	}
	close(fd);
	printf("\n");
	return (0);
}
