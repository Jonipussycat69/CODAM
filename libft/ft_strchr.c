/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:17 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/23 16:15:13 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (c == 0)
		return ((char *)str + i);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "String";
// 	char	c = 'i';
// 	printf("mine: %s\n", ft_strchr(s, c));
// 	printf("original: %s\n", strchr(s, c));
// 	return (0);
// }