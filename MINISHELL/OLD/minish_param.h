#ifndef MINISH_PARAM_H
# define MINISH_PARAM_H
# include "libft/libft.h"
# include "minish_def.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <termios.h>

// Function parameters

// parsing.c

void	parsing_distributor(t_dad *d);

// parsing_envp.c

size_t	parse_env_variable(t_dad *d, size_t i);

// init_env_list.c

t_env_node	**create_env_list(char **envp);

// utils_syntax.c

bool	syntax_check(const char *line);

// utils_string.c

char	*strdup_index(char *str, size_t	start, size_t end);

// utils_sig_arg_list.c

bool	new_node_back_arglist
(
	t_cmd_node	**cmd_head,
	char		**cmd_arr,
	short		token,
	t_sig_arg	**head
);
t_sig_arg	*arglist_last_node(t_sig_arg **head);
void		free_arglist(t_sig_arg **head);

// utils_cmd_list.c

bool		new_node_back_cmdlist(t_cmd_node **head, char *content);
t_cmd_node	*cmdlist_last_node(t_cmd_node **head);
void		free_cmdlist(t_cmd_node **head);

// utils_env_list.c

t_env_node	**new_node_back_envlist(t_env_node **head, char *key, char *value);
void		free_envlist(t_env_node **head);

// utils_exit.c

void	exit_clean(t_dad *d, int num, char *message);
void	exit_va_free(t_dad *d, int num, char *message, short amount, ...);

// utils_freeing.c

void	free_setnull(void **ptr);
void	free_if(void *ptr);
void	free_va(short amount, ...);
void	free_double_arr(char **arr);

#endif
