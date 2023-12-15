#include "ft_printf.h"

int	main(void)
{
	int	ret;

	printf("\n");

	ret = printf("Hello %s i am |%d|", "man", -24546645);
	printf("\nreturn original: %d\n\n", ret);

	ret = ft_printf("Hello %s i am |%d|", "man", -24546645);
	printf("\nreturn ft_printf: %d\n\n", ret);
	return (0);
}
