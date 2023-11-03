#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	if ((line = get_next_line(fd)) != NULL)
		printf("next line: %s\n", line);
	free(line);
	close(fd);
	return (0);
}
