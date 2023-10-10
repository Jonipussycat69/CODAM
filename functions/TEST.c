#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *d, void *s, size_t size)
{
	int	n;
	int	i;
	
	n = ft_strlen(s);
	unsigned char	t[n];
	i = 0;
	while (t[i])
	{
		t[i++] = *(unsigned char *)s++;
	}
	i = 0;
	while (size-- > 0)
	{
		*(unsigned char *)d++ = t[i++];
	}
	return (d);
}

int	main(void)
{
	char s1[] = "Hemmo";
	char s2[] = "Bye";
	int i1[] = {1, 2};
	int i2[] = {3, 4};
	printf("\nbefore: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
	memmove((s1+2), s1, 2);
	printf("sys: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
	char st1[] = "Hemmo";
	char st2[] = "Bye";
	int in1[] = {1, 2};
	int in2[] = {3, 4};
	ft_memmove((st1+2), st1, 2);
	printf("mine: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", st1, st2, in1[0], in1[1], in2[0], in2[1]);
}