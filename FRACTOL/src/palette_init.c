#include "../lib/fractol.h"

unsigned int	color_interpolate(t_color c_l, t_color c_h, double t)
{
	t_color		c;

	c.r = round_to_uint((1 - t) * c_l.r + t * c_h.r);
	c.g = round_to_uint((1 - t) * c_l.g + t * c_h.g);
	c.b = round_to_uint((1 - t) * c_l.b + t * c_h.b);
	c.a = round_to_uint((1 - t) * c_l.a + t * c_h.a);
	return (rgba_to_hex(c));
}

void	init_color_palette_m(t_fractal *f, unsigned int size)
{
	int		i;
	double	t;

	f->palette_m = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_m)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		t = (double)i / (double)size;
		if (f->palette == inverse)
			f->palette_m[i] = color_interpolate(f->c_high, f->c_low, t);
		else
			f->palette_m[i] = color_interpolate(f->c_low, f->c_high, t);
		i++;
	}
}

void	init_color_palette_j(t_fractal *f, unsigned int size)
{
	int		i;
	double	t;

	f->palette_j = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_j)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		t = (double)i / (double)size;
		if (f->palette == inverse)
			f->palette_j[i] = color_interpolate(f->c_high, f->c_low, t);
		else
			f->palette_j[i] = color_interpolate(f->c_low, f->c_high, t);
		i++;
	}
}

void	z_init_color_palette_m(t_fractal *f, unsigned int size)
{
	const unsigned int	color_a = rgba_to_hex(f->c_high);
	const unsigned int	color_b = rgba_to_hex(f->c_low);
	unsigned int		i;
	double	t;

	f->palette_m = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_m)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		t = (double)i / (double)size;
		if (i % 2 == 0)
			f->palette_m[i] = color_interpolate(f->c_high, f->c_low, t);
		else
			f->palette_m[i] = color_interpolate(f->c_low, f->c_high, t);
		i++;
	}
}

void	z_init_color_palette_j(t_fractal *f, unsigned int size)
{
	const unsigned int	color_a = rgba_to_hex(f->c_high);
	const unsigned int	color_b = rgba_to_hex(f->c_low);
	unsigned int	i;
	double	t;

	f->palette_j = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_j)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		t = (double)i / (double)size;
		if (i % 2 == 0)
			f->palette_j[i] = color_interpolate(f->c_high, f->c_low, t);
		else
			f->palette_j[i] = color_interpolate(f->c_low, f->c_high, t);
		i++;
	}
}

void	multi_init_color_palette_m(t_fractal *f, unsigned int size)
{
	int			i;
	int			start_i;
	int			end_i;
	double		step;
	const t_color	arr[4] = {f->c_a, f->c_b, f->c_c, f->c_d};

	f->palette_m = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_m)
		ft_error(f, "");
	i = 0;
	step = (double)(size - 1) / 3;
	while (i < size)
	{
		start_i = i / step;
		end_i = start_i + 1;
		f->palette_m[i] = color_interpolate(arr[start_i], arr[end_i], \
			(double)(i - start_i * step) / step);
		i++;
	}
}

void	multi_init_color_palette_j(t_fractal *f, unsigned int size)
{
	int			i;
	int			start_i;
	int			end_i;
	double		step;
	const t_color	arr[4] = {f->c_a, f->c_b, f->c_c, f->c_d};
	// const t_color	arr[4] = {hex_to_rgba(BLACK), hex_to_rgba(ORANGE), \
	// 						hex_to_rgba(RED), hex_to_rgba(WATER)};

	f->palette_j = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_j)
		ft_error(f, "");
	i = 0;
	step = (double)(size - 1) / 3;
	while (i < size)
	{
		start_i = i / step;
		end_i = start_i + 1;
		f->palette_j[i] = color_interpolate(arr[start_i], arr[end_i], \
			(double)(i - start_i * step) / step);
		i++;
	}
}

void	jewel_init_color_palette_m(t_fractal *f, unsigned int size)
{
	int			i;
	double		t;
	const int	first = size / 5;
	const int	second = round_to_uint((double)size * 0.8);
	const int	third =round_to_uint((double)size * 0.95);

	f->palette_m = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_m)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		t = (double)i / (double)size;
		if (i <= first)
			f->palette_m[i] = color_interpolate(hex_to_rgba(WHITE), hex_to_rgba(RED), t);
		if (i > first && i <= second)
			f->palette_m[i] = color_interpolate(hex_to_rgba(RED), hex_to_rgba(WATER), t);
		if (i > second && i <= third)
			f->palette_m[i] = color_interpolate(hex_to_rgba(WATER), hex_to_rgba(ORANGE), t);
		else
			f->palette_m[i] = color_interpolate(hex_to_rgba(ORANGE), hex_to_rgba(BLACK), t);
		i++;
	}
}

void	jewel_init_color_palette_j(t_fractal *f, unsigned int size)
{
	int			i;
	double		t;
	const int	first = size / 5;
	const int	second = round_to_uint((double)size * 0.8);
	const int	third =round_to_uint((double)size * 0.95);

	f->palette_j = (unsigned int *)malloc(sizeof(unsigned int) * size);
	if (!f->palette_j)
		ft_error(f, "");
	i = 0;
	while (i < size)
	{
		t = (double)i / (double)size;
		if (i <= first)
			f->palette_j[i] = color_interpolate(hex_to_rgba(WHITE), hex_to_rgba(RED), t);
		if (i > first && i <= second)
			f->palette_j[i] = color_interpolate(hex_to_rgba(RED), hex_to_rgba(WATER), t);
		if (i > second && i <= third)
			f->palette_j[i] = color_interpolate(hex_to_rgba(WATER), hex_to_rgba(ORANGE), t);
		else
			f->palette_j[i] = color_interpolate(hex_to_rgba(ORANGE), hex_to_rgba(BLACK), t);
		i++;
	}
}

void	re_init_palette(t_fractal *f, short set)
{
	if (f->palette == multi)
		f->color_inf = f->c_inf_m;
	else
		f->color_inf = f->c_inf_n;
	if (set == mandel)
	{
		free(f->palette_m);
		if (f->palette == zebra)
			return (z_init_color_palette_m(f, f->iterations));
		if (f->palette == multi)
			return (multi_init_color_palette_m(f, f->iterations));
		init_color_palette_m(f, f->iterations);
		return ;
	}
	if (set == julia)
	{
		free(f->palette_j);
		if (f->palette == zebra)
			return (z_init_color_palette_j(f, f->iterations_j));
		if (f->palette == multi)
			return (multi_init_color_palette_j(f, f->iterations_j));
		init_color_palette_j(f, f->iterations_j);
		return ;
	}
}
