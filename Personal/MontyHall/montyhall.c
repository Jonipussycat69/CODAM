#include "montyhall.h"

long long	check_inp(char *inp)
{
	short	i = 0;
	long	num = 0;

	if (!inp)
		return (0);
	while (inp[i])
	{
		if (inp[i] >= '1' && inp[i] <= '9')
			num = num * 10 + (inp[i] - '0');
		else
			return (0);
	}
	return (num);
}

short	core()
{
	return (ok);
}

short	montyhall(long amount)
{
	return (ok);
}

int	main(void)
{
	char	inp[19];
	long	i = 0;

	printf("\nInput amount of doors: ");
	i = scanf("%18s", inp);
	if (i <= 0)
		return (printf("\nINPUT ERROR\n"), 0);
	inp[i] = '\0';
	i = check_inp(inp);
	if (!i)
		return (printf("\nINPUT ERROR\n"), 0);
	montyhall(i);
	return (0);
}
