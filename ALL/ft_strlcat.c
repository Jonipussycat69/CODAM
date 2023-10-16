/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:22 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/16 17:21:43 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

// size_t	ft_strlcat(char *dest, const char *src, size_t n)
// {
// 	size_t	i;
// 	size_t	destl;
// 	size_t	srcl;

// 	destl = ft_strlen(dest);
// 	srcl = ft_strlen(src);
// 	i = 0;
// 	if (n == 0)
// 		return (srcl);
// 	if (n < destl)
// 		return (srcl);
// 	while (i < n - 1 && src[i])
// 	{
// 		dest[destl + i] = src[i];
// 		i++;
// 	}
// 	if (i < n)
// 		dest[destl + i] = '\0';
// 	return (destl + srcl);
// }

// size_t	ft_strlcat(char *dest, const char *src, size_t n)
// {
// 	size_t	i;
// 	size_t	destl;
// 	size_t	srcl;

// 	destl = ft_strlen(dest);
// 	srcl = ft_strlen(src);
// 	i = 0;
// 	while (dest[i] && i < n)
// 		i++;
// 	// if (n > destl)
// 	// 	n = destl;
// 	while (src[i] && i < n)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (n + srcl);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	st;
	size_t	st2;

	st = 0;
	st2 = 0;
	while (*(dst + st))
		st++;
	while (*(src + st2))
	{
		if (st + st2 + 1 < size)
			*(dst + st + st2) = *(src + st2);
		st2++;
	}
	if (size <= st)
		return (st2 + size);
	if (st + st <= size)
		*(dst + st + st2) = '\0';
	else
		*(dst + size) = '\0';
	return (st + st2);
}

// REWRITE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// int	main(void)
// {
// 	char dest[20] = "Hello ";
// 	char src[] = "World";
// 	printf("mine: %ld\n", ft_strlcat(dest, src, 20));
// 	return 0;
// }

// /* NO TEST */