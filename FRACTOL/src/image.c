#include "../lib/fractol.h"

void	ft_draw_mandel(t_fractal *f)
{
	t_complex	c;
	t_complex	z;
	
	f->draw = false;
	f->y = 0;
	z.x = 0.0;
	z.y = 0.0;
	while (f->y < f->mlx->height)
	{
		f->x = 0;
		while (f->x < f->mlx->width)
		{
			c.x = ft_scale_x(f, f->x);
			c.y = ft_scale_y(f, f->y);
			ft_fract_math(f, c, z);
			f->x++;
		}
		f->y++;
	}
}

void	ft_draw_julia(t_fractal *f)
{
	t_complex	c;
	t_complex	z;
	
	f->draw = false;
	f->draw_j = false;
	f->y = 0;
	c.x = f->julia_x;
	c.y = f->julia_y;
	while (f->y < f->mlx->height)
	{
		f->x = 0;
		while (f->x < f->mlx->width)
		{
			z.x = ft_scale_x(f, f->x);
			z.y = ft_scale_y(f, f->y);
			ft_fract_math(f, c, z);
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
