#include "malom.h"

int	outer_layer[3][3] = {
	{0, 0, 0},
	{0, -1, 0},
	{0, 0, 0}
};

int	middle_layer[3][3] = {
	{0, 0, 0},
	{0, -1, 0},
	{0, 0, 0}
};

int	inner_layer[3][3] = {
	{0, 0, 0},
	{0, -1, 0},
	{0, 0, 0}
};

int	save_game(int cur_game, int turns)
{
	return (next);
}

int	inp_check(char *input, inpt *inp, int type)
{
	return (next);
}

int	rule_check()
{
	return (next);
}

int	do_set(inpt *inp, int turn, int cur_game)
{
	return (end);
}

int	do_move(inpt *inp, int turn, int cur_game)
{
	return (end);
}

int	malom()
{
	inpt inp;
	int	games = 1;
	int	turn = 1;
	int	re_turn;
	char	input_buf[INP_LEN + 1];

	input_buf[INP_LEN] = '\0';
	printf("\n~ INFO ~\n\n");
	printf(" Game: Nine men's morris / Malom\n\n");
	printf(" Input syntax:\n");
	printf(" > When inputting a set (\"Input set\") type: \n");
	printf(" > When inputting a move (\"Input move\") type: \n");
	while (games <= 100)
	{
		printf("\n~ GAME %d START ~\n\n", games);
		turn = 1;
		re_turn = next;
		reset_board();
		while (re_turn == next)
		{
			if (turn % 2 == 1)
				printf("\n WHITE");
			else
				printf("\n BLACK");
			printf(" > Turn:%5d\n", turn);
			printf(" > Input set: ");
			fgets(input_buf, INP_LEN, stdin);
			if (inp_check(input_buf, &inp, set) == error)
				return (error);
			if (inp_check(input_buf, &inp, set) == exit_program)
				return (exit_program);
			if (inp_check(input_buf, &inp, set) == redo)
				break ;
			re_turn = do_set(&inp, turn, games);
			if (re_turn == error)
				return (error);
			turn++;
		}
		re_turn = next;
		while (turn > 18 && re_turn == next)
		{
			if (turn % 2 == 1)
				printf("\n WHITE");
			else
				printf("\n BLACK");
			printf(" > Turn:%5d	> Move Turn:%5d\n", turn, turn - 18);
			printf(" > Input move: ");
			fgets(input_buf, INP_LEN, stdin);
			if (inp_check(input_buf, &inp, move) == error)
				return (error);
			if (inp_check(input_buf, &inp, move) == exit_program)
				return (exit_program);
			if (inp_check(input_buf, &inp, move) == redo)
				break ;
			re_turn = do_move(&inp, turn, games);
			if (re_turn == error)
				return (error);
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
	inner_layer[0][0] = 0;
	inner_layer[0][1] = 0;
	inner_layer[0][2] = 0;
	inner_layer[1][0] = 0;
	inner_layer[1][1] = -1;
	inner_layer[1][2] = 0;
	inner_layer[2][0] = 0;
	inner_layer[2][1] = 0;
	inner_layer[2][2] = 0;
	middle_layer[0][0] = 0;
	middle_layer[0][1] = 0;
	middle_layer[0][2] = 0;
	middle_layer[1][0] = 0;
	middle_layer[1][1] = -1;
	middle_layer[1][2] = 0;
	middle_layer[2][0] = 0;
	middle_layer[2][1] = 0;
	middle_layer[2][2] = 0;
	outer_layer[0][0] = 0;
	outer_layer[0][1] = 0;
	outer_layer[0][2] = 0;
	outer_layer[1][0] = 0;
	outer_layer[1][1] = -1;
	outer_layer[1][2] = 0;
	outer_layer[2][0] = 0;
	outer_layer[2][1] = 0;
	outer_layer[2][2] = 0;
	return ;
}
