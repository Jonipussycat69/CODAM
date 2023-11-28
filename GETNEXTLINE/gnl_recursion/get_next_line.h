#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_variables
{
	size_t	i;
	size_t	j;
	size_t	l_len;
	size_t	b_len;
	size_t	rec;
	size_t	cat_len;
	ssize_t	btsr;
	int		error;
	int		checkpoint;
	char	*line;
	char	*tmp_line;
	char	*ret_line;
	char	*cat_line;
	char	*rem;
}	t_variables;

char	*get_next_line(int fd);
void	*free_line(char *line);
size_t	nl_len(char *str);
size_t	nl_check(char *str);

#endif