/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:22 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 18:34:18 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	int	i;
	int	destl;

	destl = ft_strlen(dest);
	i = 0;
	while (++i < n - destl)
		dest[destl + i] = src[i];
	dest[destl + i] = '\0';
	return (n);
}

int	main(void)
{
	char dest[20] = "Hello ";
	char src[] = "World";
	printf("mine: %ld\n", ft_strlcat(dest, src, 20));
	return 0;
}

/* NO TEST */