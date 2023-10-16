/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:32 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/16 17:07:23 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

// static int	mystrcmp(const char *hay, const char *needle, int n)
// {
// 	while (*hay == *needle && n > 0 && *hay != '\0' && *needle != '\0')
// 	{
// 		hay++;
// 		needle++;
// 		n--;
// 	}
// 	if (*needle == '\0')
// 		return (0);
// 	return (1);
// }

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	nl;

	if (*needle == '\0')
		return ((char *)hay);
	nl = ft_strlen(needle);
	if (nl < 2)
		nl--;
	if (n > 1)
		n--;
	while (*hay != '\0' && *needle != '\0' && n > 0)
	{
		if (*hay == *needle)
			if (ft_strncmp(hay, needle, nl) == 0)
				return ((char *)hay);
		hay++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	s1[] = "this is a string";
// 	char	s2[] = "is";
// 	printf("mine: %s\n", ft_strnstr(s1, s2, 10));
// 	// printf("sys: %s\n", strnstr(s1, s2, 10));
// 	return (0);
// }

// /* Not tested! */


// int main(void)
// {
// 	// char haystack[30] = "aaabcabcd";
// 	// char needle[10] = "aabc";
// 	char * empty = (char*)"";
// 	// ft_strnstr(haystack, needle, -1) == haystack + 1

// 	// printf("\n%d\n", ft_strnstr(haystack, "abcd", 9) == haystack + 5);

// 	printf("\n%s\n", ft_strnstr(empty, "", 0));
// 	return (0);
// }