#include "../lib/fractol.h"

void	ft_draw(int32_t width, int32_t height, t_fractal *f)
{
	t_complex	c;
	
	f->draw = false;
	f->y = 0;
	while (f->y < height)
	{
		f->x = 0;
		while (f->x < width)
		{
			c.x = ft_scale_x(f, f->x);
			c.y = ft_scale_y(f, f->y);
			ft_mandelbrot(f, c);
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
	f->ratio = (double)f->mlx->height / (double)f->mlx->width;
	f->draw = true;// ?
}
