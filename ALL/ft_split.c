/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:55 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/17 19:28:56 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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
	return (i);
}

static char	*word(char const *s, int b, int e)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *) malloc((e - b + 1) * sizeof(char));
	if (!(word))
		return (NULL);
	while (b < e)
		word[i++] = s[b++];
	word[i] = '\0';
	return (word);
}

static void	freeer(char **arr, size_t i, size_t l)
{
	size_t	j;

	j = 0;
	while (j < l && j <= i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	int		b;

	arr = (char **) malloc((count(s, c) + 1) * sizeof(char *));
	if (!s || !(arr))
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
			if (!(arr[j - 1]))
			
			b = -1;//REEEEEWRITEEEEEEE!!!!!!!!!!!!!!!!!!!!!
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}

// int	main(void)
// {
// 	char **out;
// 	char s[] = "shahj,hsjahsjah,hs,s";
// 	out = ft_split(s, ',');
// 	printf("%s\n", out[0]);
// 	printf("%s\n", out[1]);
// 	printf("%s\n", out[2]);
// 	return 0;
// }
