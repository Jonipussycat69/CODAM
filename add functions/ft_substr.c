/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:32:47 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/10 12:51:22 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	int	i;

	if (!(r = (char *) malloc(len)))
		return (NULL);
	i = 0;
	while (len--)
		r[i++] = s[start++];
	return (r);
}