#include "../lib/fractol.h"

bool	ft_cursor_check(t_fractal *f)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(f->mlx, &x, &y);
	if (x < 0 || y < 0 || x > f->mlx->width || y > f->mlx->height)
		return (false);
	return (true);
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;

	f = param;
	printf(">> SCROLL %f\n", ydelta);// TEST
	if (ft_cursor_check(f) == false || !ydelta || xdelta > 1)
		return ;
	if (ydelta > 0)
	{
		f->zoom *= 0.95;// zoom in
	}
	if (ydelta < 0 && f->zoom < 100.0)
	{
		f->zoom *= 1.05;// zoom out
	}
	f->draw = true;
}

void	ft_reset_view(t_fractal *f)
{
	int32_t	x;
	int32_t	y;

	if (!ft_cursor_check(f))
		return ;
	mlx_get_mouse_pos(f->mlx, &x, &y);
	if (f->split == false || (f->split == true && x < M_WIDTH))
	{
		f->draw = true;
		f->offset_x = -0.8;
		if (f->set == julia)
			f->offset_x = 0.0;
		f->offset_y = 0.0;
		f->zoom = 1.0;
	}
	else
	{
		f->draw_j = true;
		f->zoom_j = 1.0;
		f->offset_x_j = 0.0;
		f->offset_y_j = 0.0;
	}
}

void	ft_set_switch(t_fractal *f)
{
	if (f->set == mandel)
	{
		f->set = julia;
		ft_reset_view(f);
		f->offset_x = 0.0;
	}
	else if (f->set == julia)
	{
		f->set = mandel;
		ft_reset_view(f);
	}
}

void	ft_color_switch(t_fractal *f)
{
	const int	arr[5] = {WHITE, RED, GREEN, BLUE, CYAN};
	static int	i = 0;

	if (i == 4)
		i = 0;
	else
		i++;
	f->color = arr[i];
	f->draw = true;
}

void	ft_color_invert(t_fractal *f)
{
	// invert in gradient funct
}

void	ft_color_psych(t_fractal *f)
{
	f->color = WHITE;
	if (f->color_shift == true)
	{
		f->color_shift = false;
		f->c_range = 255;
	}
	else
		f->color_shift = true;
}

void	ft_lock_j_switch(t_fractal *f)
{
	if (f->lock_j == true)
		f->lock_j = false;
	else
		f->lock_j = true;
}

void	ft_key_basic(mlx_key_data_t keydata, void* param)
{
	t_fractal	*f;
	
	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_all(f);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_reset_view(f);
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
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_set_switch(f);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		ft_color_switch(f);
	else if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		ft_color_invert(f);
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		ft_color_psych(f);
	else if (keydata.key == MLX_KEY_T && keydata.action == MLX_PRESS)// TEST
	{
		if (f->test == true)
			f->test = false;
		if (f->test == false)
			f->test = true;
		f->draw = true;
	}
}

void	ft_key_split(mlx_key_data_t keydata, void* param)
{
	t_fractal	*f;
	
	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_all(f);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_reset_view(f);
	else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS \
			&& mlx_is_key_down(f->mlx, MLX_KEY_J))
		iteration_mod(f, 10);
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS \
			&& mlx_is_key_down(f->mlx, MLX_KEY_J))
		iteration_mod(f, -10);
	else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
		iteration_mod(f, 10);
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		iteration_mod(f, -10);
	else if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
		ft_lock_j_switch(f);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_reset_view(f);
}
