/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:55 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/11 12:38:41 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	count(char const *s, char c)
{
	int	i;
	int	temp;


	i = 0;
	while (*s)
	{
		if (*s != c && temp == 0)
		{
			temp = 1;
			i++;
		}
		else if (*s == c)
			temp = 0;
		s++;
	}
}

static char	*word(char const *s, int b, int e)
{
	char	*word;
	size_t	i;

	i = 0;
	if (!(word = (char *) malloc((e - b + 1) * sizeof(char))))
		return (NULL);
	while (b < e)
		word[i++] = s[b++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	int	b;

	if (!s || !(arr = (char **) malloc((count(s, c)+1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	b = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && b < 0)
			b = i;
		else if (s[i] == c && b >= 0)
		{
			arr[j++] = word(s, b, i);
			b = -1;
		}
		i++;
	}
	arr[j] = 0;/* ????????????????????????????????? */
	return (arr);
}
