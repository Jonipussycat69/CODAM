#include "../lib/fractol.h"

size_t	ft_mandlebrot(t_fractal *f, t_complex c)
{
	t_complex		z;
	size_t	iteration;
	double	real_tmp;
	double	imag_tmp;

	if (c.x > 0.5 || c.x < -2 || c.y > 1.0 || c.y < -1.0 || \
		(c.x * c.x) + (c.y * c.y) >= 4)
		return (0);
	if ((c.x * c.x) + (c.y * c.y) < 0.0625)
		return (f->iterations);
	z.x = 0;
	z.y = 0;
	iteration = 0;
	while (iteration < f->iterations)
	{
		real_tmp = (z.x * z.x - z.y * z.y) + c.x;
		imag_tmp = (2 * z.x * z.y) + c.y;
		z.x = real_tmp;
		z.y = imag_tmp;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			return (iteration);
		iteration++;
	}
	return (f->iterations);
}

size_t	ft_math(t_fractal *f, t_complex c)
{
	if (f->set == mandel)
		return (ft_mandlebrot(f, c));
	return (0);
}