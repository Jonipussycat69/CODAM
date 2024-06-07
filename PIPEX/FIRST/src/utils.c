/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/23 13:58:41 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/07 16:50:41 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_exit(t_pipex *p, char *message, int error_code)
{
	const char	*nill = "\0";

	free_struct(p);
	if (message == NULL)
		message = (char *)nill;
	dup2(STDERR_FILENO, STDOUT_FILENO);
	if (error_code == 127)
		ft_printf("pipex: command not found: %s\n", message);
	else
		ft_printf("pipex: %s: %s\n", strerror(errno), message);
	exit(errno);
}

void	free_struct(t_pipex *p)
{
	free(p->path_a);
	free(p->path_b);
	if (p->cmd_a)
		free_double_arr(p->cmd_a);
	if (p->cmd_b)
		free_double_arr(p->cmd_b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (a[i] == b[i] && a[i] && b[i] && i < n - 1)
		i++;
	return (a[i] - b[i]);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (slen + size);
	i = dlen;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

void	init_null(t_pipex *p)
{
	p->cmd_a = NULL;
	p->cmd_b = NULL;
	p->path_a = NULL;
	p->path_b = NULL;
}

int	wait_secure(t_pipex *p, int pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
		error_exit(p, "Waitpid error", errno);
	while (wait(NULL) != -1)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (errno);
}
