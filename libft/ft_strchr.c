/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:17 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/16 11:04:02 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	
	i = 0;
	if (c > 127)
		return (str);
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return (str + i);
	return (NULL);
}