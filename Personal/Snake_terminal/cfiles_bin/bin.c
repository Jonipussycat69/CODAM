#define WINDOW_X 1
#define WINDOW_Y 1

int	screen[WINDOW_Y][WINDOW_X];

void	set_screen(void)
{
	int	x = 0;
	int	y = 0;

	while (y < WINDOW_Y)
	{
		x = 0;
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
	return ;
}

int	loop(main_variables *mv, screen_prop *sp)
{
	int	input = 1;
	
	while (input != quit)
	{
		input = getchar();
		input = inputcheck(input, mv);
		if (input == quit)
			break ;
		refresh_snake(input, mv, sp);
		get_terminal_size(sp);
		mv->iter++;
		clear_screen(sp);
		print_screen(mv, sp);
	}
	return (0);
}
