#include "snake.h"

void	get_terminal_size(screen_prop *sp)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	sp->terminal_height = w.ws_row - OFFSET_Y;
	sp->terminal_width = w.ws_col - OFFSET_X;
	return ;
}

void	set_variables(main_variables *mv, screen_prop *sp)
{
	int	i = 0;
	int	pos = 2;

	mv->last_inp = 'w';
	mv->iter = 0;
	sp->candy[0] = 0;
	sp->candy[1] = 0;
	sp->snake_len = STARTING_LEN;
	while (i < MAX_LEN)
	{
		sp->pix_new[0][i] = 0;
		sp->pix_old[0][i] = 0;
		i++;
	}
	i = 0;
	while (i < MAX_LEN)
	{
		sp->pix_new[1][i] = 0;
		sp->pix_old[1][i] = 0;
		i++;
	}
	i = STARTING_LEN;
	// defining the strating snake \/
	while (i > 0)
		sp->pix_new[1][i--] = pos++;
	i = STARTING_LEN;
	while (i > 0)
		sp->pix_old[0][i--] = OFFSET_Y;
	return ;
}

void	print_screen(main_variables *mv, screen_prop *sp)
{
	int	x = 0;
	int	y = 0;
	int	i;

	while (y < sp->terminal_height)
	{
		x = 0;
		while (x < sp->terminal_width)
		{
			if (x == 0 || y == 0 || sp->terminal_width - x == 1 || sp->terminal_height - y == 1)
				printf("?");
			else if (sp->candy[0] == y && sp->candy[1] == x)
				printf("x");
			else
				printf(" ");
			i = 0;
			while (i < sp->snake_len)
			{
				if (sp->pix_new[0][i] == y && sp->pix_new[1][i] == x)
				{
					printf("%c", 8);
					if (i == 0)
						printf("O");
					else
						printf("o");
				}
				i++;
			}
			x++;
		}
		printf("\n");
		y++;
	}
	return ;
}

// void	clear_screen(screen_prop *sp)
// {
// 	int	i = 0;

// 	while (i++ < sp->terminal_width * sp->terminal_height)
// 		printf("%c", 8);
// 	return ;
// }

int	refresh_snake(main_variables *mv, screen_prop *sp)
{
	int	i = 0;
	if (mv->last_inp == 'a')
	{
		if (sp->pix_old[0][0] - 1 == 0)
			sp->pix_new[0][0] = sp->terminal_width - 1;
		else
			sp->pix_new[0][0] = sp->pix_old[0][0] - 1;
	}
	else if (mv->last_inp == 's')
	{
		if (sp->pix_old[1][0] - 1 == 0)
			sp->pix_new[1][0] = sp->terminal_height - 1;
		else
			sp->pix_new[1][0] = sp->pix_old[1][0] - 1;
	}
	else if (mv->last_inp == 'd')
	{
		if (sp->pix_old[0][0] + 1 == sp->terminal_width)
			sp->pix_new[0][0] = 1;
		else
			sp->pix_new[0][0] = sp->pix_old[0][0] + 1;
	}
	else
	{
		if (sp->pix_old[1][0] + 1 == sp->terminal_height)
			sp->pix_new[1][0] = 1;
		else
			sp->pix_new[1][0] = sp->pix_old[1][0] + 1;
	}
	while (i < sp->snake_len - 1)
	{
		sp->pix_new[0][i + 1] = sp->pix_old[0][i];
		i++;
	}
	i = 0;
	while (i < sp->snake_len - 1)
	{
		sp->pix_new[1][i + 1] = sp->pix_old[1][i];
		i++;
	}
	return (next);
}

int	inputcheck(main_variables *mv)
{
	if (mv->last_inp == 'w' || mv->last_inp == 'a' || mv->last_inp == 's' || mv->last_inp == 'd')
		return (mv->last_inp);
	else if (mv->last_inp == 'q')
		return (mv->last_inp = quit, mv->last_inp);
	return (mv->last_inp);
}

int	loop(main_variables *mv, screen_prop *sp)
{
	int				bytesRead;

	while (mv->last_inp != quit && mv->iter < 30)
	{
		inputcheck(mv);
		if (mv->last_inp == quit)
			break ;
		refresh_snake(mv, sp);
		usleep(100000);
		get_terminal_size(sp);
		mv->iter++;
		print_screen(mv, sp);
	}
	return (0);
}

int	snake_main(void)
{
	main_variables	mv;
	screen_prop	sp;

	printf("Snake\n");
	set_variables(&mv, &sp);
	loop(&mv, &sp);
	printf("Exit\n");
	printf("Iterations: %lld\n", mv.iter);
	return (0);
}
