#include "malom.h"

void	print_width_format(char *c, char *f)
{
	struct winsize	w;
	int				i = 0;
	int				j = 0;

	ioctl(0, TIOCGWINSZ, &w);

	printf("\n%s", f);
	while (i++ < w.ws_col)
	{
		printf("%c", c[j]);
		j++;
		if (j == strlen(c))
			j = 0;
	}
	printf("%s\n", RESET_F);

	// printf("lines %d\n", w.ws_row);
	// printf("columns %d\n", w.ws_col);
	return ;
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)s = '\0';
		s++;
		n--;
	}
}

int	terminate_c(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
		{
			*str = '\0';
			return (1);
		}
		str++;
	}
	return (0);
}

int	play_to_file(int fd)
{
	return (next);
}

int	get_play_file(int fd)
{
	return (next);
}

void	stop_game(int type)
{
	// Write something of exit in the save file and close it maybe
	return ;
}

void	print_format(int col, int type)
{
	if (col == reset_colour && type == standard_form)
		printf("\033[0m");
	else if (col == black)
	{
		if (type == standard_form)
			printf("\033[0;30m");
		else if (type == bold)
			printf("\033[1;30m");
		else if (type == cursive)
			printf("\033[2;30m");
	}
	else if (col == red)
	{
		if (type == standard_form)
			printf("\033[0;31m");
		else if (type == bold)
			printf("\033[1;31m");
		else if (type == cursive)
			printf("\033[2;31m");
	}
	else if (col == green)
	{
		if (type == standard_form)
			printf("\033[0;32m");
		else if (type == bold)
			printf("\033[1;32m");
		else if (type == cursive)
			printf("\033[2;32m");
	}
	else if (col == yellow)
	{
		if (type == standard_form)
			printf("\033[0;33m");
		else if (type == bold)
			printf("\033[1;33m");
		else if (type == cursive)
			printf("\033[2;33m");
	}
	else if (col == blue)
	{
		if (type == standard_form)
			printf("\033[0;34m");
		else if (type == bold)
			printf("\033[1;34m");
		else if (type == cursive)
			printf("\033[2;34m");
	}
	else if (col == purple)
	{
		if (type == standard_form)
			printf("\033[0;35m");
		else if (type == bold)
			printf("\033[1;35m");
		else if (type == cursive)
			printf("\033[2;35m");
	}
	else if (col == cyan)
	{
		if (type == standard_form)
			printf("\033[0;36m");
		else if (type == bold)
			printf("\033[1;36m");
		else if (type == cursive)
			printf("\033[2;36m");
	}
	else if (col == white)
	{
		if (type == standard_form)
			printf("\033[0;37m");
		else if (type == bold)
			printf("\033[1;37m");
		else if (type == cursive)
			printf("\033[2;37m");
	}
	return ;
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
	return (error); // check if coordinates are existing ones
}

int	inp_check(char *input, inpt *inp, int type, int turn)
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
		if (rule_check(turn, set, inp) == error)
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
		if (rule_check(turn, move, inp) == error)
			return (printf("\n\033[2;33m Invalid Move!\033[0m\n"), reinp);
		return (next);
	}
	return (error);
}
