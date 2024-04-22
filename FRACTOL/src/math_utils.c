#include "../lib/fractol.h"

double	ft_scale_x(t_fractal *f, double val)
{
	const double	max_x = (X_MAX * f->zoom) + f->offset_x;
	const double	min_x = (X_MIN * f->zoom) + f->offset_x;

	return ((max_x - min_x) * val / f->mlx->width + min_x);
}

double	ft_scale_y(t_fractal *f, double val)
{
	const double	max_y = ((Y_MAX * f->zoom) + f->offset_y) * f->ratio;
	const double	min_y = ((Y_MIN * f->zoom) + f->offset_y) * f->ratio;

	return ((max_y - min_y) * val / f->mlx->height + min_y);
}
