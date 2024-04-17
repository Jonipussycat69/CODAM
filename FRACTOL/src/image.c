#include "../lib/fractol.h"

void	ft_set_pix(t_fractal *f, size_t iter)
{
	if (iter == f->iterations)
		mlx_put_pixel(f->img, f->x, f->y, 0x010101FF);
	else
		mlx_put_pixel(f->img, f->x, f->y, 0xFFFF99FF);
}

void	ft_draw(int32_t width, int32_t height, t_fractal *f)
{
	t_complex	c;
	size_t	iter;
	
	f->y = 0;
	init_aspect_ratio(f);
	while (f->y < height)
	{
		f->x = 0;
		while (f->x < width)
		{
			c.x = ft_scale(f, f->x, x_ax);
			c.y = ft_scale(f, f->y, y_ax);
			iter = ft_math(f, c);
			ft_set_pix(f, iter);
			f->x++;
		}
		f->y++;
	}
}

void	ft_image_resize(int32_t width, int32_t height, void* param)
{
	t_fractal	*f;

	f = param;
	printf("WIDTH: %d | HEIGHT: %d\n", width, height);// TEST
	mlx_resize_image(f->img, width, height);
	ft_draw(width, height, f);
}
