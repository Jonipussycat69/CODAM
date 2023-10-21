/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:02 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/21 12:28:04 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char s = 's';
// 	printf("libft: %d\n", ft_isprint(s));
// 	printf("original: %d\n", isprint(s));
// 	return (0);
// }