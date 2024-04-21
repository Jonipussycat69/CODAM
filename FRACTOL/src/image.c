#include "../lib/fractol.h"

void	ft_draw_mandel(t_fractal *f)
{
	t_complex	c;
	t_complex	z;
	
	f->draw = false;
	f->y = 0;
	z.x = 0.0;
	z.y = 0.0;
	while (f->y < f->mlx->height)
	{
		f->x = 0;
		while (f->x < f->mlx->width)
		{
			c.x = ft_scale_x(f, f->x);
			c.y = ft_scale_y(f, f->y);
			ft_fract_math(f, c, z);
			f->x++;
		}
		f->y++;
	}
}

void	ft_draw_julia(t_fractal *f)
{
	t_complex	c;
	t_complex	z;
	
	f->draw = false;
	f->y = 0;
	c.x = f->julia_x;
	c.y = f->julia_y;
	while (f->y < f->mlx->height)
	{
		f->x = 0;
		while (f->x < f->mlx->width)
		{
			z.x = ft_scale_x(f, f->x);
			z.y = ft_scale_y(f, f->y);
			ft_fract_math(f, c, z);
			f->x++;
		}
		f->y++;
	}
}

// divine
void	ft_draw_mandel_div(t_fractal *f, t_complex z)
{
	t_complex	c;
	const double	max_x = (X_MAX + f->offset_x) * f->zoom;
	const double	min_x = (X_MIN + f->offset_x) * f->zoom;
	const double	max_y = (Y_MAX + f->offset_y) * f->zoom;
	const double	min_y = (Y_MIN + f->offset_y) * f->zoom;

	f->draw = false;
	f->y = 0;
	while (f->y < M_HEIGHT)
	{
		f->x = 0;
		while (f->x < M_WIDTH)
		{
			c.x = (max_x - min_x) * f->x / M_WIDTH + min_x;
			c.y = (max_y - min_y) * f->y / M_HEIGHT + min_y;
			ft_fract_math(f, c, z);
			f->x++;
		}
		f->y++;
	}
}

// divine
void	ft_draw_julia_div(t_fractal *f)
{
	t_complex	c;
	t_complex	z;
	const double	max_y = Y_MAX_J * f->rat_j;
	const double	min_y = Y_MIN_J * f->rat_j;

	f->draw_j = false;
	f->y = 0;
	c.x = f->julia_x;
	c.y = f->julia_y;
	while (f->y < J_HEIGHT)
	{
		f->x = 0;
		while (f->x < J_WIDTH)
		{
			z.x = (X_MAX_J - X_MIN_J) * f->x / J_WIDTH + X_MIN_J;
			z.y = (max_y - min_y) * f->y / J_HEIGHT + min_y;
			ft_fract_math_jul(f, c, z);
			f->x++;
		}
		f->y++;
	}
}

void	ft_image_resize(int32_t width, int32_t height, void* param)
{
	t_fractal	*f;

	f = param;
	printf("WIDTH: %d | HEIGHT: %d\n", width, height);// TEST
	mlx_resize_image(f->img, width, height);
	f->ratio = (double)f->mlx->height / (double)f->mlx->width;
	f->draw = true;// ?
}
