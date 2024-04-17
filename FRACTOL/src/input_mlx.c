#include "../lib/fractol.h"

bool	ft_cursor_check(t_fractal *f)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	y = 0;
	mlx_get_mouse_pos(f->mlx, &x, &y);
	if (x < 0 || y < 0 || x > f->mlx->width || y > f->mlx->height)
		return (false);
	return (true);
}

void	ft_scroll(double xdelta, double ydelta, void* param)
{
	t_fractal	*f;
	const double	multiplier = 1 + (xdelta / 10);
	
	f = param;
	printf(">> SCROLL %f\n", xdelta);// TEST
	if (ft_cursor_check(f) == false || ydelta > INT_MAX || xdelta == 0.0)
		return ;
	// HOW TO ZOOM INTO FRACTAL EDGE??
	f->scale_max_x *= multiplier;
	f->scale_min_x *= multiplier;
	f->scale_max_y *= multiplier;
	f->scale_min_y *= multiplier;
	ft_draw(f->mlx->width, f->mlx->height, f);
}

void	ft_key(mlx_key_data_t keydata, void* param)
{
	t_fractal	*f;
	
	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(f->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		ft_window_size_set(f, 1);
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		ft_window_size_set(f, 2);
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
		ft_window_size_set(f, 3);
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
		iteration_mod(f, 10);
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		iteration_mod(f, -10);
}


