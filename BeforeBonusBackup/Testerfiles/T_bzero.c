/*TESTER*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

/*BZERO*/

void	checker(char *str);

int	main(void)
{
	void	*str;
	
	str = my_malloc();

	printf("\033[1;35m\n ~ ft_bzero ~ TEST ~\n\n");
	/* 1 */
	printf("\033[1;37m 1 ~");
	memset(str, 65, 10);
	ft_bzero(str, 10);checker(str);
	printf("\033[0m Expected:\033[1;36m 0000000000\n");
	printf("\n");
	
	/* 2 */
	printf("\033[1;37m 2 ~");
	memset(str, 65, 10);
	ft_bzero(str, 10);checker(str);
	printf("\033[0m Expected:\033[1;36m 0000000000\n");
	printf("\n");

	printf("\033[0m");
	return (0);
}

void	checker(char *str)
{
	void	*compare;
	
	compare = (char *)malloc(10 * sizeof(char));
	if (!(compare))
	{
		printf("\033[1;35m CHECK ALLOCATION FAILED! \033[0m");
		return (NULL);
	}
	bzero(compare, 10);
	if (memcmp(str, compare, 10) == 0)
		printf("\033[1;32m (:\n");
	else
		printf("\033[1;31m ):\n");
	free(str);
	free(compare);
	return ; 
}

void	*my_malloc()
{
	void	*str;
	str = (void *)malloc(10 * sizeof(char));
	if (!(str))
	{
		printf("\033[1;35m TEST ALLOCATION FAILED! \033[0m");
		return (NULL);
	}
	return (str);
}