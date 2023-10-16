/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:27 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/16 12:46:38 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (n == 0)
		return (slen);
	if (n > 0)
		n--;
	while (dest[i] && src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (slen);
}

// int	main(void)
// {
// 	char	dest[20];
// 	char	src[] = "Hello World";
// 	printf("Mine: %zu", ft_strlencpy(dest, src, 6));
// 	// printf("sys: %d", strlcpy(dest, src, 6));
// 	return 0;
// }

// /* Not complete probably */