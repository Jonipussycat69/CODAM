/*TESTER*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

/*BZERO*/

void	checker(int	output, int correct);

int	main(void)
{
	const char	input[10] = "123456789";
	int	output = 0;

	printf("\033[1;35m\n ~ ft_bzero ~ TEST ~\n\n");
	/* 1 */
	printf("\033[1;37m 1 ~");
	output = ft_atoi("2147483647");checker(output, 2147483647);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 2147483647\n", output);
	printf("\n");
	
	/* 2 */
	printf("\033[1;37m 2 ~");
	output = ft_atoi("-2147483648");checker(output, -2147483648);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m -2147483648\n", output);
	printf("\n");
	
	/* 3 */
	printf("\033[1;37m 3 ~");
	output = ft_atoi("");checker(output, 0);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 0\n", output);
	printf("\n");
	
	/* 4 */
	printf("\033[1;37m 4 ~");
	output = ft_atoi(input);checker(output, 123456789);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 123456789\n", output);
	printf("\n");
	
	/* 5 */
	printf("\033[1;37m 5 ~");
	output = ft_atoi("t42");checker(output, 0);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 0\n", output);
	printf("\n");
	
	/* 6 */
	printf("\033[1;37m 6 ~");
	output = ft_atoi("00");checker(output, 0);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 0\n", output);
	printf("\n");
	
	/* 7 */
	printf("\033[1;37m 7 ~");
	output = ft_atoi("042-");checker(output, 42);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 42\n", output);
	printf("\n");
	
	/* 8 */
	printf("\033[1;37m 8 ~");
	output = ft_atoi(" 4 2");checker(output, 4);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 4\n", output);
	printf("\n");
	
	/* 9 */
	printf("\033[1;37m 9 ~");
	output = ft_atoi(" \t\r\v\n042");checker(output, 42);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 42\n", output);
	printf("\n");
	
	/* 10 */
	printf("\033[1;37m 10 ~");
	output = ft_atoi("42-42");checker(output, 42);
	printf("\033[0m Output:\033[1;36m %d\033[0m > Expected:\033[1;36m 42\n", output);
	printf("\n");
	printf("\033[0m");
	return (0);
}

void	checker(int	output, int correct)
{
	if (output == correct)
		printf("\033[1;32m (:\n");
	else
		printf("\033[1;31m ):\n");
	return ;
}