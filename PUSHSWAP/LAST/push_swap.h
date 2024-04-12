/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 16:43:40 by jdobos        #+#    #+#                 */
/*   Updated: 2024/04/12 15:41:02 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	int				index;
	int				place;
	int				to_be;
	int				weight_a;
	int				weight_b;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	int	total_inp;
	int	index;
	int	the_index;
	int	the_weight;
	t_list	*the_node;
	int	r_num;
	int	rr_num;
	int	act_arr[8];
}	t_sort;

typedef struct s_parser
{
	long	num;
	short	min;
}	t_parse;

enum	actions{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
enum	returns{err = -1, inert = -2, ok = 0};
enum	flags{biggest = -2};
enum	act_arr{
	_ra = 0,
	_rb = 1,
	_rra = 2,
	_rrb = 3,
	_rr = 4,
	_rrr = 5,
	_pa = 6,
	_pb = 7,
};

void	print_values(t_list **a, t_list **b, t_sort *s);// TEST

short	char_check(char *str);
char	*input_to_string(int argc, char **argv);
short	parser(char *input, t_list **head);
short	indexer(t_list **head);


void	pb_stage(t_list **a, t_list **b, t_sort *s);
void	pa_stage(t_list **a, t_list **b, t_sort *s);
void	hardsort(t_list **a, t_list **b);
int		weigh(t_list **a, t_list **b, t_sort *s, t_list *node);
void	execute_act(t_list **a, t_list **b, t_sort *s, t_list *node);

void	free_list(t_list **head);
short	node_back(t_list **head, t_list *node);
t_list	*new_node(int val);

int		bn(int one, int two);
int		sn(int one, int two);
int		rotate_amount_b(t_list **b, int a_num);
short	check_sort_asc(t_list **head);
void	act_arr_reset(t_sort *s);

void	wr_a(char *action);
int		list_len(t_list **head);
t_list	*last_node(t_list **head);

void	swap(t_list **head);
void	push(t_list **head_a, t_list **head_b, short stack);
void	rotate(t_list **head); 
void	r_rotate(t_list **head);

void	swap_both(t_list **head_a, t_list **head_b);
void	rotate_both(t_list **head_a, t_list **head_b);
void	r_rotate_both(t_list **head_a, t_list **head_b);

void	do_action(t_list **head_a, t_list **head_b, short action);
void	do_actions(t_list **head_a, t_list **head_b, int amount, ...);
void	repeat_action(t_list **head_a, t_list **head_b, int iter, short act);
void	do_act_arr(t_list **head_a, t_list **head_b, t_sort *s);
// short	double_act(t_list **head_a, t_list **head_b, short act);

size_t	ps_strlen(char *str);
short	ps_isdigit(int c);
char	*ps_strjoin(char *add, char *line, size_t i, size_t j);

#endif