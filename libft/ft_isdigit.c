/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:03:59 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/21 12:27:36 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

// int	main(void)
// {
// 	char s = 's';
// 	printf("libft: %d\n", ft_isdigit(s));
// 	printf("original: %d\n", isdigit(s));
// 	return (0);
// }