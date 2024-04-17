#include "../lib/fractol.h"

void	ft_set_pix(fra_t *f, size_t iter)
{
	if (iter == f->iterations)
		mlx_put_pixel(f->img, f->x, f->y, 0x010101FF);
	else
		mlx_put_pixel(f->img, f->x, f->y, 0xFFFF99FF);
}

void	draw(int32_t width, int32_t height, fra_t *f)
{
	c_t	c;
	size_t	iter;
	
	f->y = 0;
	while (f->y < height)
	{
		f->x = 0;
		while (f->x < width)
		{
			c.real = ft_scale(f, f->x, x_ax);
			c.imag = ft_scale(f, f->y, y_ax);
			iter = ft_math(f, c);
			ft_set_pix(f, iter);
			f->x++;
		}
		f->y++;
	}
}
