#include "ft_printf.h"

static void test(int amount, int choice)
{
	char	s1[] = "WORLD";
	char	s2[] = "WEIRD";
	int		in1 = 326327;
	int		in2 = 00000;
	int		in3 = 01234;
	int		in4 = INT_MAX;
	int		in5 = INT_MIN;
	int		in6 = 0;
	char	*test = NULL;
	int		*testint = &in6;
	char	c = 'A';

	int		ft;
	int		origin;

	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;35mT1 \033[0m~~>\noriginal:\n\n");
		origin = printf("HELLO %s, Is %s!.1", s1, s2);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("HELLO %s, Is %s!.1", s1, s2);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	if ((amount > 1 || choice == 2) && (choice == 0 || choice == 2))
	{
		printf("\n\033[1;35mT2 \033[0m~~>\noriginal:\n\n");
		origin = printf("%s, %s", "BRUH", "12345");
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("%s, %s", "BRUH", "12345");
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	if ((amount > 2 || choice == 3) && (choice == 0 || choice == 3))
	{
		printf("\n\033[1;35mT3 \033[0m~~>\noriginal:\n\n");
		origin = printf("%c", c);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("%c", c);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	if ((amount > 3 || choice == 4) && (choice == 0 || choice == 4))
	{
		printf("\n\033[1;35mT4 \033[0m~~>\noriginal:\n\n");
		origin = printf("HELLO %s, Is %s!.1 %p, %% %c	=%p", s1, s2, test, c, testint);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("HELLO %s, Is %s!.1 %p, %% %c	=%p", s1, s2, test, c, testint);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	if ((amount > 4 || choice == 5) && (choice == 0 || choice == 5))
	{
		printf("\n\033[1;35mT5 \033[0m~~>\noriginal:\n\n");
		origin = printf("HELLO %s, Is %s!.1 %p, %% %c	=%p", s1, s2, test, c, testint);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("HELLO %s, Is %s!.1 %p, %% %c	=%p", s1, s2, test, c, testint);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	if ((amount > 5 || choice == 6) && (choice == 0 || choice == 6))
	{
		printf("\n\033[1;35mT6 \033[0m~~>\noriginal:\n\n");
		origin = printf("HELLO %s, Is %s!.1 %p, %% %c	=%p", s1, s2, test, c, testint);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("HELLO %s, Is %s!.1 %p, %% %c	=%p", s1, s2, test, c, testint);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	if ((amount > 6 || choice == 7) && (choice == 0 || choice == 7))
	{
		printf("\n\033[1;35mT7 \033[0m~~>\noriginal:\n\n");
		origin = printf("INTS: %i, %i, %i, %i, %i, %i", in1, in2, in3, in4, in5, in6);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("INTS: %i, %i, %i, %i, %i, %i", in1, in2, in3, in4, in5, in6);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	return ;
	//SEGFAULTS AT %i OR %d!!!!
	// DOES NOT WORK FOR EVERYTHING EXCEPT STR!
	// printf("\n");
}

int	main(void)
{
	printf("ENTERING TESTER\n");
	test(3, 0);
	printf("EXITTED TESTER\n");
	return (0);
}