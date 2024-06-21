#ifndef MINISH_DEF_H
# define MINISH_DEF_H

// Colors

# define C_RESET "\033[0m"
# define C_TEAL "\033[0;36m"
# define C_YELLOW "\033[0;33m"
# define C_RED "\033[31;1m"

// Typedefs

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

// Enums

enum	e_function_return
{
	SUCCESS = 1,
	NEUTRAL = 0,
	ERROR = -1,
	MEM_ERR = -2,
	SYNTAX_ERR = -3
};

enum	e_tokens
{
	NO_ACTION = 0,
	CMD = 1,
	FILE = 2,
	BUILTIN = 3,
	PIPE = 4,
	REDIR = 5,
	ENV_VAR = 6
};

// STRUCTS

// Cmd and arg structs

typedef struct s_cmd_node
{
	char	*content;
	void	*next;
}	t_cmd_node;

typedef struct s_significant_argument
{
	t_cmd_node	**cmd_head; // can be used as single pointer, head stored in sig_argument node only
	char		**cmd_array;
	short		token;
	void		*next;
}	t_sig_arg;

typedef struct s_father_of_all_structs
{
	t_sig_arg	**sig_arg_head;
	char		*prev_line;
	char		*line;
}	t_dad;

#endif
