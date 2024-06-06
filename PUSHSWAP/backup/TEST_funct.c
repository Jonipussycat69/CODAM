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

# define BLUE_F "\033[0;34m"
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
# define CYAN_F "\033[0;36m"
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

void	print_values(t_list **a, t_list **b, t_sort *s)
{
	// THIS FUNCTION IS JUST FOR TETSTING!!
	t_list	*tmp;

	tmp = *a;
	print_width_format("-", BLUE_BOLD_F);
	printf("\n< Stack: a >\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->n_i);
		tmp = tmp->next;
	}
	printf("\n");
	printf("%s", RESET_F);
	if (list_len(b) > 0)
	{
		tmp = *b;
		printf("%s< Stack: b >\n", CYAN_F);
		while (tmp != NULL)
		{
			printf("%d ", tmp->n_i);
			tmp = tmp->next;
		}
		printf("\n");
	}
	printf("%s", RESET_F);
	if (check_sort_asc(a) == ok && list_len(a) == s->total_inp)
		printf("%sOK sort\n", GREEN_BOLD_F);
	else
		printf("%sKO sort\n", RED_DIM_F);
	printf("%s", RESET_F);
	print_width_format("-", BLUE_BOLD_F);
	printf("%s", RESET_F);
	printf("\n");
	return ;
}
