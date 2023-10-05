/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlencpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:27 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/05 12:28:25 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlencpy(char *dest, const char *src, size_t n)
{
	int	i;

	i = 0;
	while (dest[i] != '\0' && src[i] != '\0' && n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	if (i > 0)
		dest[i] = '\0';
	return (i);
}

int	main(void)
{
	char	dest[20];
	char	src[] = "Hello World";
	printf("Mine: %zu", ft_strlencpy(dest, src, 6));
	// printf("sys: %d", strlcpy(dest, src, 6));
	return 0;
}

/* Not complete probably */