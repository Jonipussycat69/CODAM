#include "libft.h"

int	form_check(char *format, int i, char *print)
{
	
}

int	get_arg(void *arg, int specifier, char *print)
{
	
}

size_t	specifier_skip(int specifier)
{
	
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	size_t	i;
	int		specifier;
	char	*print;

	i = 0;
	specifier = 0;
	print = ft_strdup("");
	while (format[i])
	{
		specifier = form_check(format, i, print);
		if (specifier < 0)
			return (-1);
		if (specifier > 0 && specifier < 10)
			specifier = get_arg(va_arg(args, void *), specifier, print);
		if (specifier < 0)
			return (-1);
		i += specifier_skip(specifier);
	}
	i = ft_strlen(print);
	write(1, print, i);
	if (print)
		free(print);
	return (i);
}
