#include "malom.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)s = '\0';
		s++;
		n--;
	}
}

int	play_to_file(int fd)
{
	return (next);
}

int	get_play_file(int fd)
{
	return (next);
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
