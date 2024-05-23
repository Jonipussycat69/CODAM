#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/wait.h>
# include <fcntl.h>

// cmd_a & cmd_b & path = malloced!

typedef struct s_pipex
{
	char	*file_a;
	char	*file_b;
	char	**cmd_a;
	char	**cmd_b;
	char	*path_a;
	char	*path_b;
	int		fd_in;
	int		fd_out;
	pid_t	pid_a;
	pid_t	pid_b;
}	t_pipex;

void	error_exit(t_pipex *p, const char *message, int error_code);
void	free_struct(t_pipex *p);
char	**ft_split(const char *s, const char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	free_double_arr(char **arr);
char	*path_find(char *cmd, char **envp);
void	init_null(t_pipex *p);

# endif
