#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	*file_a;
	char	*file_b;
	char	*cmd_a;
	char	*cmd_b;
	int		fd_in;
	int		fd_out;
	pid_t	pid_a;
	pid_t	pid_b;
}	t_pipex;

void error_exit(const char *message);

# endif
