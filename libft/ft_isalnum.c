/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:03:52 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/21 12:25:51 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char s = 's';
// 	printf("libft: %d\n", ft_isalnum(s));
// 	printf("original: %d\n", isalnum(s));
// 	return (0);
// }
