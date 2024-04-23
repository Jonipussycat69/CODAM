#include "../lib/fractol.h"

void	ft_fract_math(t_fractal *f, t_complex c, t_complex z)
{
	size_t		i;
	double		real_tmp;

	if ((c.x * c.x) + (c.y * c.y) < 0.0625 && f->set == mandel)
		return (mlx_put_pixel(f->img, f->x, f->y, f->color_inf));
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
				f->palette_m[i]));
	return (mlx_put_pixel(f->img, f->x, f->y, f->color_inf));
}

// divine
void	ft_fract_math_jul(t_fractal *f, t_complex c, t_complex z)
{
	size_t		i;
	double		real_tmp;

	i = 0;
	while (i < f->iterations_j && (z.x * z.x) + (z.y * z.y) <= 4)
	{
		real_tmp = (z.x * z.x - z.y * z.y) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = real_tmp;
		i++;
	}
	if (i < f->iterations_j)
		return (mlx_put_pixel(f->img_j, f->x, f->y, \
				f->palette_j[i]));
	return (mlx_put_pixel(f->img_j, f->x, f->y, f->color_inf));
}
