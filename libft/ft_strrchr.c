/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:35 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/23 11:19:18 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

const char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (c > 127)
		return (str);
	while (i > 0 && str[i] != c)
	{
		i--;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "String String";
// 	char	c = 'i';
// 	printf("mine: %s\n", ft_strchr(s, c));
// 	printf("original: %s\n", strchr(s, c));
// 	return (0);
// }