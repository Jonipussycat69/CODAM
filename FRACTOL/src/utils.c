#include "../lib/fractol.h"

void	init_fractal_struct(t_fractal *f)
{
	f->scale_min_x = -2.2;
	f->scale_max_x = 0.8;
	f->scale_min_y = 1.5;
	f->scale_max_y = -1.5;
	f->zoom = 1.5;
	f->iterations = 42;
	f->set = mandel;
	f->inp = 1.0;
}

void	iteration_mod(t_fractal *f, short mod)
{
	if (mod > 0 && f->iterations < 1000)
	{
		f->iterations += mod;
		printf(">> iter %zu\n", f->iterations);// TEST
		return (ft_draw(f->mlx->width, f->mlx->height, f));
	}
		
	if (mod < 0 && f->iterations > 10)
	{
		f->iterations += mod;
		printf(">> iter %zu\n", f->iterations);// TEST
		return (ft_draw(f->mlx->width, f->mlx->height, f));
	}
}

void	ft_window_size_set(t_fractal *f, short size)
{
	if (size == 1)
	{
		mlx_resize_image(f->img, WIDTH_A, HEIGHT_A);
		mlx_set_window_size(f->mlx, WIDTH_A, HEIGHT_A);
	}
	if (size == 2)
	{
		mlx_resize_image(f->img, WIDTH_B, HEIGHT_B);
		mlx_set_window_size(f->mlx, WIDTH_B, HEIGHT_B);
	}
	if (size == 3)
	{
		mlx_resize_image(f->img, WIDTH_C, HEIGHT_C);
		mlx_set_window_size(f->mlx, WIDTH_C, HEIGHT_C);
	}
}

void	init_aspect_ratio(t_fractal *f)
{
	const double	ratio = (double)f->mlx->height / (double)f->mlx->width;

	f->scale_max_y = ratio * f->zoom;
	f->scale_min_y = ratio * -(f->zoom);
}
