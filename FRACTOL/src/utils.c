#include "../lib/fractol.h"

void	init_fractal_struct(t_fractal *f)
{
	f->draw = true;// ?
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->zoom = 1.0;
	f->ratio = (double)f->mlx->height / (double)f->mlx->width;
	f->iterations = 42;
	f->inp = 1.0;
}

void	iteration_mod(t_fractal *f, short mod)
{
	if (mod > 0 && f->iterations < 1000)
	{
		f->iterations += mod;
		printf(">> iter %zu\n", f->iterations);// TEST
		f->draw = true;// ?
	}
	else if (mod < 0 && f->iterations > 10)
	{
		f->iterations += mod;
		printf(">> iter %zu\n", f->iterations);// TEST
		f->draw = true;// ?
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

void	close_all(t_fractal *f)
{
	mlx_terminate(f->mlx);
	exit(EXIT_SUCCESS);
}
