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
	if (ft_cursor_check(f) == false || !ydelta || xdelta > 1 || \
		f->retina_mode == true)
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
		mlx_set_window_title(f->mlx, "julia");
		f->set = julia;
		ft_reset_view(f);
		f->offset_x = 0.0;
	}
	else if (f->set == julia)
	{
		mlx_set_window_title(f->mlx, "mandelbrot");
		f->set = mandel;
		ft_reset_view(f);
	}
}
// LEFTOFF! Fuckaround and find the best array combination!
void	ft_color_switch_multi(t_fractal *f)
{
	const unsigned int	a_i[] = {BLACK, BLACK, BLACK, C_ANTIQUE_WHITE, C_CORNSILK, WATER, BLACK};
	const unsigned int	a_a[] = {BLACK, C_WHEAT, C_BLANCHED_ALMOND, C_BEIGE, C_BISQUE, C_LIGHT_SKY_BLUE, BLACK};
	const unsigned int	a_b[] = {ORANGE, C_BROWN, C_BROWN, ORANGE, ORANGE, SHORE, BLACK};
	const unsigned int	a_c[] = {C_GOLD, C_BLUE, C_DARK_SLATE_BLUE, WATER, C_CRIMSON, C_CRIMSON, ORANGE};
	const unsigned int	a_d[] = {C_LIGHT_STEEL_BLUE, C_PLUM, C_ANTIQUE_WHITE, C_ANTIQUE_WHITE, C_CORNSILK, WATER, C_LIGHT_STEEL_BLUE};
	static int			i = 0;

	i++;
	if (i == 7)
		i = 0;
	f->c_inf_m = a_i[i];
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
	f->c_inf_n = arr_i[i];
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
	if (f->split == true)
	{
		re_init_palette(f, julia);
		f->draw_j = true;
	}
}

void	ft_retina_switch(t_fractal *f)
{
	static int	tmp_iterations = 0;

	if (f->retina_mode)
	{
		f->iterations = tmp_iterations;
		re_init_palette(f, mandel);
		f->retina_mode = false;
	}
	else
	{
		f->lock_j = true;
		f->retina_mode = true;
		tmp_iterations = f->iterations;
		f->iterations = RETINA_ITER;
		re_init_palette(f, mandel);
	}
	f->draw = true;
}

void	ft_key_basic(mlx_key_data_t keydata, void* param)
{
	t_fractal	*f;
	
	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_all(f);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS && f->retina_mode == false)
		ft_reset_view(f);
	else if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS && f->retina_mode == false)
		ft_window_size_set(f, 1);
	else if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS && f->retina_mode == false)
		ft_window_size_set(f, 2);
	else if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS && f->retina_mode == false)
		ft_window_size_set(f, 3);
	else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS && f->retina_mode == false)
		iteration_mod(f, 10);
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS && f->retina_mode == false)
		iteration_mod(f, -10);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && f->retina_mode == false)
		ft_set_switch(f);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		ft_color_switch(f);
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		palette_switch(f);
	else if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS && f->retina_mode == false)
		ft_lock_j_switch(f);
	else if (keydata.key == MLX_KEY_0 && keydata.action == MLX_PRESS)
		ft_retina_switch(f);
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
