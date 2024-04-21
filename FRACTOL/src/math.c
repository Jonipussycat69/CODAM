#include "../lib/fractol.h"

unsigned int	col_grad(double val, double lim, unsigned int col, \
			t_fractal *f)
{
	const double	proportion = (val / lim) * f->c_range;

	return ((unsigned int)col - (f->c_range - (int)proportion));
}

void	ft_fract_math(t_fractal *f, t_complex c, t_complex z)
{
	size_t		i;
	double		real_tmp;

	if ((c.x * c.x) + (c.y * c.y) < 0.0625 && f->set == mandel)
		return (mlx_put_pixel(f->img, f->x, f->y, BLACK));
	i = 0;
	while (i < f->iterations && (z.x * z.x) + (z.y * z.y) <= 4)
	{
		real_tmp = (z.x * z.x - z.y * z.y) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = real_tmp;
		i++;
	}
	if (i < f->iterations)
		return (mlx_put_pixel(f->img, f->x, f->y, \
				col_grad(i, f->iterations, f->color, f)));
	return (mlx_put_pixel(f->img, f->x, f->y, BLACK));
}

// divine
void	ft_fract_math_jul(t_fractal *f, t_complex c, t_complex z)
{
	size_t		i;
	double		real_tmp;

	i = 0;
	while (i < f->iterations + J_EXTRA && (z.x * z.x) + (z.y * z.y) <= 4)
	{
		real_tmp = (z.x * z.x - z.y * z.y) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = real_tmp;
		i++;
	}
	if (i < f->iterations)
		return (mlx_put_pixel(f->img_div_j, f->x, f->y, \
				col_grad(i, f->iterations, f->color, f)));
	return (mlx_put_pixel(f->img_div_j, f->x, f->y, BLACK));
}
