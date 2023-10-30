#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

static int	ft_malloc(const char *start, const char *end, char **r)
{
	int		len;

	len = end - start;
	*r = (char *)malloc((len + 1) * sizeof(char));
	if (!*r)
		return (0);
	if (!ft_strlcpy(*r, start, len + 1))
		return (0);
	return (1);
}

static int	ft_words(const char *s, char c, char **res, int *w_index)
{
	char	*start;

	start = (char *)s;
	while (*s)
	{
		if (*s != c)
			s++;
		else
		{
			if (start != s && ft_malloc(start, s, &res[(*w_index)++]) == 0)
				return (0);
			start = (char *)++s;
		}
	}
	if (start != s && ft_malloc(start, s, &res[(*w_index)++]) == 0)
		return (0);
	*(res + *w_index) = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		w_index;
	int		i;

	result = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	w_index = 0;
	if (ft_words(s, c, result, &w_index) == 0)
	{
		i = 0;
		while (w_index > i)
			free(result[i++]);
		free(result);
		return (NULL);
	}
	return (result);
}

//S

#include "libft.h"

static int	ft_splitcount(const char *s, const char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_splitdup(const char *s, const char c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	*ft_freeall(char **array, int row)
{
	while (row--)
		free(array[row]);
	free(array);
	return (NULL);
}

char	**ft_split(const char *s, const char c)
{
	char	**array;
	int		row;
	int		i;

	row = 0;
	i = 0;
	array = (char **)malloc((ft_splitcount(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			array[row] = ft_splitdup((char *)(s + i), c);
			if (!array[row])
				return (ft_freeall(array, row));
			i += ft_strlen(array[row]);
			row++;
		}
	}
	array[row] = NULL;
	return (array);
}