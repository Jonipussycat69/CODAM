/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:12 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 19:48:19 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *d, void *s, size_t size)
{
	unsigned char	*des;
	unsigned char	*src;
	size_t			i;

	des = (unsigned char *)d;
	src = (unsigned char *)s;
	i = 0;
	if (d > s)
	{
		while (size--)
		{
			des[i] = src[i];
		}
	}
	if (d < s)
	{
		while (size-- && d && s)
		{
			des[i] = src[i];
		}
	}
	return (d);
}

// int	main(void)
// {
// 	char s1[] = "Hello";
// 	char s2[] = "Bye";
// 	int i1[] = {1, 2};
// 	int i2[] = {3, 4};
// 	printf("\nbefore: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
// 	memmove((s1+2), s1, 2);
// 	printf("sys: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
// 	char st1[] = "Hello";
// 	char st2[] = "Bye";
// 	int in1[] = {1, 2};
// 	int in2[] = {3, 4};
// 	ft_memmove((st1+2), st1, 2);
// 	printf("mine: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", st1, st2, in1[0], in1[1], in2[0], in2[1]);
// }