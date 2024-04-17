#include "../lib/fractol.h"

double	ft_scale(t_fractal *f, double val, short axis)
{
	if (axis == y_ax)
		return ((f->scale_max_y - f->scale_min_y) * val / f->mlx->height \
				+ f->scale_min_y);
	else
		return ((f->scale_max_x - f->scale_min_x) * val / f->mlx->width \
				+ f->scale_min_x);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_complex	square_complex(t_complex a)
{
	t_complex	res;

	res.x = (a.x * a.x) - (a.y * a.y);
	res.y = 2 * a.y * a.y;
	return (res);
}
