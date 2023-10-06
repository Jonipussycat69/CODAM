#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "Hello";
	char s2[] = "Bye";
	int i1[] = {1, 2};
	int i2[] = {3, 4};
	printf("before: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
	memmove(s1, s2, 4);
	printf("sys: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
	char s1[] = "Hello";
	char s2[] = "Bye";
	int i1[] = {1, 2};
	int i2[] = {3, 4};
	ft_memmove(s1, s2, 4);
	printf("mine: s1: %s\ns2: %s,\ni1[0]: %d, i1[1]: %d, i2[0]: %d, i2[1]: %d\n\n", s1, s2, i1[0], i1[1], i2[0], i2[1]);
}