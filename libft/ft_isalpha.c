/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:03:55 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/21 12:26:36 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char s = 's';
// 	printf("libft: %d\n", ft_isalpha(s));
// 	printf("original: %d\n", isalpha(s));
// 	return (0);
// }