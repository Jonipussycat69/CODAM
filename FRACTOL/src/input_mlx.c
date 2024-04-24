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
// LEFTOFF! Fuckaround and then define the best array combination!
void	ft_color_switch_multi(t_fractal *f)
{
	const unsigned int	a_i[5] = {C_DODGER, C_DARK_SLATE_BLUE, LAND, BLACK, BLACK};
	const unsigned int	a_a[5] = {BLACK, BLACK, LAND, BLACK, BLACK};
	const unsigned int	a_b[5] = {ORANGE, ORANGE, SHORE, ORANGE, BLACK};
	const unsigned int	a_c[5] = {RED, C_LIGHT_STEEL_BLUE, WATER, WHITE, ORANGE};
	const unsigned int	a_d[5] = {WATER, C_DARK_SLATE_BLUE, WATER, WHITE, C_LIGHT_STEEL_BLUE};
	static int			i = 0;

	i++;
	if (i == 5)
		i = 0;
	f->color_inf = a_i[i];
	f->c_a = hex_to_rgba(a_a[i]);
	f->c_b = hex_to_rgba(a_b[i]);
	f->c_c = hex_to_rgba(a_c[i]);
	f->c_d = hex_to_rgba(a_d[i]);
	re_init_palette(f, mandel);
	f->draw = true;
	if (f->split == true)
	{
		re_init_palette(f, julia);
		f->draw_j = true;
	}
}

void	ft_color_switch(t_fractal *f)
{
	const unsigned int	arr_i[5] = {BLACK, WHITE, LAND, BLACK, WHITE};
	const unsigned int	arr_h[5] = {WHITE, PINK, SHORE, ORANGE, WHITE};
	const unsigned int	arr_l[5] = {BLACK, CYAN, WATER, WHITE, BLACK};
	static int			i = 0;

	if (f->palette == multi)
		return (ft_color_switch_multi(f));
	i++;
	if (i == 5)
		i = 0;
	f->color_inf = arr_i[i];
	f->c_high = hex_to_rgba(arr_h[i]);
	f->c_low = hex_to_rgba(arr_l[i]);
	re_init_palette(f, mandel);
	f->draw = true;
	if (f->split == true)
	{
		re_init_palette(f, julia);
		f->draw_j = true;
	}
}

void	ft_lock_j_switch(t_fractal *f)
{
	if (f->lock_j == true)
		f->lock_j = false;
	else
		f->lock_j = true;
}

void	palette_switch(t_fractal *f)
{
	if (f->palette == normal)
		f->palette = inverse;
	else if(f->palette == inverse)
		f->palette = zebra;
	else if(f->palette == zebra)
		f->palette = multi;
	else if(f->palette == multi)
		f->palette = normal;
	re_init_palette(f, mandel);
	f->draw = true;
	if (f->split)
	{
		re_init_palette(f, julia);
		f->draw_j = true;
	}
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
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		palette_switch(f);
	else if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
		ft_lock_j_switch(f);
}

void	ft_key_split(mlx_key_data_t keydata, void* param)
{
	t_fractal	*f;

	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_all(f);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_reset_view(f);
	else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
		iteration_mod(f, 10);
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		iteration_mod(f, -10);
	else if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
		ft_lock_j_switch(f);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_reset_view(f);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		ft_color_switch(f);
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		palette_switch(f);
}
