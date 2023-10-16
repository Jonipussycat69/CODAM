/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:03:49 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/15 14:09:26 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*r;
	size_t			i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		r = (unsigned char *) malloc(1);
		if (!r)
			return (NULL);
		*r = '\0';
		return ((void *)r);
	}
	r = (unsigned char *) malloc(nmemb * size);
	if (!r)
		return (NULL);
	while (i < nmemb * size)
	{
		r[i] = '\0';
		i++;
	}
	return ((void *)r);
}
