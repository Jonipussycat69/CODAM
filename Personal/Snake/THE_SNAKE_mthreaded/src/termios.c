#include "../term_snake.h"

struct termios	orig_termios;

void disableRawMode()
{
	tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios); // Restore original terminal settings
}

void enableRawMode()
{
	struct termios raw;
	tcgetattr(STDIN_FILENO, &orig_termios); // Get current terminal attributes
	raw = orig_termios;
	raw.c_lflag &= ~(ECHO | ICANON); // Disable echo and canonical mode
	tcsetattr(STDIN_FILENO, TCSANOW, &raw); // Apply raw mode settings
	atexit(disableRawMode); // Ensure raw mode is disabled on exit
}
