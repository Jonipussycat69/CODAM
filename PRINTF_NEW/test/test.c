#include "ft_printf.h"

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

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

int main()
{
    setlocale(LC_CTYPE, "");
    wchar_t star = 0x2605;
    wprintf(L"%lc\n", star);
}
