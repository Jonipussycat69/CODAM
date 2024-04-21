#include "../lib/fractol.h"

void	ft_cursor_to_julia(void *param)
{
	t_fractal	*f;
	int32_t	x;
	int32_t	y;

	f = param;
	x = 0;
	y = 0;
	mlx_get_mouse_pos(f->mlx, &x, &y);
	if (x < 0 || y < 0 || x > M_WIDTH || y > M_HEIGHT)
		return ;
	f->julia_x = ft_scale_x(f, x);
	f->julia_y = ft_scale_y(f, y);
	printf("j_c = %f, %f\n", f->julia_x, f->julia_y);// TEST
	f->draw_j = true;
}
