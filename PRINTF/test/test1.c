#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t		nl;
	size_t		i;

	if (!(*needle))
		return ((char *)hay);
	nl = ft_strlen(needle);
	while (*hay && n-- >= nl)
	{
		i = 0;
		while (needle[i] && hay[i] == needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}

size_t	my_strchr(const char *h, char c)
{
	size_t	i;

	i = 0;
	while (h[i])
	{
		if (h[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (0);
}

size_t	arg_write(const void *arg, int fd)
{
	write(fd, arg, ft_strlen(arg));
	return (0);
}

int	ft_printf(const char *form, ...)
{
	va_list		args;
	va_start	(args, form);
	size_t		i;
	const void	*arg;
	size_t		chwritten;
	int			fd;

	fd = 1;
	i = 0;
	arg = va_arg(args, const char *);
	while (form[i])
	{
		if (form[i] == '%')
		{
			chwritten += arg_write(arg, fd);//NOT ITERATING TO SECOD ARG!
			// while (form[i] != ' ' && form[i])
			// 	i++;
			i += 2;
		}
		write(fd, &(form[i]), 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char	s1[] = "WORLD";
	char	s2[] = "WEIRD";
	printf("HELLO %s, Is %s!\n\n", s1, s2);
	ft_printf("HELLO %s, Is %s!", s1, s2);
	printf("\n");
	return (0);
}