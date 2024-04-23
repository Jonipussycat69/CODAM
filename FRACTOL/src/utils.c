#include "../lib/fractol.h"

void	init_basic_struct(t_fractal *f)
{
	f->test = false;// TEST
	f->draw = true;
	f->offset_x = -0.8;
	if (f->set == julia)
		f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->zoom = 1.0;
	f->ratio = (double)f->mlx->height / (double)f->mlx->width;
	f->iterations = 42;
	f->inp = 1.0;
	f->lock_j = false;
}

void	init_split_struct(t_fractal *f)
{
	f->test = false;// TEST
	f->draw = true;
	f->draw_j = true;
	f->offset_x = -0.8;
	f->offset_y = 0.0;
	f->offset_x_j = 0.0;
	f->offset_y_j = 0.0;
	f->zoom = 1.0;
	f->zoom_j = 1.0;
	f->ratio = 1;
	f->iterations = 42;
	f->iterations_j = 62;
	f->inp = 1.0;
	f->lock_j = false;
}

void	iteration_mod(t_fractal *f, short mod)
{
	int32_t	x;
	int32_t	y;

	if (!ft_cursor_check(f))
		return ;
	mlx_get_mouse_pos(f->mlx, &x, &y);
	if (f->split == false || (x < M_WIDTH && \
	((mod > 0 && f->iterations < 500) || \
	(mod < 0 && f->iterations > 10))))
	{
		f->iterations += mod;
		printf(">> iter %zu\n", f->iterations);// TEST
		re_init_palette(f, mandel);
		f->draw = true;
	}
	else if ((mod > 0 && f->iterations_j < 500) || \
		(mod < 0 && f->iterations_j > 10))
	{
		f->iterations_j += mod;
		printf(">> iter %zu\n", f->iterations_j);// TEST
		re_init_palette(f, julia);
		f->draw_j = true;
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
	if (f->palette_m)
		free(f->palette_m);
	if (f->palette_j)
		free(f->palette_j);
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->img_j)
		mlx_delete_image(f->mlx, f->img_j);
	mlx_close_window(f->mlx);
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
