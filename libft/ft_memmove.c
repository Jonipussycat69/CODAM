/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:12 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/13 13:39:22 by jdobos           ###   ########.fr       */
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
// 	int i1[] = {1, 2};
// 	int i2[] = {3, 4};
// 	printf("\nbefore: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
// 	memmove((s1+2), s1, 10);
// 	printf("sys: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
// 	char st1[] = "Hallo";
// 	char st2[] = "Bye";
// 	int in1[] = {1, 2};
// 	int in2[] = {3, 4};
// 	ft_memmove((st1+2), st1, 10);
// 	printf("mine: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", st1, st2, in1[0], in1[1], in2[0], in2[1]);
// }