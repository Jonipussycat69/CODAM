#include "../lib/fractol.h"

double	mx(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

t_uint	color_interpolate(t_color c_l, t_color c_h, double t)
{
	t_color	c;

	c.r = round_to_uint((1 - t) * c_l.r + t * c_h.r);
	c.g = round_to_uint((1 - t) * c_l.g + t * c_h.g);
	c.b = round_to_uint((1 - t) * c_l.b + t * c_h.b);
	c.a = round_to_uint((1 - t) * c_l.a + t * c_h.a);
	return (rgba_to_hex(c));
}

t_uint	color_log_interpolate(t_color c_l, t_color c_h, double t)
{
	t_color			c;
	const double	e = 1e-6;

	c.r = (t_uchar)((1.0 - t) * log(mx(c_l.r, e)) + t * log(mx(c_h.r, e)));
	c.g = (t_uchar)((1.0 - t) * log(mx(c_l.g, e)) + t * log(mx(c_h.g, e)));
	c.b = (t_uchar)((1.0 - t) * log(mx(c_l.b, e)) + t * log(mx(c_h.b, e)));
	c.a = (t_uchar)((1.0 - t) * log(mx(c_l.a, e)) + t * log(mx(c_h.a, e)));
	return (rgba_to_hex(c));
}

void	init_color_palette_m(t_fractal *f, t_uint size)
{
	int		i;
	double	t;

	f->palette_m = (t_uint *)malloc(sizeof(t_uint) * size);
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

void	init_color_palette_j(t_fractal *f, t_uint size)
{
	int		i;
	double	t;

	f->palette_j = (t_uint *)malloc(sizeof(t_uint) * size);
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

void	z_init_color_palette_m(t_fractal *f, t_uint size)
{
	int		i;
	double	t;

	f->palette_m = (t_uint *)malloc(sizeof(t_uint) * size);
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

void	z_init_color_palette_j(t_fractal *f, t_uint size)
{
	int		i;
	double	t;

	f->palette_j = (t_uint *)malloc(sizeof(t_uint) * size);
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

void	multi_init_color_palette_m(t_fractal *f, t_uint size)
{
	int		i;
	int		start_i;
	int		end_i;
	double	step;
	const	t_color	arr[4] = {f->c_a, f->c_b, f->c_c, f->c_d};

	f->palette_m = (t_uint *)malloc(sizeof(t_uint) * size);
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

void	multi_init_color_palette_j(t_fractal *f, t_uint size)
{
	int		i;
	int		start_i;
	int		end_i;
	double	step;
	const	t_color	arr[4] = {f->c_a, f->c_b, f->c_c, f->c_d};

	f->palette_j = (t_uint *)malloc(sizeof(t_uint) * size);
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

void	log_init_color_palette_m(t_fractal *f, t_uint size)
{
	int		i;
	int		start_i;
	int		end_i;
	double	step;
	const	t_color	arr[4] = {f->c_a, f->c_b, f->c_c, f->c_d};

	f->palette_m = (t_uint *)malloc(sizeof(t_uint) * size);
	if (!f->palette_m)
		ft_error(f, "");
	i = 0;
	step = (double)(size - 1) / 3;
	while (i < size)
	{
		start_i = i / step;
		end_i = start_i + 1;
		f->palette_m[i] = color_log_interpolate(arr[start_i], arr[end_i], \
			(double)(i - start_i * step) / step);
		i++;
	}
}

void	log_init_color_palette_j(t_fractal *f, t_uint size)
{
	int		i;
	int		start_i;
	int		end_i;
	double	step;
	const	t_color	arr[4] = {f->c_a, f->c_b, f->c_c, f->c_d};

	f->palette_j = (t_uint *)malloc(sizeof(t_uint) * size);
	if (!f->palette_j)
		ft_error(f, "");
	i = 0;
	step = (double)(size - 1) / 3;
	while (i < size)
	{
		start_i = i / step;
		end_i = start_i + 1;
		f->palette_j[i] = color_log_interpolate(arr[start_i], arr[end_i], \
			(double)(i - start_i * step) / step);
		i++;
	}
}

void	re_init_palette(t_fractal *f, short set)
{
	if (f->palette == multi || f->palette == logarithmic)
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
		if (f->palette == logarithmic)
			return (log_init_color_palette_m(f, f->iterations));
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
		if (f->palette == logarithmic)
			return (log_init_color_palette_j(f, f->iterations_j));
		init_color_palette_j(f, f->iterations_j);
		return ;
	}
}
