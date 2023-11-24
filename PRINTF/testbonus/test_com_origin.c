// #include "ft_printf.h"
#include "ft_b_printf.h"
#include <sys/ioctl.h>

void	print_full_width(void)
{
	struct winsize	w;
	int				i;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	i = 0;
	while (i++ < w.ws_col)
		// markup(" ", -1, 45, 0);
		printf("\033[1;35m-\033[0m");
	printf("\n");
}

static void test_compare(int amount, int choice)
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

	int		ft;
	int		origin;

	// TEST 1
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;35mT1 \033[0m~~>\noriginal:\n\n");
		origin = printf(NULL);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf(NULL);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	// TEST 2
	if ((amount > 1 || choice == 2) && (choice == 0 || choice == 2))
	{
		printf("\n\033[1;35mT2 \033[0m~~>\noriginal:\n\n");
		origin = printf("%.s ", "abc");
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("%.s ", "abc");
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	// TEST 3
	if ((amount > 2 || choice == 3) && (choice == 0 || choice == 3))
	{
		printf("\n\033[1;35mT3 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %.2d ", 1);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf(" %.2d ", 1);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	// TEST 4
	if ((amount > 3 || choice == 4) && (choice == 0 || choice == 4))
	{
		printf("\n\033[1;35mT4 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %.8d ", INT_MAX);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf(" %.8d ", INT_MAX);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	// TEST 5
	if ((amount > 4 || choice == 5) && (choice == 0 || choice == 5))
	{
		printf("\n\033[1;35mT5 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %10.5i ", -9);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf(" %10.5i ", -9);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	// TEST 6
	if ((amount > 5 || choice == 6) && (choice == 0 || choice == 6))
	{
		printf("\n\033[1;35mT6 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %.6x ", 17);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf(" %.6x ", 17);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	// TEST 7
	if ((amount > 6 || choice == 7) && (choice == 0 || choice == 7))
	{
		printf("\n\033[1;35mT7 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %.1X ", -9);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf(" %.1X ", -9);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	// TEST 8
	if ((amount > 7 || choice == 8) && (choice == 0 || choice == 8))
	{
		printf("\n\033[1;35mT8 \033[0m~~>\noriginal:\n\n");
		origin = printf("ALL FLAGS: %-10s, %+10d, %0+10i, %u, %20p, %2c, %#15X, %%.", s1, in1, in1, uin1, testpint, c, 123);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("ALL FLAGS: %-10s, %+10d, %0+10i, %u, %20p, %2c, %#15X, %%.", s1, in1, in1, uin1, testpint, c, 123);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	// TEST 9
	if ((amount > 8 || choice == 9) && (choice == 0 || choice == 9))
	{
		printf("\n\033[1;35mT9 \033[0m~~>\noriginal:\n\n");
		origin = printf("ALL FLAGS: %-1wr0s, %+-----0010d, %0+10ri, %u, %20p, %2c, %#15X, %%.", in1, uin1, testpint, c, 123);
		printf("\n\nft_printf:\n\n");
		ft = ft_printf("ALL FLAGS: %-1wr0s, %+-----0010d, %0+10ri, %u, %20p, %2c, %#15X, %%.", in1, uin1, testpint, c, 123);
		printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	}
	return ;
}

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
		origin = printf(" NULL %c, %c NULL ", 0, 0);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 2
	if ((amount > 1 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT2 \033[0m~~>\noriginal:\n\n");
		origin = printf(" NULL %c, %c NULL ", 0, 0);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 3
	if ((amount > 2 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT3 \033[0m~~>\noriginal:\n\n");
		origin = printf(" NULL %c, %c NULL ", 0, 0);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 4
	if ((amount > 3 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT4 \033[0m~~>\noriginal:\n\n");
		origin = printf(" NULL %c, %c NULL ", 0, 0);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 5
	if ((amount > 4 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT5 \033[0m~~>\noriginal:\n\n");
		origin = printf(" NULL %c, %c NULL ", 0, 0);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 6
	if ((amount > 5 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT6 \033[0m~~>\noriginal:\n\n");
		origin = printf(" NULL %c, %c NULL ", 0, 0);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 7
	if ((amount > 6 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT7 \033[0m~~>\noriginal:\n\n");
		origin = printf(" NULL %c, %c NULL ", 0, 0);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 8
	if ((amount > 7 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT8 \033[0m~~>\noriginal:\n\n");
		origin = printf(" NULL %c, %c NULL ", 0, 0);
		printf("\n\nreturn: original: %d\n", origin);
	}
	return ;
}

int	main(void)
{
	int	range = 7;
	int	test = 0;
	int	type = 1;

	print_full_width();
	printf("\033[1;32m~ ENTERING TESTER ~\033[0m\n");
	if ((type == 1 || type == 3) && (range || test))
	{
		printf("\n\033[1;34mCOMPARISON TEST\033[0m\n");
		test_compare(range, test);
		printf("\n\033[1;34mCOMPARISON TEST <END>\033[0m\n");
	}
	if ((type == 2 || type == 3) && (range || test))
	{
		printf("\n\033[1;36mORIGINAL TEST\033[0m\n");
		test_origin(range, test);
		printf("\n\033[1;36mORIGINAL TEST <END>\033[0m\n");
	}
	printf("\n\033[1;32m~ EXITTED TESTER ~\033[0m\n");
	print_full_width();
	return (0);
}