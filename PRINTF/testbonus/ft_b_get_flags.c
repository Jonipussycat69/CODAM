#include "ft_printf.h"

int	spf(const char *form, int i)
{
	if (form[i] != '%')
		return (0);
	if (form[i] == 'c')
		return (1);
	if (form[i] == 's')
		return (2);
	if (form[i] == 'p')
		return (3);
	if (form[i] == 'd')
		return (4);
	if (form[i] == 'i')
		return (5);
	if (form[i] == 'u')
		return (6);
	if (form[i] == 'x')
		return (7);
	if (form[i] == 'X')
		return (8);
	if (form[i] == '%')
		return (9);
	return (0);
}

void	fl_reset(t_fl *f)
{
	f->f_pl = 0;
	f->f_hash = 0;
	f->f_sp = 0;
	f->min = 0;
	f->fill_ch = 32;
	f->width = 0;
	f->f_len = 0;
}

size_t	get_flags(const char *form, size_t i, t_va *v, t_fl *f)
{
	while (form[i] == ' ' || form[i] == '+' || form[i] == '-' ||
	form[i] == '0' || form[i] == '#')
	{
		if (form[i] == ' ')
			f->f_sp++;
		if (form[i] == '+')
			f->f_pl++;
		if (form[i] == '-')
			f->min++;
		if (form[i] == '0')
			f->fill_ch = 48;
		if (form[i] == '#')
			f->f_hash++;
		f->f_len++;
		i++;
	}
	return (i);
}

size_t	get_width(const char *form, size_t i, t_va *v, t_fl *f)
{
	size_t	num_len;
	size_t	num;

	num_len = 0;
	num = 0;
	while (form[i] >= '0' && form[i] <= '9' && num_len++ < 10)
		num = num * 10 + (form[i++] - 48);
	f->width = num;
	return (i);
}
