#include "../lib/fractol.h"

void	ft_fract_math(t_fractal *f, t_complex c, t_complex z)
{
	size_t		i;
	double		real_tmp;

	if ((c.x * c.x) + (c.y * c.y) >= 4 && f->set == mandel)
		return (mlx_put_pixel(f->img, f->x, f->y, \
				col_grad(0, f->iterations, WHITE)));
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
				col_grad(i, f->iterations, WHITE)));
	return (mlx_put_pixel(f->img, f->x, f->y, BLACK));
}
