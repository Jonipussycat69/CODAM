#include "ft_printf.h"

char	*mal_set(size_t size, char c)
{
	char	*ret;
	size_t	i;
	
	ret = (char *)malloc(size + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

char	*pl_sp_h_print(t_va *v, t_fl *f)
{
	if (f->f_sp >= 1 && f->f_pl == 0)
		v->print = char_str(' ', v->print, 0);
	else if (f->f_pl >= 1)
		v->print = char_str('+', v->print, 0);
	else if (f->f_hash >= 1 && v->spec == 7)
		v->print = add_print(v->print, "0x");
	else if (f->f_hash >= 1 && v->spec == 8)
		v->print = add_print(v->print, "0X");
	if (f->width > 0 && (f->f_pl >= 1 || f->f_sp >= 1 || f->f_hash >= 1))
		f->width--;
	if (f->f_hash >= 1)
		f->width--;
	return (v->print);
}
