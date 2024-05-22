#include "pipex.h"

void	error_exit(const char *message, int error_code)
{
	perror(message);
	exit(error_code);
}

// strcmp, split, function to find the path (with access)

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}