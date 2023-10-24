/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:32 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/23 12:41:06 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

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

// int main(void)
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	char * empty = (char*)"";
// 	printf("\n%d\n", ft_strnstr(haystack, "abcd", 9) == haystack + 5);
// 	printf("\n%s\n", ft_strnstr(empty, "", 0));
// 	return (0);
// }