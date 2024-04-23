#include "../lib/fractol.h"

void	color_engine(t_fractal *f)
{
	// LEFTOFF
}

unsigned int	rgba_to_hex(t_color c)
{
	unsigned int	hex;

	hex = ((unsigned int)c.r << 24) | ((unsigned int)c.g << 16) | \
	((unsigned int)c.b << 8) | (unsigned int)c.a;
	return (hex);
}

t_color	hex_to_rgba(unsigned int hex)
{
	t_color	c;

	c.r = (hex >> 24) & 0xFF;
	c.g = (hex >> 16) & 0xFF;
	c.b = (hex >> 8) & 0xFF;
	c.a = hex & 0xFF;
	return (c);
}

void	init_color_palette_m(t_fractal *f, unsigned int size)
{
	t_color_d		d;
	t_color			c;
	unsigned int	i;

	f->palette_m = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_m)
		close_all(f);
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
		close_all(f);
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

void	re_init_palette(t_fractal *f, short set)
{
	if (set == mandel)
	{
		free(f->palette_m);
		init_color_palette_m(f, f->iterations);
		return ;
	}
	if (set == julia)
	{
		free(f->palette_j);
		init_color_palette_j(f, f->iterations_j);
		return ;
	}
}
