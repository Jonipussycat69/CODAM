/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:55:23 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/10 18:41:37 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	check(char const ch, char const *set)
{
	while (set)
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	t[ft_strlen(s1)];
	char	*r;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check(s1[i], set) == 1)
		i++;
	while (check(s1[i], set) == 0)
		t[j++] = s1[i++];
	while (check(s1[i], set) == 1)
		i++;
	if (!(r = (char *) malloc(j * sizeof(char))));
		return (NULL);
	i = 0;
	while (t[i])
	{
		r[i] = t[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}