#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	count(char const *s, char c)
{
	int		t;
	size_t	i;

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

static void	freeer(char **arr, size_t j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
	return ;
}

static char	*word(char const *s, size_t b, size_t e, char **arr, size_t j)
{
	char	*word;
	size_t	i;
	
	word = (char *)malloc((e - b + 1) * sizeof(char));
	if (!(word))
	{
		freeer(arr, j);
		return (NULL);
	}
	while (b <= e && s[b])
	{
		word[i] = s[b];
		b++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		b;
	char	**arr;

	arr = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!(arr))
		return (NULL);
	i = 0;
	j = 0;
	b = -1;
	while (s[i])
	{
		if (s[i] != c && b < 0)
			b = i;
		else if (s[i] == c && b >= 0)
		{
			arr[j++] = word(s, b, i, arr, j);
			if (!(arr[j - 1]))
				return (NULL);
			b = -1;
		}
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
