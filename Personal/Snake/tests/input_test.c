// #include "tests.h"

// int	test_inp(int max_iter)
// {
// 	int	i = 0;
// 	int	bytesRead = 0;
// 	char	input;
// 	int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
// 	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
	
// 	while (i++ < max_iter)
// 	{
// 		bytesRead = read(STDIN_FILENO, &input, 1);
// 		// Still have to press enter, weird undefined behaveour
// 		usleep(1000000);
// 		printf("iteration: %d -> ", i);
// 		printf("%c | %d\n", input, input);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	test_inp(100);
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <termios.h>
#include <string.h>

struct termios orig_termios;

void enableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &orig_termios);
    raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);  // Disable echo and canonical mode
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void* readInput(void* arg) {
    char c;
    while (1) {
        if (read(STDIN_FILENO, &c, 1) == 1) {
            if (c == 'q') break;  // Exit on 'q'
            printf("Read: %c\n", c);
            fflush(stdout);  // Ensure output is displayed immediately
        }
    }
    return NULL;
}

void* writeOutput(void* arg) {
    while (1) {
		write(STDOUT_FILENO, "\033[2J", 4);
		write(STDOUT_FILENO, "\033[H", 3);
        printf("Writing...");
        fflush(stdout);
		write(STDOUT_FILENO, "Hello, World!\n", 14);
        usleep(500000);  // Wait for 0.5 seconds
    }
    return NULL;
}

int main() {
    enableRawMode();  // Enable raw mode for terminal

    pthread_t readerThread, writerThread;

    // Create threads for reading and writing
    pthread_create(&readerThread, NULL, readInput, NULL);
    pthread_create(&writerThread, NULL, writeOutput, NULL);

    // Wait for reader thread to finish
    pthread_join(readerThread, NULL);

    // Cleanup
    disableRawMode();
    pthread_cancel(writerThread);  // Stop the writer thread if still running
    pthread_join(writerThread, NULL);

    return 0;
}
