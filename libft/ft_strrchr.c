/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:35 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/23 16:16:43 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "String String";
// 	char	c = 'i';
// 	printf("mine: %s\n", ft_strrchr(s, c));
// 	printf("original: %s\n", strrchr(s, c));
// 	return (0);
// }