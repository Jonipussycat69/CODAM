#include "ft_printf.h"

int	main(void)
{
	char	s1[] = "WORLD";
	char	s2[] = "WEIRD";
	int		i1 = 326327;
	int		i2 = 00000;
	int		i3 = 01234;
	int		i4 = INT_MAX;
	int		i5 = INT_MIN;
	int		i6 = 0;
	char	*test;

	int		ft;
	int		origin;

	printf("\n\noriginal:\n\n");
	origin = printf("HELLO %s, Is %s!.1 %i", s1, s2, i1);
	printf("\n\nft_printf:\n\n");
	ft = ft_printf("HELLO %s, Is %s!.1 %i", s1, s2, i1);//SEGFAULTS AT %i OR %d!!!!

	printf("\n\nreturns: original: %d, ft: %d\n", origin, ft);
	// printf("\n");
	return (0);
}