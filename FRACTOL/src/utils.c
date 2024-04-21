#include "../lib/fractol.h"

void	init_fractal_struct(t_fractal *f)
{
	f->test = false;// TEST
	f->draw = true;
	f->draw_j = true;
	f->c_range = 255;
	f->color = WHITE;
	f->color_shift = false;
	f->offset_x = -0.8;
	if (f->set == julia)
		f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->zoom = 1.0;
	f->zoom_prev = 1.0;
	f->rat_j = J_HEIGHT / J_WIDTH;
	f->ratio = (double)f->mlx->height / (double)f->mlx->width;
	if (f->divine == true)
		f->ratio = 1;
	f->iterations = 42;
	f->inp = 1.0;
}

void	iteration_mod(t_fractal *f, short mod)
{
	if (mod > 0 && f->iterations < 1000)
	{
		f->iterations += mod;
		printf(">> iter %zu\n", f->iterations);// TEST
		f->draw = true;
	}
	else if (mod < 0 && f->iterations > 10)
	{
		f->iterations += mod;
		printf(">> iter %zu\n", f->iterations);// TEST
		f->draw = true;
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

void	close_all(void *param)
{
	t_fractal	*f;
	
	f = param;
	mlx_terminate(f->mlx);
	exit(EXIT_SUCCESS);
}

// Exit the program as failure, takes error-message as argument
void	ft_error(t_fractal *f, char *message)
{
	if (message)
	{
		write(STDOUT_FILENO, message, ft_strlen(message));
		write(STDOUT_FILENO, "\n", 1);
	}
	if (f->mlx)
		close_all(f);
	exit(EXIT_FAILURE);
}
