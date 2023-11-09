#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*itoa_base(int value, int base, const char *rep, char *print)
{
	char	buf[65];
	char	*ptr;
	int	num;

	ptr = &buf[64];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		*--ptr = rep[value % base];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value /= base;
	}
	if (num < 0 && base == 10)
		*--ptr = '-';
	return (ft_strdup(ptr));
}

char	*test_itoa(int value, int base, char *print, int hex_type)
{
	const char	rep[] = "0123456789abcdef";
	const char	rep_up[] = "0123456789ABCDEF";

	if (base != 10 && value < 0)
		value *= -1;
	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	if (hex_type == 1)
		return (itoa_base(value, base, rep_up, print));
	else
		return (itoa_base(value, base, rep, print));
}

int	main(void)
{
	char	s1[] = "WORLD";
	char	s2[] = "WEIRD";
	int		i1 = 326327;
	int		i2 = 00000;
	int		i33 = 01234;
	int		i4 = INT_MAX;
	int		i5 = INT_MIN;
	int		i6 = 0;
	char	*test;

	int		i3 = i33;

	printf("original: %d\n", i3);
	printf("start\n");
	test = test_itoa(i1, 10, test, 1);
	if (!test)
	{
		printf("NULL\n"); return (0);
	}
	printf("itoabase: %s\n", test);
	free(test);
	test = test_itoa(i2, 10, test, 1);
	if (!test)
	{
		printf("NULL\n"); return (0);
	}
	printf("itoabase: %s\n", test);
	free(test);
	test = test_itoa(i3, 10, test, 1);
	if (!test)
	{
		printf("NULL\n"); return (0);
	}
	printf("itoabase: %s\n", test);
	free(test);
	test = test_itoa(i4, 10, test, 1);
	if (!test)
	{
		printf("NULL\n"); return (0);
	}
	printf("itoabase: %s\n", test);
	free(test);
	test = test_itoa(i5, 10, test, 1);
	if (!test)
	{
		printf("NULL\n"); return (0);
	}
	printf("itoabase: %s\n", test);
	free(test);
	// printf("HELLO %s, Is %s!\n\n", s1, s2);
	// ft_printf("HELLO %s, Is %s!", s1, s2);
	printf("\n");
	return (0);
}