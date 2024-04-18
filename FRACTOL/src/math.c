#include "../lib/fractol.h"

void	ft_mandelbrot(t_fractal *f, t_complex c)
{
	t_complex		z;
	size_t	i;
	double	real_tmp;
	double	imag_tmp;

	if ((c.x * c.x) + (c.y * c.y) >= 4)
		return (mlx_put_pixel(f->img, f->x, f->y, \
				col_grad(0, f->iterations, WHITE)));
	if ((c.x * c.x) + (c.y * c.y) < 0.0625)
		return (mlx_put_pixel(f->img, f->x, f->y, BLACK));
	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (i < f->iterations)
	{
		real_tmp = (z.x * z.x - z.y * z.y) + c.x;
		imag_tmp = (2 * z.x * z.y) + c.y;
		z.x = real_tmp;
		z.y = imag_tmp;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			return (mlx_put_pixel(f->img, f->x, f->y, \
					col_grad(i, f->iterations, WHITE)));
		i++;
	}
	return (mlx_put_pixel(f->img, f->x, f->y, BLACK));
}

void	ft_math(t_fractal *f, t_complex c)// IS THIS FUNCTION USEFULL?
{
	if (f->set == mandel)
		return (ft_mandelbrot(f, c));
}