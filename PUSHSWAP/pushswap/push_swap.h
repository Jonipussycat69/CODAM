/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 16:43:40 by jdobos        #+#    #+#                 */
/*   Updated: 2024/03/23 10:13:19 by joni          ########   odam.nl         */
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

# define WS_PB_INIT_WEIGHT 3000.0

# define DIMMED_F "\033[2;37m"// TEST!
# define DIMMED_BOLD_F "\033[1;2;37m"// TEST!
# define RESET_F "\033[0m"// TEST!
# define GREEN_BOLD_F "\033[1;32m"// TEST!

/*
	value = original inputted value

	i_value = index corresponding to value

	list_index = index of placement in list

	stack_iv = index corresponding to the values in current list

	mark = the i_value of node this one should go ontop, used in sorting

	side = multiplier; 1 upper half, -1 lower half

	weight = the lower the wheight the better,
		[val + num of act] for low values, [num of act - val] for high
*/
typedef struct s_list
{
	int				value;
	int				i_value;
	int				list_index;
	int				stack_iv;
	int				mark;
	short			side;
	struct s_list	*next;
}	t_list;

typedef struct s_misc
{
	char	*str_to_free;
}	t_misc;

typedef struct s_sort
{
	int		total_inp;
	double	val_pa_mult;
	double	val_pb_mult;
	double	act_pa_mult;
	double	act_pb_mult;
	t_list	*act_node;
	double	act_weight;
	int		r_actions;
	int		rr_actions;
	int		act_arr[8];
}	t_sort;

enum	actions{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
enum	returns{err = -1, inert = -2, ok = 0};
enum	flags{lower = -1, upper = 1, biggest = -2};
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

// PUSH SWAP ORIGINAL

void	print_values(t_list **head, char stack);// TEST!
void	print_width_format(char *c, char *f);// TEST!
void	print_act_arr(t_sort *s, int i, double cur_weight, t_list *the_node);// TEST!

short	char_check(char *str);
char	*input_to_string(int argc, char **argv, t_misc *m);
short	parser(char *input, t_list **head);

void	list_indexer(t_list **head);
short	indexer(t_list **head);
void	stack_indexer(t_list **head);
void	update_variable_index(t_list **head_a, t_list **head_b);

void	assign_mark(t_list **head);
void	assign_side(t_list **head);
void	init_multiplier(t_list **head_a, t_sort *s);

short	check_sort_asc(t_list **head);
short	check_sort_des(t_list **head);
short	strict_check_asc(t_list **head);
short	strict_check_des(t_list **head);

double	sortedness_asc(t_list **head);
double	sortedness_des(t_list **head);

void	hardsort(t_list **head_used, t_list **head_other, short used_stack);

void	ws_pb_stage(t_list **head_a, t_list **head_b, t_sort *s);
void	ws_pa_stage(t_list **head_a, t_list **head_b, t_sort *s);
double	path_weigh(t_list **head_a, t_list **head_b, t_sort *s, short stage);
void	act_arr_reset(t_sort *s);
void	path_init(t_list **head_a, t_list **head_b, t_sort *s, short stage);

void	mark_sort_pa(t_list **head_a, t_list **head_b, t_sort *s);
void	ms_rep_action(t_list **head_a, t_list **head_b, int iter, short act);
void	ms_do_act(t_list **head_a, t_list **head_b, t_sort *s, int *act);
void	init_shortest(t_sort *s, int *tmp, short *act);
void	init_shortest_prepare(t_sort *s, short *act);
void	shortest_path(t_sort *s);
double	pathmark_weight(t_sort *s);

void	free_list(t_list **head);
short	nodeadd_back(t_list **head, t_list *node);
short	nodeadd_front(t_list **head, t_list *node);
t_list	*new_node(int val, int ind);

int		get_i_value(t_list *node);
int		get_value(t_list *node);
int		get_si(t_list *node);
int		get_li(t_list *node);
int		get_mark(t_list *node);
int		get_side(t_list *node);

int		list_len(t_list **head);
void	set_null(int *arr, int size);
void	copy_arr(int *dest, int *source, int size);
void	wr_a(char *action);

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

// LIBFT

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t c, size_t l);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *d, void *s, size_t size);
void		*ft_memset(void *b, int c, size_t l);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dest, const char *src, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *hay, const char *needle, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strrchr(const char *str, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

#endif