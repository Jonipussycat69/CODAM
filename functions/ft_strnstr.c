/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:32 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 18:34:37 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	mystrcmp(const char *hay, const char *needle, int n)
{
	while (*hay == *needle && n > 0 && *hay != '\0' && *needle != '\0')
	{
		hay++;
		needle++;
		n--;
	}
	if (*needle == '\0')
		return (0);
	return (1);
}

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	if (!(needle))
		return (hay);
	while (*hay != '\0' && *needle != '\0' && n > 0)
	{
		if (*hay == *needle)
			if (mystrcmp(hay, needle, n) == 0)
				return ((char *)hay);
		hay++;
		n--;
	}
	return (NULL);
}

int	main(void)
{
	char	s1[] = "this is a string";
	char	s2[] = "is";
	printf("mine: %s\n", ft_strnstr(s1, s2, 10));
	// printf("sys: %s\n", strnstr(s1, s2, 10));
	return (0);
}

/* Not tested! */