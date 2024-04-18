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

	f = param;
	printf(">> SCROLL %f\n", xdelta);// TEST
	if (ft_cursor_check(f) == false || ydelta > INT_MAX || xdelta == 0.0)
		return ;
	// HOW TO ZOOM INTO FRACTAL EDGE??
	f->zoom += xdelta / 10;
	f->draw = true;// ?
}

void	ft_key(mlx_key_data_t keydata, void* param)
{
	t_fractal	*f;
	
	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_all(f);
	else if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		ft_window_size_set(f, 1);
	else if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		ft_window_size_set(f, 2);
	else if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
		ft_window_size_set(f, 3);
	else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
		iteration_mod(f, 10);
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		iteration_mod(f, -10);
}


