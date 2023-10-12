/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:07 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 18:50:23 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ls1;
	const unsigned char	*ls2;

	ls1 = (const unsigned char*)s1;
	ls2 = (const unsigned char*)s2;
	while (*ls1 == *ls2 && *ls1 != '\0' && *ls2 != '\0' && n > 0)
	{
		ls1++;
		ls2++;
		n--;
	}
	return (*ls1 - *ls2);
}

// int	main(void)
// {
// 	char s1[] = "Hello world";
// 	char s2[] = "Hello world";
// 	printf("mine: %d\n", ft_memcmp(s1, s2, 10));
// 	printf("sys: %d\n", memcmp(s1, s2, 10));
// 	return 0;
// }