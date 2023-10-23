/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:22 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/23 11:26:18 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

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

// int	main(void)
// {
// 	char dest[20] = "Hello ";
// 	char src[] = "World";
// 	printf("mine: %ld\n", ft_strlcat(dest, src, 20));
// 	return 0;
// }