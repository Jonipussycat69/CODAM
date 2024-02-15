/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 16:43:40 by jdobos        #+#    #+#                 */
/*   Updated: 2024/02/15 16:48:08 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>

typedef struct s_list
{
	int				value;
	int				i_value;
	int				list_index;
	int				stack_iv;
	short			flag;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	int		total_inputsize;
	int		mid_iv_a;
	int		mid_iv_b;
	int		mid_si_a;
	int		mid_si_b;
	int		mid_li_a;
	int		mid_li_b;
	int		large_si_a;
	int		large_si_b;
	int		large_b_si_a;
	int		large_b_si_b;
	int		large_t_si_a;
	int		large_t_si_b;
	int		sorting_point;
	int		sorted_amount;
	int		stack_a_len;
	int		stack_b_len;
	short	choice_index;
}	t_sort;

enum	actions{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
enum	returns{err, mid, ok};
enum	stacks{a, b};

// PUSH SWAP ORIGINAL

void	list_indexer(t_list **head);
void	indexer(t_list **head);
void	stack_indexer(t_list **head);
void	parser(char *input, t_list **head);

void	assign_mid(t_list **head_a, t_list **head_b, t_sort *s);
int		get_mid_si(t_list **head, t_sort *s);

void	assign_large(t_list **head_a, t_list **head_b, t_sort *s);

void	small_algo(t_list **head_a, t_list **head_b, t_sort *s, short *arr);
void	midsplit_algo(t_list **head_a, t_list **head_b, t_sort *s, short *arr);

void	free_list(t_list **head);
short	nodeadd_back(t_list **head, t_list *node);
short	nodeadd_front(t_list **head, t_list *node);
t_list	*new_node(int val, int ind);

int		get_index(t_list *node);
int		get_value(t_list *node);
int		get_flag(t_list *node);
int		list_len(t_list **head);

t_list	*last_node(t_list **head);
t_list	*nth_node(t_list **head, int n);

t_list	*n_si_node(t_list **head, int n);
t_list	*n_li_node(t_list **head, int n);
t_list	*n_iv_node(t_list **head, int n);

short	swap(t_list **head);
short	push(t_list **head_a, t_list **head_b, short stack);
short	rotate(t_list **head);
short	r_rotate(t_list **head);

short	swap_both(t_list **head_a, t_list **head_b);
short	rotate_both(t_list **head_a, t_list **head_b);
short	r_rotate_both(t_list **head_a, t_list **head_b);
short	do_action(t_list **head_a, t_list **head_b, short action);
short	do_actions(t_list **head_a, t_list **head_b, short amount, ...);

void	wr_a(char *action);

size_t	ps_strlen(char *str);

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