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

static size_t	wlen(char const *s, char c, size_t b)
{
	size_t	i;
	size_t	j;
	int		t;

	j = 0;
	while (j <= b)
	{
		i = 0;
		t = 0;
		while (t < 1)
		{

		}
	}
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

static char	*word(char const *s, char c, size_t j)
{
	size_t	i;
	char	*w;

	i = 0;
	j = 0;
	w = (char *)malloc((wlen(s, c, j) + 1) * sizeof(char));
	if (!(w))
		return (NULL);
	while (i <= wlen(s, c, j))
	{

	}
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**arr;

	arr = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!(arr))
		return (NULL);
	while (j <= count(s, c))
	{
		arr[j] = word(s, c, j);
		if (!(arr[j]))
		{
			freeer(arr, j, count(s, c));
			return (NULL);
		}
		j++;
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
