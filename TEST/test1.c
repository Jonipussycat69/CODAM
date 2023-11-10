#include <stdio.h>

long long	test1(int i)
{
	long long	l;
	
	l = i;
	return (l);
}

int	main(void)
{
	int	i = 12345;
	long long	l = test1(i);
	char c[2];
	char b[] = "A";
	char a = 'A';
	
	c[0] = 'A';
	c[1] = '\0';
	printf("int: %i, %d\n", i, i);
	printf("long: %lli, %lld\n", l, l);
	printf("str c: %s, str b: %s, char a: %c\n", c, b, a);
	return (0);
}