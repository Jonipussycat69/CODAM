/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:12:53 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/30 12:36:34 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// size_t	my_strstr(const char *h, char *n)
// {
// 	size_t	nl;
// 	size_t	i;
// 	size_t	j;
// 	const char	*temp;

// 	if (!(*n))
// 		return (0);
// 	printf("%s\n", n);
// 	nl = ft_strlen(n);
// 	j = 0;
// 	while (h[j] && ft_strlen(h + j) >= nl)
// 	{
// 		i = 0;
// 		temp = h + j;
// 		while (n[i] && temp[i] == n[i])
// 			i++;
// 		if (n[i] == '\0')
// 			return (j);
// 		j++;
// 	}
// 	return (0);
// }

const char	*skip(const char *form)
{
	form = ft_strchr(form, '%');
	if (!(form))
		return (NULL);
	while (*form && *form != ' ')
		form++;
	return (form);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	va_start(args, form);
	size_t	i;
	const void	*arg;
	char	*temp;
	int		fd;

	fd = 1;
	arg = va_arg(args, const char *);
	while (*form)
	{
		i = my_strchr(form, '%') + 1;
		printf("%zu\n", i);
		temp = (char *)malloc(i + 1);
		if (!(temp))
			return (0);
		temp[i] = '\0';
		ft_strlcpy(temp, form, i);
		write(fd, temp, ft_strlen(temp));
		if (ft_strnstr(form, "%c", ft_strlen(form)))
			write(fd, arg, 1);
		else if (ft_strnstr(form, "%s", ft_strlen(form)))
			write(fd, arg, ft_strlen(arg));
		free(temp);
		form = skip(form);
		if (!(form))
			break ;
	}
	va_end(args);
	write(fd, "\n", 1);
	return (0);
}

//DOESNT WORK FOR SHIT!!

int	main(void)
{
	char	s1[] = "WORLD";
	char	s2[] = "WEIRD";
	ft_printf("HELLO %s, Is %s!", s1, s2);
	return (0);
}