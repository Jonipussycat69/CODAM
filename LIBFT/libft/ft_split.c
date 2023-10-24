/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:55 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/24 11:40:21 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	int		t;
	size_t	i;

	t = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && t == 0)
		{
			i++;
			t = 1;
		}
		else if (*s == c)
			t = 0;
		s++;
	}
	return (i);
}

static void	free_er(char **arr, size_t j)
{
	if (j > 1)
	{
		j--;
		while (j > 0)
		{
			free(arr[j]);
			j--;
		}
		free(arr[j]);
	}
	free(arr);
	return ;
}

static char	*word(char const *s, size_t b, size_t e)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc((e - b + 1) * sizeof(char));
	if (!(word))
		return (NULL);
	while (b < e && s[b])
	{
		word[i] = s[b];
		b++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**arr_word(char **arr, char const *s, char c, size_t i)
{
	int		b;
	size_t	j;

	b = -1;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && b < 0)
			b = i;
		else if (s[i] == c && b >= 0)
		{
			arr[j++] = word(s, b, i);
			if (!(arr[j - 1]))
			{
				free_er(arr, j - 1);
				return (NULL);
			}
			b = -1;
		}
		i++;
	}
	if (b < (int)i && b != -1)
		arr[j++] = word(s, b, i);
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	arr = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!(arr))
		return (NULL);
	if (arr_word(arr, s, c, i) == NULL)
		return (NULL);
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
