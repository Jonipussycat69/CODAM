#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	int	i;
	
	i = 0;
	if (fd < 0)
		return (1);
	while (i++ < 7)
	{
		// printf("MAIN >> getting line\n");
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free_line(line);
		}
	}
	close(fd);
	printf("\n");
	return (0);
}
