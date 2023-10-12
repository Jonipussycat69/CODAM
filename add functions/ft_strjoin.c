/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:48:57 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 14:37:27 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static unsigned int	ft_strlen(const char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(r = (char *) malloc(j * sizeof(char))))
		return (NULL);
	j = ft_strlen(s1);
	while (i < j)
	{
		r[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
		r[j++] = s2[i++];
	r[j] = '\0';
	return (r);
}

int	main(void)
{
	char *out;
	char s[] = "Mother ";
	char s2[] = "trucker";
	out = ft_strjoin(s, s2);
	printf("%s\n", out);
	return (0);
}