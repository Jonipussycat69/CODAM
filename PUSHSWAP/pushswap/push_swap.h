/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 16:43:40 by jdobos        #+#    #+#                 */
/*   Updated: 2024/03/15 19:45:02 by jdobos        ########   odam.nl         */
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

# define WS_REMAIN 3

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
	short			weight;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	char	*str_to_free;
	int		total_inp;
	short	choice_index;
	short	ret_a;
	short	ret_b;
	double	val_mult;
	double	act_mult;
	double	sortedness_a;
	double	sortedness_b;
	double	total_sorted;
}	t_sort;

typedef struct s_action
{
	t_list	*node_b;
	t_list	*node_a;
	int		act_arr[6];
	int		total_act;
}	t_act;

enum	actions{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
enum	returns{err = -1, inert = -2, ok = 0, eureka};
enum	flags{lower = -1, upper = 1, f_true, f_false};
enum	stacks{st_a = 0, st_b = 1};
enum	act_arr{
	_ra = 0,
	_rb = 1,
	_rra = 2,
	_rrb = 3,
	_rr = 4,
	_rrr = 5,
};

// PUSH SWAP ORIGINAL

void	print_values(t_list **head, char stack);// TEST!
void	print_width_format(char *c, char *f);// TEST!

void	list_indexer(t_list **head);
short	indexer(t_list **head);
void	stack_indexer(t_list **head);
void	update_variable_index(t_list **head_a, t_list **head_b);

void	assign_mark(t_list **head);
void	assign_side(t_list **head);

short	check_sort_asc(t_list **head);
short	check_sort_des(t_list **head);
double	sortedness_asc(t_list **head);
double	sortedness_des(t_list **head);

short	hardsort(t_list **head_used, t_list **head_other, short used_stack);

short	algo_swap_push(t_list **head_a, t_list **head_b, t_sort *s, \
		const short *arr);

short	fsl_sort(t_list **head_a, t_list **head_b, t_sort *s, \
		const short *arr);
short	weigh_sort(t_list **head_a, t_list **head_b, t_sort *s, \
		const short *arr);

void	free_list(t_list **head);
short	nodeadd_back(t_list **head, t_list *node);
short	nodeadd_front(t_list **head, t_list *node);
t_list	*new_node(int val, int ind);

int		get_i_value(t_list *node);
int		get_value(t_list *node);
int		get_weight(t_list *node);
int		get_li(t_list *node);
int		get_mark(t_list *node);
int		get_side(t_list *node);

int		list_len(t_list **head);

t_list	*last_node(t_list **head);

t_list	*nth_node(t_list **head, int n);
t_list	*n_si_node(t_list **head, int n);
t_list	*n_li_node(t_list **head, int n);
t_list	*n_iv_node(t_list **head, int n);
short	parser(char *input, t_list **head);

short	swap(t_list **head);
short	push(t_list **head_a, t_list **head_b, short stack);
short	rotate(t_list **head);
short	r_rotate(t_list **head);

short	swap_both(t_list **head_a, t_list **head_b);
short	rotate_both(t_list **head_a, t_list **head_b);
short	r_rotate_both(t_list **head_a, t_list **head_b);
short	do_action(t_list **head_a, t_list **head_b, short action);
short	do_actions(t_list **head_a, t_list **head_b, int amount, ...);

void	wr_a(char *action);
t_list	*find_annom(t_list **head);

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