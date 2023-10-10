/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:48:57 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/10 14:03:02 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static unsigned int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*r;
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2) - 1;
	if (!(r = (unsigned char *) malloc(j * sizeof(unsigned char))));
		return (NULL);
	while (i++ < ft_strlen(s1))
		r[i] = s1[i];
	j = ft_strlen(s1);
	while (i++ < ft_strlen(s2))
		r[j++] = s1[i];
	r[j] = '\0';
	return (r);
}