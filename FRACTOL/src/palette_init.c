#include "../lib/fractol.h"

void	init_color_palette_m(t_fractal *f, unsigned int size)
{
	t_color_d		d;
	t_color			c;
	unsigned int	i;

	f->palette_m = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_m)
		ft_error(f, "");
	d.r = (double)(f->c_high.r - f->c_low.r) / (size - 1);
	d.g = (double)(f->c_high.g - f->c_low.g) / (size - 1);
	d.b = (double)(f->c_high.b - f->c_low.b) / (size - 1);
	d.a = (double)(f->c_high.a - f->c_low.a) / (size - 1);
	i = 0;
	while (i < size)
	{
		c.r = f->c_low.r + (unsigned char)(d.r * i);
		c.g = f->c_low.g + (unsigned char)(d.g * i);
		c.b = f->c_low.b + (unsigned char)(d.b * i);
		c.a = f->c_low.a + (unsigned char)(d.a * i);
		f->palette_m[i] = rgba_to_hex(c);
		i++;
	}
}

void	init_color_palette_j(t_fractal *f, unsigned int size)
{
	t_color_d		d;
	t_color			c;
	unsigned int	i;

	f->palette_j = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_j)
		ft_error(f, "");
	d.r = (double)(f->c_high.r - f->c_low.r) / (size - 1);
	d.g = (double)(f->c_high.g - f->c_low.g) / (size - 1);
	d.b = (double)(f->c_high.b - f->c_low.b) / (size - 1);
	d.a = (double)(f->c_high.a - f->c_low.a) / (size - 1);
	i = 0;
	while (i < size)
	{
		c.r = f->c_low.r + (unsigned char)(d.r * i);
		c.g = f->c_low.g + (unsigned char)(d.g * i);
		c.b = f->c_low.b + (unsigned char)(d.b * i);
		c.a = f->c_low.a + (unsigned char)(d.a * i);
		f->palette_j[i] = rgba_to_hex(c);
		i++;
	}
}

void	z_init_color_palette_m(t_fractal *f, unsigned int size)
{
	const unsigned int	color_a = rgba_to_hex(f->c_high);
	const unsigned int	color_b = rgba_to_hex(f->c_low);
	unsigned int		i;

	f->palette_m = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_m)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		if (i % 2 == 0)
			f->palette_m[i] = color_a;
		else
			f->palette_m[i] = color_b;
		i++;
	}
}

void	z_init_color_palette_j(t_fractal *f, unsigned int size)
{
	const unsigned int	color_a = rgba_to_hex(f->c_high);
	const unsigned int	color_b = rgba_to_hex(f->c_low);
	unsigned int	i;

	f->palette_j = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_j)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		if (i % 2 == 0)
			f->palette_j[i] = color_a;
		else
			f->palette_j[i] = color_b;
		i++;
	}
}

void	i_init_color_palette_m(t_fractal *f, unsigned int size)
{
	double			t;
	unsigned int	i;
	t_color			c;

	f->palette_m = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_m)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		t = (double)i / (double)(size - 1);
		c.r = round_to_uint((1 - t) * f->c_high.r + t * f->c_low.r);
		c.g = round_to_uint((1 - t) * f->c_high.g + t * f->c_low.g);
		c.b = round_to_uint((1 - t) * f->c_high.b + t * f->c_low.b);
		c.a = round_to_uint((1 - t) * f->c_high.a + t * f->c_low.a);
		f->palette_m[i] = rgba_to_hex(c);
		i++;
	}
}

void	i_init_color_palette_j(t_fractal *f, unsigned int size)
{
	double			t;
	unsigned int	i;
	t_color			c;

	f->palette_j = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_j)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		t = (double)i / (double)(size - 1);
		c.r = round_to_uint((1 - t) * f->c_high.r + t * f->c_low.r);
		c.g = round_to_uint((1 - t) * f->c_high.g + t * f->c_low.g);
		c.b = round_to_uint((1 - t) * f->c_high.b + t * f->c_low.b);
		c.a = round_to_uint((1 - t) * f->c_high.a + t * f->c_low.a);
		f->palette_j[i] = rgba_to_hex(c);
		i++;
	}
}

void	re_init_palette(t_fractal *f, short set)
{
	if (set == mandel)
	{
		free(f->palette_m);
		if (f->palette == zebra)
			return (z_init_color_palette_m(f, f->iterations));
		if (f->palette == inverse)
			return (i_init_color_palette_m(f, f->iterations));
		init_color_palette_m(f, f->iterations);
		return ;
	}
	if (set == julia)
	{
		free(f->palette_j);
		if (f->palette == zebra)
			return (z_init_color_palette_j(f, f->iterations_j));
		if (f->palette == inverse)
			return (i_init_color_palette_j(f, f->iterations_j));
		init_color_palette_j(f, f->iterations_j);
		return ;
	}
}
