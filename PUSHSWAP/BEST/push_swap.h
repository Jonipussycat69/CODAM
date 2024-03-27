/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 16:43:40 by jdobos        #+#    #+#                 */
/*   Updated: 2024/03/27 23:48:11 by joni          ########   odam.nl         */
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
	int				ind;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	int		total_inp;
	double	val_pb_mult;
	double	act_pb_mult;
	t_list	*act_node;
	double	act_weight;
	int		r_actions;
	int		rr_actions;
	int		act_arr[8];
}	t_sort;

typedef struct s_parser
{
	long	num;
	short	min;
}	t_parse;

enum	actions{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
enum	returns{err = -1, inert = -2, ok = 0};
enum	flags{biggest = -2};
enum	stacks{st_a = 0, st_b = 1};
enum	inputs{s_pa = 1, s_pb = 2, global = 20};
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

short	char_check(char *str);
char	*input_to_string(int argc, char **argv);
short	parser(char *input, t_list **head);

void	list_indexer(t_list **head);
short	indexer(t_list **head);
void	stack_indexer(t_list **head);
void	update_variable_index(t_list **head_a, t_list **head_b);

void	assign_mark(t_list **head);
void	init_multiplier(t_sort *s);

short	check_sort_asc(t_list **head);
short	strict_check_asc(t_list **head);

void	hardsort(t_list **head_used, t_list **head_other, short used_stack);

void	weigh_sort_pb(t_list **head_a, t_list **head_b, t_sort *s);

void	mark_sort_pa(t_list **head_a, t_list **head_b, t_sort *s);
void	ms_rep_action(t_list **head_a, t_list **head_b, int iter, short act);
void	ms_do_act(t_list **head_a, t_list **head_b, t_sort *s, int *act);
void	ms_shortest_path(t_sort *s);
double	ms_path_weight(t_sort *s);

void	free_list(t_list **head);
short	node_back(t_list **head, t_list *node);
t_list	*new_node(int val, int ind);

int		get_i_value(t_list *node);
int		get_si(t_list *node);
int		get_li(t_list *node);
int		get_mark(t_list *node);

int		list_len(t_list **head);
void	set_null(int *arr, int size);
void	copy_arr(int *dest, int *source, int size);
void	wr_a(char *action);
void	act_arr_reset(t_sort *s);

t_list	*last_node(t_list **head);

t_list	*nth_node(t_list **head, int n);
t_list	*n_si_node(t_list **head, int n);
t_list	*n_li_node(t_list **head, int n);
t_list	*n_iv_node(t_list **head, int n);

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
short	double_act(t_list **head_a, t_list **head_b, short act);

size_t	ps_strlen(char *str);
short	ps_isdigit(int c);
char	*ps_strjoin(char *add, char *line, size_t i, size_t j);

#endif