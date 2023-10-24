/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:14 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/23 12:11:06 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t l)
{
	void	*t;

	t = b;
	while (l-- && b)
		*(unsigned char *)b++ = c;
	return (t);
}

// int	main(void)
// {
// 	char s1[] = "Hello";
// 	char s2 = '1';
// 	printf("b sys: %s\n", s1);
// 	memset(s1, 50, 3);
// 	printf("a sys: %s\n", s1);
// 	char st1[] = "Hello";
// 	char st2 = '1';
// 	ft_memset(st1, 50, 3);
// 	printf("a mine: %s\n", st1);
// }