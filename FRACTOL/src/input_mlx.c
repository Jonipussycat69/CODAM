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
	double		prev_zoom;
	t_fractal	*f;

	f = param;
	printf(">> SCROLL %f\n", xdelta);// TEST
	if (ft_cursor_check(f) == false || ydelta > INT_MAX || xdelta == 0.0)
		return ;
	prev_zoom = f->offset_x * f->zoom_prev;
	if (xdelta > 0 && f->zoom > 0.1)
	{
		f->zoom -= 0.01 + f->zoom / 10;// zoom in
		f->offset_x -= (f->zoom * f->offset_x - prev_zoom) / 2;// ?
	}
	if (xdelta < 0 && f->zoom < 9.0)
	{
		f->zoom += 0.01 + f->zoom / 10;// zoom out
		f->offset_x -= (f->zoom * f->offset_x - prev_zoom) / 2;// ?
	}
	f->zoom_prev = f->zoom;
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
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		f->draw = true;
}


