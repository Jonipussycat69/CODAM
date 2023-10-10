/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:55 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/10 19:19:34 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(char	*str, char c, size_t i)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;
	char	*arr[];

	i = 0;
	j = 0;
	if (!(s1 = (char *) malloc(ft_strlen(s, c, i) * sizeof(char))))
		return (NULL);
	if (!(s2 = (char *) malloc(ft_strlen(s, '\0', i) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i++] != c)
		s1[i] = s[i];
	s1[i] = '\0';
	i++;
	while (s[i++])
		s2[j] = s[i];
	s2[i] = '\0';
	
}
