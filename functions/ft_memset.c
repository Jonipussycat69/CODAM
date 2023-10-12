/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:14 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 14:55:31 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t l)
{
	void	*t;
	
	t = b;
	while (l-- && b)
		*(unsigned char *)b++ = c;
	return (t);
}

int	main(void)
{
	char s1[] = "Hello";
	char s2 = '1';
	int i1[] = {1, 2};
	int i2[] = {3, 4};
	printf("b sys: %s\n", s1);
	// printf("\nbefore: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
	memset(s1, 50, 3);
	printf("a sys: %s\n", s1);
	// printf("sys: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
	char st1[] = "Hello";
	char st2 = '1';
	int in1[] = {1, 2};
	int in2[] = {3, 4};
	ft_memset(st1, 50, 3);
	printf("a mine: %s\n", st1);
	// printf("mine: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", st1, st2, in1[0], in1[1], in2[0], in2[1]);
}