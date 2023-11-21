#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

#include <sys/ioctl.h>

void	print_full_width(void)// FUNCTION TO PRINT WHOLE WITH OF TERMINAL.
{
	struct winsize	w;
	int				i;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	i = 0;
	while (i++ < w.ws_col)
		// markup(" ", -1, 45, 0);
		printf("\033[1;35m~\033[0m");
	printf("\n");
}

void	markup(char *str, ...)// FUNCTION FOR PRINTF FORMATTING. ALWAYS LAST INPUT = 0!
{
	va_list	style;
	int		num_styles;
	int		minus_check;

	num_styles = 0;
	va_start(style, str);
	while (va_arg(style, int) != 0)
		num_styles++;
	va_end(style);
	va_start(style, str);
	if (num_styles == 0)
		printf("\n%s\n", str);
	else if (num_styles > 0)
	{
		minus_check = va_arg(style, int);
		if (minus_check == -1 && printf("\033[45m%s\033[0m", str))
			return ;
		printf("\n\033[%d", minus_check);
		while (--num_styles)
			printf(";%d", va_arg(style, int));
		printf("m%s\033[0m\n", str);
	}
	va_end(style);
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

	// POSSIBLE FLAGS:> +, (space), # <&&> -, (width num), 0 <

	// TEST 1
	if ((amount > 0 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT1 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %.x ", 17);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 2
	if ((amount > 1 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT2 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %.6x ", 17);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 3
	if ((amount > 2 || choice == 3)&& (choice == 0 || choice == 3))
	{
		printf("\n\033[1;37mT3 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %8.6x ", 17);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 4
	if ((amount > 3 || choice == 4)&& (choice == 0 || choice == 4))
	{
		printf("\n\033[1;37mT4 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %.6d ", 17);
		printf("\n\nreturn: original: %d\n", origin);
	}
	// TEST 5
	if ((amount > 4 || choice == 1)&& (choice == 0 || choice == 1))
	{
		printf("\n\033[1;37mT5 \033[0m~~>\noriginal:\n\n");
		origin = printf(" %10.d ", 17);
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
	int	range = 5;
	int	test = 0;

	print_full_width();
	markup("~ ENTERING TESTER ~ ", 1, 32, 0);
	// printf("\033[1;32m~ ENTERING TESTER ~\033[0m\n");
	if (range || test)
	{
		printf("\n\033[1;36mORIGINAL TEST\033[0m\n");
		test_origin(range, test);
		printf("\n\033[1;36mORIGINAL TEST <END>\033[0m\n");
	}
	printf("\n\033[1;32m~ EXITTED TESTER ~\033[0m\n");
	print_full_width();
	return (0);
}