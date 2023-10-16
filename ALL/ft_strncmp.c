/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:30 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/16 11:21:24 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i <= n)
	{
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	char s1[] = "1234";
// 	char s2[] = "1235";
// 	printf("mine: %d\n", ft_strncmp(s1, s2, 3));
// 	printf("sys: %d\n", strncmp(s1, s2, 3));
// 	return 0;
// }