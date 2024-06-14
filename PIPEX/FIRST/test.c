#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char	**ft_split(const char *s, const char c);

void	free_double_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}

int	main(void)
{
	char	str[] = "hallo:/dit/is/mijn/path:::::/hallo:";
	char	**split;

	printf("PATH: %i\n", _PC_PATH_MAX);
	split = ft_split(str, ':');
	if (!split)
		return (printf("error\n"), 1);
	printf("split: %s | %s\n", split[0], split[1]);
	free_double_arr(split);
	return (0);
}

// SPLIT

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

static size_t	count(char const *s, char c)
{
	int		t;
	size_t	words;

	t = 0;
	words = 0;
	while (*s)
	{
		if (*s != c && t == 0)
		{
			words++;
			t = 1;
		}
		else if (*s == c)
			t = 0;
		s++;
	}
	return (words);
}

static void	*free_er(char **arr, size_t word)
{
	while (word--)
		free(arr[word]);
	free(arr);
	return (NULL);
}

static char	*wordalloc(char const *s, char const c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, const char c)
{
	char	**arr;
	size_t	word;
	size_t	i;

	arr = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			arr[word] = wordalloc((char *)(s + i), c);
			if (!arr[word])
				return (free_er(arr, word));
			i += ft_strlen(arr[word]);
			word++;
		}
	}
	arr[word] = NULL;
	return (arr);
}
