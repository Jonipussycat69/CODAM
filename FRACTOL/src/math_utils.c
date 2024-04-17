#include "../lib/fractol.h"

double	ft_scale(fra_t *f, double val, short axis)
{
	if (axis == y_ax)
		return ((f->scale_max_y - f->scale_min_y) * val / f->mlx->height \
				+ f->scale_min_y);
	else
		return ((f->scale_max_x - f->scale_min_x) * val / f->mlx->width \
				+ f->scale_min_x);
}
