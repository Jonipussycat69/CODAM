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

	// TEST 1
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT1 \033[0m~~>\noriginal:\n\n");
		origin = printf("NULL%5c|%-5cNULL", 'A', 'A');
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 2
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT2 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%5s|%-5s<", "Hi", "Hi");
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 3
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT3 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%0   5d|% -5d<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 4
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT4 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%#X|%#x<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 5
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT5 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%06X|%6x<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 6
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT6 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%0#8X|%-#8x<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 7
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT7 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%#X|%#x<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 8
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT8 \033[0m~~>\noriginal:\n\n");
		origin = printf(">%#X|%#x<", 42, 42);
		printf("\n\nreturn: original: %d\n", origin);
	}
	return ;
}

int	main(void)
{
	int	range = 8;
	int	test = 0;

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