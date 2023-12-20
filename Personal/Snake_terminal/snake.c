#include "snake.h"

int	screen[WINDOW_Y][WINDOW_X];

void	set_screen(void)
{
	int	x = 0;
	int	y = 0;

	while (y < WINDOW_Y)
	{
		while (x < WINDOW_X)
		{
			if (x == 0 || y == 0 || WINDOW_X - x == 1 || WINDOW_Y - y == 1)
				screen[y][x] = 1;
			else
				screen[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	print_screen(void)
{
	return ;
}

void	clear_screen(void)
{
	return ;
}

int	refresh(void)// LEFTOFF look at structs in header!
{
	return (0);
}

int	snake_main(void)
{
	printf("Snake\n");
	set_screen();
	refresh();
	printf("Exit\n");
}