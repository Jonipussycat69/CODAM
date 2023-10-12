/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:03:49 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 18:33:15 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t c, size_t l)
{
	if (c <= 0 || l <= 0)
		return (NULL);
	unsigned char	*r;
	int	i;

	i = 0;
	if (!(r = (unsigned char *) malloc(c * sizeof(l))));
		return (NULL);
	while (i < c)
		r[i++] = '\0';
	return ((void *)r);
}