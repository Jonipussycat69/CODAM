#include "../lib/fractol.h"

size_t	ft_mandlebrot(fra_t *f, c_t c)
{
	c_t		z;
	size_t	iteration;
	double	magnitude;
	double	real_tmp;
	double	imag_tmp;

	z.real = 0;
	z.imag = 0;
	iteration = 0;
	while (iteration < f->iterations)
	{
		real_tmp = z.real * z.real - z.imag * z.imag + c.real;
		imag_tmp = 2 * z.real * z.imag + c.imag;
		z.real = real_tmp;
		z.imag = imag_tmp;
		magnitude = z.real * z.real + z.imag * z.imag;
		if (magnitude > 4)
			return (iteration);
		iteration++;
	}
	return (f->iterations);
}

size_t	ft_math(fra_t *f, c_t c)
{
	if (f->set == mandel)
		return (ft_mandlebrot(f, c));
	return (0);
}