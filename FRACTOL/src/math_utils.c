#include "../lib/fractol.h"
unsigned int	col_grad(int val, int lim, unsigned int col)
{
	const double	proportion = ((double)val / (double)lim) * 255;

	return (col - (255 - (int)proportion));
}

double	ft_scale_x(t_fractal *f, double val)
{
	const double	max_x = (X_MAX + f->offset_x) * f->zoom;
	const double	min_x = (X_MIN + f->offset_x) * f->zoom;

	return ((max_x - min_x) * val / f->mlx->width + min_x);
}

double	ft_scale_y(t_fractal *f, double val)
{
	const double	max_y = (Y_MAX + f->offset_y) * f->zoom * f->ratio;
	const double	min_y = (Y_MIN + f->offset_y) * f->zoom * f->ratio;

	return ((max_y - min_y) * val / f->mlx->height + min_y);
}

t_complex	sum_complex(t_complex a, t_complex b)// OBSELETE?
{
	t_complex	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_complex	square_complex(t_complex a)// OBSELETE?
{
	t_complex	res;

	res.x = (a.x * a.x) - (a.y * a.y);
	res.y = 2 * a.y * a.y;
	return (res);
}
