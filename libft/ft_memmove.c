/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:12 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/23 12:52:41 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	norm(unsigned char *d, unsigned char *s, size_t l)
{
	size_t	i;

	i = 0;
	while (l-- && d && s)
	{
		d[i] = s[i];
		i++;
	}
}

static void	rev(unsigned char *d, unsigned char *s, size_t l)
{
	size_t	i;

	if (l < ft_strlen((const char *)s))
		i = l - 1;
	else
		return ;
	while (l-- && d && s && i >= 0)
	{
		d[i] = s[i];
		i--;
	}
}

void	*ft_memmove(void *d, void *s, size_t size)
{
	unsigned char	*des;
	unsigned char	*src;

	des = (unsigned char *)d;
	src = (unsigned char *)s;
	if (d > s)
		rev(des, src, size);
	if (d < s)
		norm(des, src, size);
	return (d);
}

// int	main(void)
// {
// 	char s1[] = "Hallo";
// 	char s2[] = "Bye";
// 	printf("\nbefore: s1: %s\ns2: %s,\n\n", s1, s2);
// 	memmove((s1+2), s1, 10);
// 	printf("sys: s1: %s\ns2: %s,\n\n", s1, s2);
// 	char st1[] = "Hallo";
// 	char st2[] = "Bye";
// 	ft_memmove((st1+2), st1, 10);
// 	printf("mine: s1: %s\ns2: %s,\n\n", st1, st2);
// }