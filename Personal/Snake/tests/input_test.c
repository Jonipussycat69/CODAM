#include "tests.h"

int	test_inp(int max_iter)
{
	int	i = 0;
	int	bytesRead = 0;
	char	input;
	int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
	
	while (i++ < max_iter)
	{
		bytesRead = read(STDIN_FILENO, &input, 1);
		// Still have to press enter, weird undefined behaveour
		usleep(1000000);
		printf("iteration: %d -> ", i);
		printf("%c | %d\n", input, input);
	}
	return (0);
}

int	main(void)
{
	test_inp(100);
	return (0);
}
