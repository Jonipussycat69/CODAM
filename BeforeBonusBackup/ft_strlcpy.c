/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:27 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/17 13:30:15 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

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

// int	main(void)
// {
// 	char	dest[] = "AAAAAAAAAA";
// 	char	src[] = "coucou";
// 	printf("Mine: %zu\n", ft_strlcpy(dest, src, 2));
// 	printf("Mine: %d\n", ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'c' && dest[1] == 0  && dest[2] == 'A');
// 	// printf("sys: %d", strlcpy(dest, src, 6));
// 	return 0;
// }

// int	main(void)
// {
// 	char	dest[] = "AAAAAAAAAA";
// 	char	src[] = "coucou";
// 	printf("Mine: %zu\n", ft_strlcpy(dest, src, -1));
// 	printf("Mine: %d\n", ft_strlcpy(dest, src, -1) == strlen(src) && !strcmp(src, dest) && dest[strlen(src) + 1] == 'A');
// 	// printf("sys: %d", strlcpy(dest, src, 6));
// 	return 0;
// }

// /* Not complete probably */