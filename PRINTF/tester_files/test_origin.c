#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

static void test_origin(int amount, int choice)
{
	char	s1[] = "WORLD";
	char	s2[] = "WEIRD";
	int		in1 = -326327;
	int		in2 = 00000;
	int		in3 = 01234;
	int		in4 = INT_MAX;
	int		in5 = INT_MIN;
	int		in6 = 0;
	unsigned int	uin1 = UINT_MAX;
	char	*testp = NULL;
	int		*testpint = &in6;
	char	c = 'A';

	int		origin;

	// POSSIBLE FLAGS:> +, (space), # <&&> -, (width num), 0 <

	// TEST 1
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT1 \033[0m~~>\noriginal:\n\n");
		origin = printf("ALL FLAGS: %-10s, %+10d, %0+10i, % u, %015p, %2c, %#15X, %%.", s1, in1, in1, uin1, testpint, c, 123);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 2
	if ((amount > 1 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT2 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%5s|%-5s<", "Hi", "Hi");
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 3
	if ((amount > 2 || choice == 3)&& (choice == 0 || choice == 3))
	{
		printf("\n\033[1;37mT3 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%0 4%i%i|%0+d<", 42, -42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 4
	if ((amount > 3 || choice == 4)&& (choice == 0 || choice == 4))
	{
		printf("\n\033[1;37mT4 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%0#5x|%#x<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 5
	if ((amount > 4 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT5 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%-6c|%6c<", '4', '4');
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 6
	if ((amount > 5 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT6 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%0#8X|%-#8x<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 7
	if ((amount > 6 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT7 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%-3p|%3p<", testpint, testpint);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 8
	if ((amount > 7 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT8 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%#X|%#x<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	return ;
}

int	main(void)
{
	int	range = 1;
	int	test = 1;

	printf("\033[1;32m~ ENTERING TESTER ~\033[0m\n");
	if (range || test)
	{
		printf("\n\033[1;36mORIGINAL TEST\033[0m\n");
		test_origin(range, test);
		printf("\n\033[1;36mORIGINAL TEST <END>\033[0m\n");
	}
	printf("\n\033[1;32m~ EXITTED TESTER ~\033[0m\n");
	return (0);
}