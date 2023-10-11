#include <stdio.h>

static size_t	ft_strlen(char	*str, char c, size_t i)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	*arr;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	char	s1[ft_strlen(s, c, i)];
	i = ft_strlen(s, c, i);
	char	s2[ft_strlen(s, '\0', i)];
	if (!(arr = (char *) malloc(ft_strlen(s, '\0', i) * sizeof(char))))
		return (NULL);
	while (j++ < i)
		s1[j] = s[j];
	i = 0;
	s1[j] = '\0';
	while (j < ft_strlen(s, '\0', i))
		s2[i++] = s[j++];
	s2[i] = '\0';
	
}