#include "malom.h"

int	board[8][8] = {
	{7, 0, 3, 3, 0, 3, 3, 0},
	{6, 3, 0, 3, 0, 3, 0, 3},
	{5, 3, 3, 0, 0, 0, 3, 3},
	{4, 0, 0, 0, 4, 0, 0, 0},
	{3, 3, 3, 0, 0, 0, 3, 3},
	{2, 3, 0, 3, 0, 3, 0, 3},
	{1, 0, 3, 3, 0, 3, 3, 0},
	{0, 'a', 'b', 'c', 'd', 'e', 'f', 'g'}	
};

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

#define A1 outer_layer[2][0]
#define A4 outer_layer[1][0]
#define A7 outer_layer[0][0]

#define B2 middle_layer[2][0]
#define B4 middle_layer[1][0]
#define B6 middle_layer[0][0]

#define C3 inner_layer[2][0]
#define C4 inner_layer[1][0]
#define C5 inner_layer[0][0]

#define D1 outer_layer[2][1]
#define D2 middle_layer[2][1]
#define D3 inner_layer[2][1]
#define D5 inner_layer[0][1]
#define D6 middle_layer[0][1]
#define D7 outer_layer[0][1]

#define E3 inner_layer[2][2]
#define E4 inner_layer[1][2]
#define E5 inner_layer[0][2]

#define F2 middle_layer[2][2]
#define F4 middle_layer[1][2]
#define F6 middle_layer[0][2]

#define G1 outer_layer[2][2]
#define G4 outer_layer[1][2]
#define G7 outer_layer[0][2]

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

void	stop_game(int type)
{
	// Write something of exit in the save file and close it maybe
	return ;
}

int	save_game(int cur_game, int turns)
{
	return (next);
}

int	coordinate_check(int type, inpt *inp)
{
	if (inp->X_new_alpf == 'a' || inp->X_new_alpf == 'g')
	{
		if (inp->Y_new == 1 || inp->Y_new == 4 || inp->Y_new == 7)
			return (next);
	}
	else if (inp->X_new_alpf == 'b' || inp->X_new_alpf == 'f')
	{
		if (inp->Y_new == 2 || inp->Y_new == 4 || inp->Y_new == 6)
			return (next);
	}
	else if (inp->X_new_alpf == 'c' || inp->X_new_alpf == 'e')
	{
		if (inp->Y_new == 3 || inp->Y_new == 4 || inp->Y_new == 5)
			return (next);
	}
	else if (inp->X_new_alpf == 'd')
	{
		if (inp->Y_new >= 1 && inp->Y_new <= 7 && inp->Y_new != 4)
			return (next);
	}
	if (type == move)
	{
		if (inp->X_cur_alpf == 'a' || inp->X_cur_alpf == 'g')
		{
			if (inp->Y_cur == 1 || inp->Y_cur == 4 || inp->Y_cur == 7)
				return (next);
		}
		else if (inp->X_cur_alpf == 'b' || inp->X_cur_alpf == 'f')
		{
			if (inp->Y_cur == 2 || inp->Y_cur == 4 || inp->Y_cur == 6)
				return (next);
		}
		else if (inp->X_cur_alpf == 'c' || inp->X_cur_alpf == 'e')
		{
			if (inp->Y_cur == 3 || inp->Y_cur == 4 || inp->Y_cur == 5)
				return (next);
		}
		else if (inp->X_cur_alpf == 'd')
		{
			if (inp->Y_cur >= 1 && inp->Y_cur <= 7 && inp->Y_cur != 4)
				return (next);
		}
	}
	return (error); // should check if coordinates are existing ones
}

int	rule_check(int type, inpt *inp)
{
	
	if (type == move)
	{
		return (next);
	}
	return (error);//LEFTOFF should check if the set/ move is possible
}

int	inp_check(char *input, inpt *inp, int type)
{
	const char	alnum[] = " abcdefg";
	int			i = 0;

	if (strcmp(input, "exit") == 0)
		return (stop_game(exit_program), exit_program);
	if (strcmp(input, "redo") == 0)
		return (stop_game(redo), redo);
	if (type == set)
	{
		if (!(input[0] >= 'a' && input[0] <= 'g'))
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (!(input[1] >= '1' && input[1] <= '7'))
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (input[2] != '\0')
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		while (alnum[i] != input[0])
			i++;
		inp->X_new_alpf = input[0];
		inp->X_new = i;
		inp->Y_new = input[1] - '0';
		if (coordinate_check(set, inp) == error)
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (rule_check(set, inp) == error)
			return (printf("\n\033[2;33m Invalid set!\033[0m\n"), reinp);
		return (next);
	}
	if (type == move)
	{
		if (!(input[0] >= 'a' && input[0] <= 'g'))
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (!(input[1] >= '1' && input[1] <= '7'))
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (input[2] != ' ')
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (!(input[3] >= 'a' && input[3] <= 'g'))
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (!(input[4] >= '1' && input[4] <= '7'))
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (input[5] != '\0')
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		while (alnum[i] != input[0])
			i++;
		inp->X_cur_alpf = input[0];
		inp->X_cur = i;
		inp->Y_cur = input[1] - '0';
		i = 0;
		while (alnum[i] != input[3])
			i++;
		inp->X_new_alpf = input[3];
		inp->X_new = i;
		inp->Y_new = input[4] - '0';
		if (coordinate_check(move, inp) == error)
			return (printf("\n\033[2;33m Invalid Input!\033[0m\n"), reinp);
		if (rule_check(move, inp) == error)
			return (printf("\n\033[2;33m Invalid Move!\033[0m\n"), reinp);
		return (next);
	}
	return (error);
}

int	do_set(inpt *inp, int turn, int cur_game)
{
	return (next);
}

int	do_move(inpt *inp, int turn, int cur_game)
{
	return (next);
}

int	malom()
{
	inpt inp;
	int	games = 1;
	int	turn = 1;
	int	re_turn;
	int	check_ret = 0;
	char	input_buf[INP_LEN + 1];
	char	*ptr;

	print_info();
	while (games <= 100)
	{
		ft_bzero(input_buf, INP_LEN);
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
			printf(" > Turn:%2d\n", turn);
			check_ret = reinp;
			while (check_ret == reinp)
			{
				printf(" > Input set: ");
				fgets(input_buf, INP_LEN, stdin);
				ptr = strchr(input_buf, '\n');
				*ptr = '\0';
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
			turn++;
		}
		re_turn = next;
		while (turn > 18 && re_turn == next)
		{
			if (turn % 2 == 1)
				printf("\n WHITE");
			else
				printf("\n BLACK");
			printf(" > Turn:%2d	> Move Turn:%2d\n", turn, turn - 18);
			check_ret = reinp;
			while (check_ret == reinp)
			{
				printf(" > Input move: ");
				fgets(input_buf, INP_LEN, stdin);
				ptr = strchr(input_buf, '\n');
				*ptr = '\0';
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
