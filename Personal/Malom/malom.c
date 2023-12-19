#include "malom.h"

int	board[PARAMB][PARAMB] = {
	{0, 8, 8, 0, 8, 8, 0},
	{9, 0, 8, 0, 8, 0, 9},
	{9, 9, 0, 0, 0, 9, 9},
	{0, 0, 0, -1, 0, 0, 0},
	{9, 9, 0, 0, 0, 9, 9},
	{9, 0, 8, 0, 8, 0, 9},
	{0, 8, 8, 0, 8, 8, 0},
};

bool	malom_indicator = 0;
int		malom_coord[3];
int		coord_save[19][4];
mann	men_prev[19];
mann	men[19];

void	reset_malom_coord(void)
{
	malom_coord[0] = 0;
	malom_coord[1] = 0;
	malom_coord[2] = 0;
	return ;
}

void	set_coord(void)
{
	int	y = 0;
	int	x;

	while (y < 19)
	{
		x = 0;
		while (x < 4)
		{
			coord_save[y][x] = 0;
			x++;
		}
		y++;
	}
	return ;
}

void	set_men(void)
{
	int	i = 0;

	while (i < 9)
	{
		men[i].colour = white;
		men[i].state = inactive;
		men[i].x = 0;
		men[i].y = 0;
		men[i].code = i + 1;
		men[i].update = 0;
		i++;
	}
	while (i < 18)
	{
		men[i].colour = blue;
		men[i].state = inactive;
		men[i].x = 0;
		men[i].y = 0;
		men[i].code = i + 1;
		men[i].update = 0;
		i++;
	}
	return ;
}

int	assign_men(int turn, int game, inpt *inp, int type)
{
	int	reassigned = 0;
	int	x;
	int	y = 0;
	int	i = 0;
	int	temp_x = 0;
	int	temp_y = 0;

	if (type == set)
	{
		while (i < 18)
		{
			if (men[i].y > 0 && men[i].x > 0 && board[PARAMB - men[i].y][men[i].x - 1] == 0 \
			&& malom_coord[0] == men[i].y && malom_coord[1] == men[i].x)
			{
				men[i].y = 0;
				men[i].x = 0;
				men[i].state = dead;
			}
			i++;
		}
		i = 0;
		while ((men[i].y == 0 && men[i].x == 0) || men[i].state == dead)
			i++;
		men[i].y = inp->Y_new;
		men[i].x = inp->X_new;
		men[i].state = alive;
		return (next);
	}
	if (type == move)
	{
		while (i < 18)
		{
			if (men[i].y > 0 && men[i].x > 0 && board[PARAMB - men[i].y][men[i].x - 1] == 0 \
			&& malom_coord[0] == men[i].y && malom_coord[1] == men[i].x)
			{
				men[i].y = 0;
				men[i].x = 0;
				men[i].state = dead;
			}
			i++;
		}
		i = 0;
		while (i < 18)
		{
			if (men[i].y > 0 && men[i].x > 0 && board[PARAMB - men[i].y][men[i].x - 1] == 0)
				reassigned = i;
			i++;
		}
		if (reassigned)
		{
			men[reassigned].y = inp->Y_new;
			men[reassigned].x = inp->X_new;
			men[i].state = moved;
		}
		return (next);
	}
	return (next);// LEFTOFF check if the coordinates of a man changed SEGFAULT!!!!!!!!!!!!!!
}

int	chek_malom(int turn, int game)
{
	return (next);
}

int	print_board(int turn, int game)
{
	int	x;
	int	y = 0;
	int	i = 0;

	while (y < PARAMB)
	{
		printf("%d   ", PARAMB - y);
		x = 0;
		while (x < PARAMB)
		{
			if (board[y][x] == 0)
				printf("%so%s", DIMMED_F, RESET_F);
			else if (board[y][x] == 'w')
				printf("%sW%s", WHITE_F, RESET_F);
			else if (board[y][x] == 'b')
				printf("%sB%s", BLUE_F, RESET_F);
			else if (board[y][x] == 8)
				printf("-");
			else if (board[y][x] == 9)
				printf("|");
			else if (board[y][x] == -1)
				printf(" ");
			if (y == (PARAMB - 1) / 2)
			{
				if (x == (PARAMB - 1) / 2 || x == (PARAMB - 1) / 2 - 1)
					printf(" ");
				else if (x < PARAMB - 1)
					printf("-");
			}
			else if (y < (PARAMB - 1) / 2)
			{
				if (x < (PARAMB - 1) - y && x >= (PARAMB - 1) - ((PARAMB - 1) - y))
					printf("-");
				else
					printf(" ");
			}
			else if (y > 3)
			{
				if (x >= (PARAMB - 1) - y && x < (PARAMB - 1) - ((PARAMB - 1) - y))
					printf("-");
				else
					printf(" ");
			}
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n    a b c d e f g\n");
	while ((men[i].state == alive || men[i].state == dead) && i < 18)
	{
		printf("  ");
		if (men[i].state == alive)
			printf("%sman %2d%s", GREEN_DIM_F, i + 1, RESET_F);
		if (men[i].state == dead)
			printf("%sman %2d%s", RED_DIM_F, i + 1, RESET_F);
		i++;
	}
	printf("\n");
	i = 0;
	while ((men[i].state == alive || men[i].state == dead) && i < 18)
	{
		printf("    ");
		if (men[i].state == alive)
			printf("%s%c%d%s", GREEN_DIM_F, men[i].x, men[i].y, RESET_F);
		if (men[i].state == dead)
			printf("%s X%s", RED_DIM_F, RESET_F);
		printf("  ");
		i++;
	}
	printf("\n");
	print_width_format("Malom ", BLUE_DIM_F);
}

void	print_info(void)
{
	printf("\033[3;34m");
	printf("\n~ INFO ~\n\n");
	printf(" Game: Nine men's morris / Malom\n\n");
	printf(" Input syntax:\n\n");
	printf(" -> When inputting a set (\"Input set\"):\n");
	printf(" <coordinate x (a-z)> <coordinate y (1-7)> <Enter>\n\n");
	printf(" -> When inputting a move (\"Input move\"):\n");
	printf(" <current x> <current y> <Space> <new x> <new y> <Enter>\n\n");
	printf(" -> to start a new game type: \"redo\"\n");
	printf(" -> to exit the program type: \"exit\"\n\n");
	printf("\033[0m");
	return ;
}

int	save_game(int cur_game, int turns)
{
	return (next);
}

int	do_set(inpt *inp, int turn, int cur_game)
{
	if (turn % 2 == 1)
		board[PARAMB - inp->Y_new][inp->X_new - 1] = 'w';
	else
		board[PARAMB - inp->Y_new][inp->X_new - 1] = 'b';
	return (next);
}

int	do_move(inpt *inp, int turn, int cur_game)
{
	if (turn % 2 == 1)
	{
		board[PARAMB - inp->Y_new][inp->X_new - 1] = 'w';
		board[PARAMB - inp->Y_cur][inp->X_cur - 1] = 0;
	}
	else
	{
		board[PARAMB - inp->Y_new][inp->X_new - 1] = 'b';
		board[PARAMB - inp->Y_cur][inp->X_cur - 1] = 0;
	}
	return (next);
}

int	malom()
{
	inpt	inp;
	int	games = 1;
	int	turn = 1;
	int	re_turn;
	int	check_ret = 0;
	char	input_buf[INP_LEN + 1];
	char	*ptr;

	print_info();
	while (games <= 100)
	{
		set_men();
		set_coord();
		reset_malom_coord();
		reset_board();
		ft_bzero(input_buf, INP_LEN + 1);
		printf("\n~ GAME %d START ~\n\n", games);
		turn = 1;
		re_turn = next;
		while (re_turn == next)
		{
			if (turn % 2 == 1)
				printf("\n %sWHITE%s", WHITE_F, RESET_F);
			else
				printf("\n %sBLUE%s", BLUE_F, RESET_F);
			printf(" > Turn:%2d\n", turn);
			check_ret = reinp;
			while (check_ret == reinp)
			{
				printf(" > Input set: ");
				fgets(input_buf, INP_LEN, stdin);
				terminate_c(input_buf, '\n');
				check_ret = inp_check(input_buf, &inp, set);
				printf("\n");
			}
			if (check_ret == error)
				return (error);
			if (check_ret == exit_program)
				return (exit_program);
			if (check_ret == redo)
				break ;
			re_turn = do_set(&inp, turn, games);
			if (re_turn == error)
				return (error);
			
			assign_men(turn, games, &inp, set);
			print_board(turn, games);
			turn++;
		}
		printf("\n Lets start moving!..\n");
		re_turn = next;
		while (turn > 18 && re_turn == next)
		{
			if (turn % 2 == 1)
				printf("\n %sWHITE%s", WHITE_F, RESET_F);
			else
				printf("\n %sBLUE%s", BLUE_F, RESET_F);
			printf(" > Turn:%2d	> Move Turn:%2d\n", turn, turn - 18);
			check_ret = reinp;
			while (check_ret == reinp)
			{
				printf(" > Input move: ");
				fgets(input_buf, INP_LEN, stdin);
				terminate_c(input_buf, '\n');
				check_ret = inp_check(input_buf, &inp, move);
				printf("\n");
			}
			if (check_ret == error)
				return (error);
			if (check_ret == exit_program)
				return (exit_program);
			if (check_ret == redo)
				break ;
			re_turn = do_move(&inp, turn, games);
			if (re_turn == error)
				return (error);
			assign_men(turn, games, &inp, move);
			print_board(turn, games);
			turn++;
		}
		if (save_game(games, turn - 1) == error)
			return (error);
		printf("\n~ GAME %d END ~\n\n", games);
		games++;
	}
	return (end);
}

void	reset_board(void)
{
	board[0][0] = 0;
	board[0][3] = 0;
	board[0][6] = 0;
	board[1][1] = 0;
	board[1][3] = 0;
	board[1][5] = 0;
	board[2][2] = 0;
	board[2][3] = 0;
	board[2][4] = 0;
	board[3][0] = 0;
	board[3][1] = 0;
	board[3][2] = 0;
	board[3][4] = 0;
	board[3][5] = 0;
	board[3][6] = 0;
	board[4][2] = 0;
	board[4][3] = 0;
	board[4][4] = 0;
	board[5][1] = 0;
	board[5][3] = 0;
	board[5][5] = 0;
	board[6][0] = 0;
	board[6][3] = 0;
	board[6][6] = 0;
	board[3][3] = -1;
	return ;
}

int	rule_check(int type, inpt *inp)
{
	if (board[PARAMB - inp->Y_new][inp->X_new - 1] != 0)
		return (error);
	if (type == move || type == jumpmove)
	{
		if (board[PARAMB - inp->Y_cur][inp->X_cur - 1] != 0)
			return (error);
	}
	if (type == move)
	{
		if (inp->X_cur == 3 || inp->X_cur == 5 || inp->Y_cur == 3 || inp->Y_cur == 5)
		{
			if (inp->X_new - inp->X_cur > 1 || inp->X_new - inp->X_cur < -1)
				return (error);
		}
		if (inp->X_new - inp->X_cur > 2 || inp->X_new - inp->X_cur < -2)
			return (error);
	}
	return (next);// check if the set/ move is possible
}
