#include "snake.h"

int	main(void)
{
	snake_main();
	return (0);
}

int main(void)
{
	// Set stdin to non-blocking mode
	int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

	char input;
	int bytesRead;

	while (1) {
		// Attempt to read from stdin
		bytesRead = read(STDIN_FILENO, &input, 1);

		if (bytesRead > 0) {
			// Process the input
			printf("Read: %c\n", input);
		} else {
			// No input available, continue with other tasks or sleep
			usleep(100000);  // Sleep for 100 milliseconds (adjust as needed)
		}
	}

	return 0;
}
