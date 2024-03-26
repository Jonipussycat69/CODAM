#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <sys/ioctl.h>

# define BLUE_F "\033[1;34m"
# define WHITE_F "\033[1;37m"
# define DIMMED_F "\033[2;37m"
# define DIMMED_BOLD_F "\033[1;2;37m"
# define RESET_F "\033[0m"
# define BLUE_DIM_F "\033[2;34m"
# define BLUE_BOLD_DIM_F "\033[1;2;34m"
# define BLUE_BOLD_F "\033[1;34m"
# define RED_DIM_F "\033[2;31m"
# define GREEN_BOLD_F "\033[1;32m"
# define GREEN_F "\033[32m"
# define GREEN_DIM_F "\033[2;32m"
# define CYAN_DIM_F "\033[2;36m"
# define CYAN_BOLD_F "\033[1;36m"

void	print_width_format(char *c, char *f)
{
	// JUST FOR TESTING!!
	struct winsize	w;
	int				i = 0;
	int				j = 0;

	ioctl(0, TIOCGWINSZ, &w);

	printf("%s", f);
	while (i++ < w.ws_col)
	{
		printf("%c", c[j]);
		j++;
		if (j == strlen(c))
			j = 0;
	}
	// printf("%s\n", RESET_F);

	// printf("lines %d\n", w.ws_row);
	// printf("columns %d\n", w.ws_col);
	return ;
}

void	print_sortedness_asc(t_list **head)
{
	long			total_dif;
	int				hold;
	double			sortedness;
	t_list			*tmp;

	if (!head || !*head || list_len(head) < 2)
		return ;
	tmp = *head;
	total_dif = 0;
	stack_indexer(head);
	while (tmp->next != NULL)
	{
		hold = tmp->stack_iv;
		tmp = tmp->next;
		hold = tmp->stack_iv - hold;
		if (hold < 0)
			hold *= -2;
		total_dif += hold;
	}
	// sortedness = (((double)list_len(head) - 1.0) / (double)total_dif) * 100.00;
	// printf("[Sortedness asc: %.3f]\n", sortedness);
	// sortedness = ((double)list_len(head) / ((double)total_dif + 1.0)) * 100.00;
	// printf("[Sortedness asc: %.3f]\n", sortedness);
	sortedness = (((double)list_len(head) - 1.0) / (double)total_dif) * 100.00;
	sortedness = ((((double)list_len(head) / ((double)total_dif + 1.0)) * 100.00) + sortedness) / 2.0;
	printf("[Sortedness asc: %.3f]\n", sortedness);
}

void	print_sortedness_des(t_list **head)
{
	long			total_dif;
	int				hold;
	double			sortedness;
	t_list			*tmp;

	if (!head || !*head || list_len(head) < 2)
		return ;
	tmp = *head;
	total_dif = 0;
	stack_indexer(head);
	while (tmp->next != NULL)
	{
		hold = tmp->stack_iv;
		tmp = tmp->next;
		hold = hold - tmp->stack_iv;
		if (hold < 0)
			hold *= -2;
		total_dif += hold;
	}
	// sortedness = (((double)list_len(head) - 1.0) / (double)total_dif) * 100.00;
	// printf("[Sortedness des: %.3f]\n", sortedness);
	// sortedness = ((double)list_len(head) / ((double)total_dif + 1.0)) * 100.00;
	// printf("[Sortedness des: %.3f]\n", sortedness);
	sortedness = (((double)list_len(head) - 1.0) / (double)total_dif) * 100.00;
	sortedness = ((((double)list_len(head) / ((double)total_dif + 1.0)) * 100.00) + sortedness) / 2.0;
	printf("[Sortedness des: %.3f]\n", sortedness);
}

void	print_values(t_list **head, char stack)
{
	// THIS FUNCTION IS JUST FOR TETSTING!!
	t_list	*tmp;

	tmp = *head;
	if (stack == 'a')
		print_width_format("-", CYAN_BOLD_F);
	else
		print_width_format("-", BLUE_BOLD_F);
	printf("\n< Stack: %c >\t", stack);
	if (stack == 'a')
		print_sortedness_asc(head);
	else
		print_sortedness_des(head);
	printf("Values:\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n\n");
	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d ", tmp->i_value);
		tmp = tmp->next;
	}
	printf("\n");
	if (stack == 'a')
		print_width_format("-", CYAN_BOLD_F);
	else
		print_width_format("-", BLUE_BOLD_F);
	printf("%s", RESET_F);
	printf("\n");
	return ;
}

void	print_act_arr(t_sort *s, int i, double cur_weight, t_list *the_node)
{
	printf("%s>> mark %2d[%2d] = %6.3f", DIMMED_F, s->act_node->i_value, i, cur_weight);// TEST!
	printf(" |~> act_arr = [ra %d| rb %d| rra %d| rrb %d| rr %d| rrr %d| pa %d| pb %d]", s->act_arr[0], \
	s->act_arr[1], s->act_arr[2], s->act_arr[3], s->act_arr[4], s->act_arr[5], \
	s->act_arr[6], s->act_arr[7]);
	if (the_node == s->act_node)
		printf("\nCHOSEN ONE");
	printf("%s\n", RESET_F);
}
